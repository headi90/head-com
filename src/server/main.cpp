#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>
#include <algorithm>

std::vector<int> clients;
std::mutex clientsMutex;

namespace
{
// void broadcast(const std::string& msg, int sender) {
//     std::lock_guard<std::mutex> lock(clientsMutex);
//     for(int client : clients) {
//         if(client != sender) {
//             send(client, msg.c_str(), msg.size(), 0);
//         }
//     }
// }

void handleClient(int clientSocket) {
    char buffer[1024];
    while(true) {
        ssize_t bytes = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
        std::cout << "Received bytes: " << bytes << "\n";
        if(bytes <= 0) {
            std::cout << "Client disconnected\n";
            std::lock_guard<std::mutex> lock(clientsMutex);
            clients.erase(std::remove(clients.begin(), clients.end(), clientSocket), clients.end());
            close(clientSocket);
            break;
        }
        std::cout << "Bytes received: " << bytes << "\n";

        buffer[bytes] = '\0';
        std::string msg = buffer;
        // broadcast(msg, clientSocket);
        std::cout << "Msg: " << msg;
    }
}
}

int main() {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 10);

    std::cout << "Server running on port 8080...\n";

    while(true) {
        sockaddr_in clientAddr{};
        socklen_t clientSize = sizeof(clientAddr);
        int clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientSize);

        std::cout << "Client connected\n";
        {
            std::lock_guard<std::mutex> lock(clientsMutex);
            clients.push_back(clientSocket);
        }

        std::thread(handleClient, clientSocket).detach();
    }
}
