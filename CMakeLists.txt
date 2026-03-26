cmake_minimum_required(VERSION 3.20)
project(dijkstra C)

set(CMAKE_C_STANDARD 99)

add_executable(tests
        src/binary_heap.c
        src/dijkstra.c
        test/vendor/unity.c
        test/test_binary_heap.c
        test/test_dijkstra.c
)

target_include_directories(tests PRIVATE src)
target_compile_definitions(tests PRIVATE UNITY_SUPPORT_64)
target_compile_options(tests PRIVATE
        -Wall -Wextra -pedantic -Werror
        -Wmissing-declarations -Wstrict-prototypes
)
target_link_libraries(tests m)
