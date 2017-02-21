# Define a project if this file wasn't included.
if(NOT CMAKE_PROJECT_NAME OR "${CMAKE_PROJECT_NAME}" MATCHES "^ArgonA$")
    cmake_minimum_required(VERSION 2.8.11)
    project(RadonFastEntityComponentSystem)
    set(RADONFRAMEWORK_USE_OPENGL OFF CACHE BOOL "" FORCE)
    set(RADONFRAMEWORK_USE_FORMS OFF CACHE BOOL "" FORCE)
    
    # put the libraries to the dist directory
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/dist)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/dist)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/dist)    
endif()

include("Integrate.cmake")

rcf_addlocation(RADONFRAMEWORK "git" "https://github.com/tak2004/RadonFramework.git")
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