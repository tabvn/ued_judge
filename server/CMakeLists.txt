cmake_minimum_required(VERSION 3.5)
project(server)
set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")
include_directories(src)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_executable(server main.cpp src/server.h src/subscribe.h)
target_link_libraries(server websockets cpp_redis tacopie)