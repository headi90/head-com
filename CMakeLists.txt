cmake_minimum_required(VERSION 3.16)
project(ChatApp LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

# GoogleTest prefers to use its own settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(
        -Wall
        -Wextra
        -Werror
        -Wpedantic
        -Wcast-align
        -Wcast-qual
        -Wconversion
        -Wdouble-promotion
        -Wformat=2
        -Wformat-nonliteral
        -Wformat-security
        -Wformat-y2k
        -Wimplicit-fallthrough
        -Wmissing-declarations
        -Wnull-dereference
        -Wold-style-cast
        -Woverloaded-virtual
        -Wredundant-decls
        -Wsign-conversion
        -Wstrict-overflow=5
        -Wunused
    )
endif()

add_subdirectory(src/server)
add_subdirectory(src/client)

enable_testing()
add_subdirectory(tests)
