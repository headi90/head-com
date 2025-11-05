add_executable(chat_server
    main.cpp
    ChatServer.cpp
)

target_include_directories(chat_server PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

# target_link_libraries(chat_server pthread)
