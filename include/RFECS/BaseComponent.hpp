#ifndef RFECS_BASECOMPONENT_HPP
#define RFECS_BASECOMPONENT_HPP
#if _MSC_VER > 1000
#pragma once
#endif

#include <RFECS/Entity.hpp>
#include <RadonFramework/Radon.hpp>

namespace RadonFastEntityComponentSystem {

typedef RF_Type::UInt32 ComponentID;

class SharedAttributePool;

template<ComponentID ID>
struct BaseComponent
{
    void Setup(EntityID Entity, RF_Mem::AutoPointerArray<RF_Type::UInt8>& Data,
               SharedAttributePool& SharedAttributes)
    {
        m_Entity = Entity;
    }

    void Process(){}
private:
    EntityID m_Entity;
};

}

#ifndef RFECS_SHORTHAND_NAMESPACE_RFECS
#define RFECS_SHORTHAND_NAMESPACE_RFECS
namespace RFECS = RadonFastEntityComponentSystem;
#endif

#endif // RFECS_BASECOMPONENT_HPP