
cmake_minimum_required(VERSION 2.8)

project(libui-cpp)

option(LIBUI_BUILD_TEST "Build the test project" ON)

macro(use_libui TARGET)
    target_link_libraries(${TARGET} libui)
    if(APPLE)
        target_link_libraries(${TARGET} "-framework Cocoa")
    endif()
endmacro()

add_subdirectory(ext/libui)
add_subdirectory(src/libui-cpp)
add_subdirectory(src/test)
