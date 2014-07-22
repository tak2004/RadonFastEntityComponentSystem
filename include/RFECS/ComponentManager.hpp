#ifndef RFECS_COMPONENTMANAGER_HPP
#define RFECS_COMPONENTMANAGER_HPP
#if _MSC_VER > 1000
#pragma once
#endif

#include <RFECS/BaseComponentManager.hpp>

namespace RadonFastEntityComponentSystem {

class Allocator;

template<ComponentID ID>
class ComponentManager: public BaseComponentManager
{
public:
    ComponentManager();

    virtual void Setup(Allocator& MemoryAllocator);

    virtual void Process(SharedAttributePool& AttributePool);

    virtual void AttachComponentOnEntity(ComponentID Component,
        RF_Mem::AutoPointerArray<RF_Type::UInt8>& ComponentData,
        EntityID Entity);
protected:
    RF_Collect::Array<BaseComponent<ID> > m_Components;
};

}

#ifndef RFECS_SHORTHAND_NAMESPACE_RFECS
#define RFECS_SHORTHAND_NAMESPACE_RFECS
namespace RFECS = RadonFastEntityComponentSystem;
#endif

#endif // RFECS_COMPONENTMANAGER_HPP