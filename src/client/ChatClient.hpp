#pragma once
#include <string>

namespace client
{
    class ChatClient
    {
    public:
        ChatClient(const std::string serverIp, int port);
        void run();

    private:
        std::string serverIp;
        int port;
        int sock;

        void receiveMessages();
    };
} // namespace client