
# project(libui-test)

set(TEST_SOURCES
    main.cpp
)

add_executable(libui-test ${TEST_SOURCES})

use_libui(libui-test)
