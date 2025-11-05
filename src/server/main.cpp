#include <iostream>
#include "ChatServer.hpp"

int main()
{
    server::ChatServer chatServer(8080);
    chatServer.run();
    return 0;
}
