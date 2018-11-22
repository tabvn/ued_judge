#include "src/server.h"
#include <thread>
#include <iostream>
#include <functional>

Ued::Server server;
const int PORT = 3000;

int main(int argc, const char **argv) {

    // Server
    std::thread tServer([]() {
        
        server.config.origin = "/usr/src/server/public"; // path from docker container
        server.logs = LLL_USER;
        server.start(PORT);

    });

    tServer.join();

    return 0;
}