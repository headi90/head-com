#pragma once
#include <string>
#include <vector>
#include <mutex>

namespace server
{
    class ChatServer
    {
    public:
        explicit ChatServer(int port);
        void run();

    private:
        int port;
        int serverSocket;
        std::vector<int> clients;
        std::mutex clientsMutex;

        void handleClient(int clientSocket);
        void broadcast(const std::string &msg, int sender);
    };

} // namespace server