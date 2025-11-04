cmake_minimum_required(VERSION 3.16)
project(ChatApp LANGUAGES CXX)

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
        # -Wcast-align
        # -Wcast-qual
        # -Wconversion
        # -Wdouble-promotion
        # -Wformat=2
        # -Wformat-nonliteral
        # -Wformat-security
        # -Wformat-y2k
        # -Wimplicit-fallthrough
        # -Wmissing-declarations
        # -Wnull-dereference
        # -Wold-style-cast
        # -Woverloaded-virtual
        # -Wredundant-decls
        # -Wshadow
        # -Wsign-conversion
        # -Wstrict-overflow=5
        # -Wunused
    )
endif()

add_subdirectory(src/server)
add_subdirectory(src/client)
