cmake_minimum_required(VERSION 3.17)
project(SOCIAL_NETWORK)

set(CMAKE_CXX_STANDARD 20)
include_directories(include src)
set(SOURCES src/abstraction/Edge.cpp src/abstraction/Vertex.cpp main.cpp src/SocialNetwork.cpp include/SocialNetwork.h src/SocialNetworkUser.cpp include/SocialNetworkUser.h src/Friendship.cpp include/Friendship.h)
add_executable(SOCIAL_NETWORK ${SOURCES})