#ifndef RFECS_COMPONENTPROCESSOR_HPP
#define RFECS_COMPONENTPROCESSOR_HPP
#if _MSC_VER > 1000
#pragma once
#endif

#include <RFECS/BaseComponentProcessor.hpp>

namespace RadonFastEntityComponentSystem {

class Allocator;

// Generic component manager used for simple components.
template<ComponentID ID>
class ComponentProcessor: public BaseComponentProcessor
{
public:
    ComponentProcessor();

    virtual void Setup(Allocator& MemoryAllocator, SharedAttributePool& AttributePool);

    virtual void Process();

    virtual RF_Type::Bool AttachComponentOnEntity(ComponentID Component,
        RF_Mem::AutoPointerArray<RF_Type::UInt8>& ComponentData,
        EntityID Entity, SharedAttributePool& SharedAttributes);
protected:
    RF_Collect::Array<BaseComponent<ID> > m_Components;
};

template<ComponentID ID>
RF_Type::Bool ComponentProcessor<ID>::AttachComponentOnEntity(ComponentID Component, 
    RF_Mem::AutoPointerArray<RF_Type::UInt8>& ComponentData, EntityID Entity, 
    SharedAttributePool& SharedAttributes)
{
    RF_Type::Bool result = false;
    if(Component == ID)
    {
        m_Components.Resize(m_Components.Count() + 1);
        m_Components(m_Components.Count() - 1).Setup(Entity, ComponentData, SharedAttributes);
        result = true;
    }
    return result;
}

template<ComponentID ID>
void ComponentProcessor<ID>::Process()
{
    RF_Algo::ForEach(m_Components, [](RF_Collect::Array<BaseComponent<ID> >::EnumeratorType& Enum) {
        Enum->Process(); });
}

template<ComponentID ID>
void ComponentProcessor<ID>::Setup(Allocator& MemoryAllocator, 
    SharedAttributePool& AttributePool)
{
    m_Allocator = &MemoryAllocator;
    m_AttributePool = &AttributePool;
}

template<ComponentID ID>
ComponentProcessor<ID>::ComponentProcessor()
:BaseComponentProcessor()
{
    m_ComponentIdentifiers.Resize(1);
    m_ComponentIdentifiers(0) = static_cast<RF_Type::UInt32>(ID);
}

}

#ifndef RFECS_SHORTHAND_NAMESPACE_RFECS
#define RFECS_SHORTHAND_NAMESPACE_RFECS
namespace RFECS = RadonFastEntityComponentSystem;
#endif

#endif // RFECS_COMPONENTPROCESSOR_HPP