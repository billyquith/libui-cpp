
set(LIBUICPP_SOURCES
    ui.hpp
    ui.cpp
)

add_definitions(-std=c++0x)

add_library(libui-cpp ${LIBUICPP_SOURCES})

use_libui(libui-cpp)
