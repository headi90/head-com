add_executable(unit_tests
    ChatServerTest.cpp
)

target_include_directories(unit_tests PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src/server
)

target_link_libraries(unit_tests
    gtest_main
    pthread
)

include(GoogleTest)
gtest_discover_tests(unit_tests)
