# Get the GCC preinstalled image from Docker Hub
FROM ubuntu:16.04

RUN apt update && apt install -y cmake git-core g++

#libwebsockets
RUN git clone "https://github.com/warmcat/libwebsockets.git" /usr/src/server/libwebsockets && cd /usr/src/server/libwebsockets && cmake -DLWS_WITH_SSL=0 . && make && make install
# Redis client
RUN cd /usr/src/server && git clone "https://github.com/cylix/cpp_redis.git" /usr/src/server/redis && cd /usr/src/server/redis && git submodule init && git submodule update && cmake . -DCMAKE_BUILD_TYPE=Release && make && make install

# Copy files to docker container
RUN mkdir -p /usr/src/server/build
WORKDIR /usr/src/server
COPY . /usr/src/server
RUN cd build/ && cmake ../ && make

CMD ["./build/server"]

EXPOSE 3000