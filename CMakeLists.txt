cmake_minimum_required(VERSION 3.17)
project(UnidrectedGraph)

set(CMAKE_CXX_STANDARD 20)
include_directories(include src)
add_executable(UnidrectedGraph src/Edge.cpp src/UndirectedGraph.cpp src/Vertex.cpp main.cpp)