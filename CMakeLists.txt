cmake_minimum_required(VERSION 2.8.11)
project(RadonFastEntityComponentSystem)

include("Integrate.cmake")

rcf_addlocation(RADONFRAMEWORK "git" "https://github.com/tak2004/RadonFramework.git")
set(RADONFRAMEWORK_BUILD_UNITTEST OFF CACHE BOOL "" FORCE)
set(RADONFRAMEWORK_BUILD_SYSTEMTEST OFF CACHE BOOL "" FORCE)
set(RADONFRAMEWORK_BUILD_RESOURCETEST OFF CACHE BOOL "" FORCE)
Integrate(RADONFRAMEWORK "Radon framework" "RADONFRAMEWORK_HOME")

AddSourceDirectoryRecursive(rfecssrclist "src" "Source")
AddHeaderDirectoryRecursive(rfecshdrlist "include/RFECS" "Includes")
set(RADON_FAST_ENTITY_COMPONENT_SYSTEM_FILES ${rfecssrclist} ${rfecshdrlist})
Generate(MODULE RADON_FAST_ENTITY_COMPONENT_SYSTEM RadonFastEntityComponentSystem "Framework")
AddPublicInclude(RADON_FAST_ENTITY_COMPONENT_SYSTEM ${RadonFastEntityComponentSystem_SOURCE_DIR}/include/)
AddDependency(RADON_FAST_ENTITY_COMPONENT_SYSTEM RadonFramework)
Finalize(RADON_FAST_ENTITY_COMPONENT_SYSTEM)