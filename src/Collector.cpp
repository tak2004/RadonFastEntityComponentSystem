#include <RFECS/Collector.hpp>
#include <RFECS/Allocator.hpp>
#include <RadonFramework/IO/Log.hpp>

using namespace RadonFastEntityComponentSystem;

void Collector::Process()
{
    /*RF_Algo::ForEach(m_ComponentManagers, 
        [](RF_Collect::Array<RF_Mem::AutoPointer<BaseComponentManager> >::EnumeratorType& Enum)
        {
            (*Enum)->Process();
        }
    );*/
    for(RF_Type::Size i = 0; i < m_ComponentManagers.Count(); ++i)
    {
        m_ComponentManagers(i)->Process();
    }
}

void Collector::Setup(Allocator& MemoryAllocator)
{
    m_Allocator = &MemoryAllocator;
    m_Attributes.Setup(MemoryAllocator);
}

void Collector::RegisterComponentManager(RF_Mem::AutoPointer<BaseComponentManager>& ComponentManager)
{
    // check if one of the components is already known
    for(RF_Type::Size i = 0; i < ComponentManager->ComponentTypes().Count(); ++i)
    {
        if(m_ComponentManagerLookup.ContainsKey(ComponentManager->ComponentTypes()(i)))
        {
            RF_IO::LogDebug("The component %d is already registered!\n", ComponentManager->ComponentTypes()(i));
            return;
        }
    }

    // register all new components
    for(RF_Type::Size i = 0; i < ComponentManager->ComponentTypes().Count(); ++i)
    {
        m_ComponentManagerLookup[ComponentManager->ComponentTypes()(i)] = ComponentManager.Get();
    }    

    ComponentManager->Setup(*m_Allocator);
    m_ComponentManagers.Resize(m_ComponentManagers.Count()+1);
    m_ComponentManagers(m_ComponentManagers.Count()-1)=ComponentManager;
}

void Collector::SetSharedAttributeOfEntity(SharedAttributeID AttributeIdentifier, 
    RF_Mem::AutoPointerArray<RF_Type::UInt8>& AttributeData, EntityID EntityIdentifier)
{
    void* data = m_Attributes.AttachToEntity(AttributeIdentifier, AttributeData.Size(), EntityIdentifier);
    RF_SysMem::Copy(data, AttributeData.Get(), AttributeData.Size());
}

void Collector::AttachComponentOnEntity(ComponentID ComponentIdentifier, 
    RF_Mem::AutoPointerArray<RF_Type::UInt8>& ComponentData, EntityID EntityIdentifier)
{
    m_ComponentManagerLookup[ComponentIdentifier]->AttachComponentOnEntity(ComponentIdentifier,
        ComponentData, EntityIdentifier, m_Attributes);
}

Collector::Collector()
:m_Allocator(0)
{

}

