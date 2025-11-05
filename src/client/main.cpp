#include "ChatClient.hpp"
#include <iostream>

int main()
{
    client::ChatClient chatClient("127.0.0.1", 8080);
    chatClient.run();
    return 0;
}
