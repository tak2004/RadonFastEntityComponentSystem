#ifndef RFECS_SHAREDATTRIBUTEPOOL_HPP
#define RFECS_SHAREDATTRIBUTEPOOL_HPP
#if _MSC_VER > 1000
#pragma once
#endif

#include <RadonFramework/Radon.hpp>
#include <RFECS/Entity.hpp>

namespace RadonFastEntityComponentSystem {

typedef RF_Type::UInt32 SharedAttributeID;
class Allocator;

class SharedAttributePool
{
public:
    void Setup(Allocator& MemoryAllocator);

    RF_Type::UInt8* AttachToEntity(SharedAttributeID AttributeIdentifier, 
        RF_Type::Size AttributeDataSize, EntityID EntityIdentifier);
private:
    struct Entity
    {
        RF_Collect::HashMap<SharedAttributeID, RF_Type::UInt8*> m_AttributeLookup;
        RF_Collect::List<RF_Mem::AutoPointerArray<RF_Type::UInt8> > m_Attributes;
    };

    RF_Collect::HashMap<EntityID, Entity*> m_EntityLookup;
    RF_Collect::List<RF_Mem::AutoPointer<Entity> > m_Entities;
    Allocator* m_Allocator;
};

}

#ifndef RFECS_SHORTHAND_NAMESPACE_RFECS
#define RFECS_SHORTHAND_NAMESPACE_RFECS
namespace RFECS = RadonFastEntityComponentSystem;
#endif

#endif // RFECS_SHAREDATTRIBUTEPOOL_HPP