#ifndef RFECS_COLLECTOR_HPP
#define RFECS_COLLECTOR_HPP
#if _MSC_VER > 1000
#pragma once
#endif

#include <RFECS/BaseComponentProcessor.hpp>
#include <RFECS/SharedAttributePool.hpp>

#include <RadonFramework/Radon.hpp>

namespace RadonFastEntityComponentSystem {

class Allocator;

class Collector
{
public:
    Collector();

    void Setup(Allocator& MemoryAllocator);

    void Process();

    void RegisterComponentManager(RF_Mem::AutoPointer<BaseComponentProcessor>& ComponentManager);

    void SetSharedAttributeOfEntity(SharedAttributeID AttributeIdentifier, 
        RF_Mem::AutoPointerArray<RF_Type::UInt8>& AttributeData, 
        EntityID EntityIdentifier);

    void AttachComponentOnEntity(ComponentID ComponentIdentifier, 
        RF_Mem::AutoPointerArray<RF_Type::UInt8>& ComponentData, 
        EntityID EntityIdentifier);
private:
    RF_Collect::Array<RF_Mem::AutoPointer<BaseComponentProcessor> > m_ComponentManagers;
    SharedAttributePool m_Attributes;
    RF_Collect::HashMap<ComponentID, BaseComponentProcessor*> m_ComponentManagerLookup;
    Allocator* m_Allocator;
};

}

#ifndef RFECS_SHORTHAND_NAMESPACE_RFECS
#define RFECS_SHORTHAND_NAMESPACE_RFECS
namespace RFECS = RadonFastEntityComponentSystem;
#endif

#endif // RFECS_COLLECTOR_HPP