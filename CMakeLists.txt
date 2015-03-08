cmake_minimum_required(VERSION 2.8.11)
project(RadonFastEntityComponentSystem)

include("Integrate.cmake")

AddSourceDirectoryRecursive(rfecssrclist "src" "Source")
AddHeaderDirectoryRecursive(rfecshdrlist "include/RFECS" "Includes")
set(RADON_FAST_ENTITY_COMPONENT_SYSTEM_FILES ${rfecssrclist} ${rfecshdrlist})
Generate(MODULE RADON_FAST_ENTITY_COMPONENT_SYSTEM RadonFastEntityComponentSystem "Framework")
AddPublicInclude(RADON_FAST_ENTITY_COMPONENT_SYSTEM ${RadonFastEntityComponentSystem_SOURCE_DIR}/include/)
Finalize(RADON_FAST_ENTITY_COMPONENT_SYSTEM)