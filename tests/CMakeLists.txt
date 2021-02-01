cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 20)
project(SHORELINE_TESTS)

add_subdirectory(lib/googletest)

enable_testing()
include_directories(${gtest_SOURCE_DIR}/include
                    ${gtest_SOURCE_DIR}
                    {gmock_SOURCE_DIR}/include
                    ${gmock_SOURCE_DIR}
                    mocks/include
                    ../include
                    ../src
)

add_executable( EdgeTests
        ../src/abstraction/Vertex.cpp
        unit-tests/test_Friendship.cpp
)

add_executable( VertexTests
        unit-tests/test_SocialNetworkUser.cpp
)

add_executable( UndirectedGraphTests
                unit-tests/
        unit-tests/test_SocialNetwork.cpp
                mocks/stubs/MockUndirectedGraph.cpp
                mocks/include/MockUndirectedGraph.h)

target_link_libraries(EdgeTests gtest gmock gtest_main gmock_main)
target_link_libraries(VertexTests gtest gmock gtest_main gmock_main)
target_link_libraries(UndirectedGraphTests gtest gmock gtest_main gmock_main)

add_test(tests EdgeTests VertexTests UndirectedGraphTests)