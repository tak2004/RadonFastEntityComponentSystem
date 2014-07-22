#ifndef RFECS_ENTITY_HPP
#define RFECS_ENTITY_HPP
#if _MSC_VER > 1000
#pragma once
#endif

#include <RadonFramework/Radon.hpp>

namespace RadonFastEntityComponentSystem {

typedef RF_Type::UInt64 EntityID;

}

#ifndef RFECS_SHORTHAND_NAMESPACE_RFECS
#define RFECS_SHORTHAND_NAMESPACE_RFECS
namespace RFECS = RadonFastEntityComponentSystem;
#endif

#endif // RFECS_ENTITY_HPP