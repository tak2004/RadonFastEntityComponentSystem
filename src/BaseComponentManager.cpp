#include <RFECS/BaseComponentManager.hpp>

using namespace RadonFastEntityComponentSystem;

const RF_Collect::Array<ComponentID>& BaseComponentManager::ComponentTypes() const
{
    return m_ComponentIdentifiers;
}
