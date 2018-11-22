#include "src/server.h"
#include "src/subscribe.h"
#include <thread>
#include <iostream>
#include <functional>


Ued::Server server;
Ued::Subscribe sub;

const int PORT = 3000;

int main(int argc, const char **argv) {

    // Server
    std::thread tServer([]() {
        server.config.origin = "/usr/src/server/public"; // path from docker container
        server.logs = LLL_USER;
        server.start(PORT);


    });

    std::thread tSub([]() {

        sleep(3);
        sub.connect();
        sub.subscribe();

    });


    tServer.join();
    tSub.join();


    return 0;
}