#include "src/server.h"
#include <iostream>

Ued::Server server;

int main(int argc, const char **argv) {

    server.config.origin = "/usr/src/server/public"; // path from docker container
    server.start(3000);

    return 0;
}