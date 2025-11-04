#include <iostream>
#include <thread>
#include <unistd.h>
#include <arpa/inet.h>

namespace
{
void receiveMessages(int sock) {
    char buffer[1024];
    while(true) {
        ssize_t bytes = recv(sock, buffer, sizeof(buffer) - 1, 0);
        if(bytes <= 0) break;
        buffer[bytes] = '\0';
        std::cout << buffer;
    }
}
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

    connect(sock, (sockaddr*)&serverAddr, sizeof(serverAddr));

    std::thread(receiveMessages, sock).detach();

    std::string msg;
    while(true) {
        std::getline(std::cin, msg);
        std::cout << "You: " << msg << "\n";
        send(sock, msg.c_str(), msg.size(), 0);
    }

    close(sock);
}
