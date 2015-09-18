#include "RFECS/SharedAttributePool.hpp"
#include "RFECS/Allocator.hpp"

using namespace RadonFastEntityComponentSystem;

void SharedAttributePool::Setup(Allocator& MemoryAllocator)
{
    m_Allocator = &MemoryAllocator;
}

RF_Type::UInt8* SharedAttributePool::AttachToEntity(SharedAttributeID AttributeIdentifier,
    RF_Type::Size AttributeDataSize, EntityID EntityIdentifier)
{
    // if entity doesn't exist then create it
    if(!m_EntityLookup.ContainsKey(EntityIdentifier))
    {
        RF_Mem::AutoPointer<Entity> newEntity(new Entity);
        m_EntityLookup[EntityIdentifier] = newEntity.Get();
        m_Entities.AddLast(newEntity);
    }

    // if attribute doesn't exist then create it
    Entity* entity = m_EntityLookup[EntityIdentifier];
    if(!entity->m_AttributeLookup.ContainsKey(AttributeIdentifier))
    {
        RF_Mem::AutoPointerArray<RF_Type::UInt8> newAttribute(AttributeDataSize);
        entity->m_AttributeLookup[AttributeIdentifier] = newAttribute.Get();
        entity->m_Attributes.AddLast(newAttribute);

    }

    return entity->m_AttributeLookup[AttributeIdentifier];
}
