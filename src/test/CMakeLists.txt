
# project(libui-test)

set(TEST_SOURCES
    main.cpp
)

add_definitions(-std=c++0x)

add_executable(libui-test ${TEST_SOURCES})

use_libui(libui-test)
target_link_libraries(libui-test libui-cpp)
