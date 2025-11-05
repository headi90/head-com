add_executable(chat_client
    main.cpp
    ChatClient.cpp
)

target_include_directories(chat_client PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

# target_link_libraries(chat_client pthread)
