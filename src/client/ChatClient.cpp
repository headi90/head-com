#include "ChatClient.hpp"
#include <iostream>
#include <thread>
#include <unistd.h>
#include <arpa/inet.h>

namespace client
{
    ChatClient::ChatClient(const std::string serverIp, int port)
        : serverIp(serverIp), port(port), sock(-1) {}

    void ChatClient::receiveMessages()
    {
        char buffer[1024];
        while (true)
        {
            const auto bytes = recv(sock, buffer, sizeof(buffer) - 1, 0);
            std::cout << "Received " << bytes << " bytes\n";
            if (bytes <= 0)
            {
                break;
            }
            buffer[bytes] = '\0';
            std::cout << buffer << '\n'
                      << std::flush;
        }
    }

    void ChatClient::run()
    {
        sock = socket(AF_INET, SOCK_STREAM, 0);

        sockaddr_in serverAddr{};
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(port);
        inet_pton(AF_INET, serverIp.c_str(), &serverAddr.sin_addr);

        connect(sock, (sockaddr *)&serverAddr, sizeof(serverAddr));

        std::thread(&ChatClient::receiveMessages, this).detach();

        std::string msg;
        while (true)
        {
            std::getline(std::cin, msg);
            std::cout << "You: " << msg << "\n";
            send(sock, msg.c_str(), msg.size(), 0);
        }

        close(sock);
    }
} // namespace client