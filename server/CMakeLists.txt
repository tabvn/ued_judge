cmake_minimum_required(VERSION 3.5)
project(server)
set(CMAKE_CXX_STANDARD 14)
include_directories(src)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_executable(server main.cpp src/server.h)
target_link_libraries(server websockets)