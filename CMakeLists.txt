cmake_minimum_required(VERSION 3.17)
project(SOCIAL_NETWORK)

set(CMAKE_CXX_STANDARD 20)
include_directories(include src)
set(SOURCES
        src/exception/SocialNetworkException.cpp
        src/abstraction/Edge.cpp
        src/abstraction/Vertex.cpp
        src/abstraction/UndirectedGraph.cpp
        src/SocialNetwork.cpp
        src/SocialNetworkUser.cpp
        src/Friendship.cpp
        main.cpp
)
add_executable(SOCIAL_NETWORK ${SOURCES})