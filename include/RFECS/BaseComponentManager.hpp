#ifndef RFECS_BASECOMPONENTMANAGER_HPP
#define RFECS_BASECOMPONENTMANAGER_HPP
#if _MSC_VER > 1000
#pragma once
#endif

#include <RFECS/BaseComponent.hpp>
#include <RadonFramework/Radon.hpp>

namespace RadonFastEntityComponentSystem {

class Allocator;

class BaseComponentManager
{
public:
    virtual void Setup(Allocator& MemoryAllocator)=0;
    
    virtual void Process()=0;

    virtual void AttachComponentOnEntity(ComponentID Component,
        RF_Mem::AutoPointerArray<RF_Type::UInt8>& ComponentData,
        EntityID Entity, SharedAttributePool& SharedAttributes) = 0;

    const RF_Collect::Array<ComponentID>& ComponentTypes()const;
protected:
    RF_Collect::Array<ComponentID> m_ComponentIdentifiers;
    Allocator* m_Allocator;
    
};

}

#ifndef RFECS_SHORTHAND_NAMESPACE_RFECS
#define RFECS_SHORTHAND_NAMESPACE_RFECS
namespace RFECS = RadonFastEntityComponentSystem;
#endif

#endif // RFECS_BASECOMPONENTMANAGER_HPP