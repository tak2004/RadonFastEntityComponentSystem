#include <RFECS/BaseComponentProcessor.hpp>

using namespace RadonFastEntityComponentSystem;

const RF_Collect::Array<ComponentID>& BaseComponentProcessor::ComponentTypes() const
{
    return m_ComponentIdentifiers;
}
