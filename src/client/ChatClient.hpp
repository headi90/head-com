#pragma once
#include <string>
#include <cstdint>

namespace client
{
    class ChatClient
    {
    public:
        ChatClient(const std::string serverIp, uint16_t port);
        void run();

    private:
        std::string serverIp;
        uint16_t port;
        int sock;

        void receiveMessages();
    };
} // namespace client