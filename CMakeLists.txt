cmake_minimum_required(VERSION 3.13)
project(context-get)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")

include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)
ExternalProject_Add(tinyxml2_project
        URL https://github.com/leethomason/tinyxml2/archive/7.1.0.tar.gz
        URL_MD5 8a02c592702dcc7a061932425d8f3087
        CMAKE_ARGS -DBUILD_SHARED_LIBS:BOOL=OFF -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/tinyxml2_install
        )

add_library(libtinyxml2 STATIC IMPORTED)
set_property(TARGET libtinyxml2 PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/tinyxml2_install/lib/libtinyxml2.a)
add_dependencies(libtinyxml2 tinyxml2_project)

add_executable(context-get main.cpp)

target_include_directories(context-get PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/tinyxml2_install/include)
target_link_libraries(context-get libtinyxml2)