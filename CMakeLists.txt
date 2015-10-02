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
set(RFECS_FILES ${rfecssrclist} ${rfecshdrlist})
Generate(MODULE RFECS RadonFastEntityComponentSystem "Framework")
AddPublicInclude(RFECS ${RadonFastEntityComponentSystem_SOURCE_DIR}/include/)
AddDependency(RFECS RadonFramework)
Finalize(RFECS)

option(RFECS_BUILD_RESOURCETEST "Enable the resource test." OFF)
if(RFECS_BUILD_RESOURCETEST)
add_subdirectory("tests/ResourceTest/")
endif()