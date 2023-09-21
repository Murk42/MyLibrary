cmake_minimum_required (VERSION 3.23)

#Used to run vcpkg to check for new libraries
file(TIMESTAMP "${CMAKE_CURRENT_LIST_DIR}/vcpkg.json" vcpkg_json_timestamp)
if(VCPKG_JSON_TIMESTAMP_PREV STREQUAL vcpkg_json_timestamp)
    set(VCPKG_MANIFEST_INSTALL OFF CACHE STRING "" FORCE)
else()
    set(VCPKG_MANIFEST_INSTALL ON CACHE STRING "" FORCE)
endif()
include("C:/Program Files/Microsoft Visual Studio/2022/Community/VC/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(VCPKG_JSON_TIMESTAMP_PREV "${vcpkg_json_timestamp}" CACHE STRING "" FORCE)

project (MyLibrary)

#find vcpkg packages
find_package(SDL2 CONFIG REQUIRED)

add_subdirectory ("MyLibrary")