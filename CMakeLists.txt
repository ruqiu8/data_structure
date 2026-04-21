cmake_minimum_required(VERSION 3.10)

project(data_structure VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

if(CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID MATCHES "Clang")
    add_compile_options(-fsanitize=address -fno-omit-frame-pointer)
    add_link_options(-fsanitize=address)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# 查找源文件
set(SOURCES
    src/seqlist.c
    src/linklist.c
    src/char_seq_stack.c
    src/int_link_stack.c
    src/seq_queue.c
    src/link_queue.c
    src/infix.c
)

add_library(ds STATIC ${SOURCES})
target_include_directories(ds PRIVATE include)

set(TEST_SOURCES
    tests/seqlist_test.c
    tests/linklist_test.c
    tests/char_seq_stack_test.c
    tests/int_link_stack_test.c
    tests/seq_queue_test.c
    tests/link_queue_test.c
    tests/infix_test.c
)

enable_testing()

foreach(TEST_PATH ${TEST_SOURCES})

    get_filename_component(TEST_NAME ${TEST_PATH} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_PATH})
    target_link_libraries(${TEST_NAME} ds)

    target_include_directories(${TEST_NAME} PRIVATE include)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})

    message(STATUS "Created test: ${TEST_NAME}")
endforeach()