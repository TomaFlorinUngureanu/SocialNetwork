cmake_minimum_required(VERSION 3.17)
project(TESTS)

add_subdirectory(lib/googletest)

enable_testing()

include_directories(${gtest_SOURCE_DIR}/include
                    ${gtest_SOURCE_DIR}
                    ${gmock_SOURCE_DIR}/include
                    ${gmock_SOURCE_DIR}
                    mocks/include
                    ../include
                    ../src
)

add_executable( FriendshipTests
                ../src/exception/SocialNetworkException.cpp
                ../src/Friendship.cpp
                ../src/abstraction/Edge.cpp
                mocks/stubs/SocialNetworkUser_Stub.cpp
                mocks/stubs/Vertex_Stub.cpp
                unit-tests/test_Friendship.cpp
)

add_executable( SocialNetworkUserTests
                ../src/abstraction/Vertex.cpp
                mocks/stubs/SocialNetworkUser_Stub.cpp
                unit-tests/test_SocialNetworkUser.cpp
)

add_executable( SocialNetworkTests
                ../src/abstraction/UndirectedGraph.cpp
                ../src/SocialNetwork.cpp
                ../src/exception/SocialNetworkException.cpp
                ../src/abstraction/Edge.cpp
                ../src/abstraction/Vertex.cpp
                mocks/stubs/Friendship_Stub.cpp
                mocks/stubs/SocialNetworkUser_Stub.cpp
                unit-tests/test_SocialNetwork.cpp
)

target_link_libraries(FriendshipTests gtest gmock gtest_main gmock_main)
target_link_libraries(SocialNetworkUserTests gtest gmock gtest_main gmock_main)
target_link_libraries(SocialNetworkTests gtest gmock gtest_main gmock_main)

add_test(TESTS FriendshipTests)
add_test(TESTS SocialNetworkUserTests)
add_test(TESTS SocialNetworkTests)