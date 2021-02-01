cmake_minimum_required(VERSION 3.17)
project(TESTS)

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

set(PROJECT_SOURCES ../src/abstraction/Vertex.cpp
                    ../src/abstraction/Edge.cpp
                    ../src/SocialNetworkUser.cpp
                    ../src/Friendship.cpp
                    ../src/SocialNetwork.cpp)

add_executable( FriendshipTests
                ${PROJECT_SOURCES}
        unit-tests/test_Friendship.cpp
)

add_executable( SocialNetworkUserTests
                ${PROJECT_SOURCES}
        unit-tests/test_SocialNetworkUser.cpp
)

add_executable( SocialNetworkTests
                ${PROJECT_SOURCES}
        unit-tests/test_SocialNetwork.cpp
)

target_link_libraries(FriendshipTests gtest gmock gtest_main gmock_main)
target_link_libraries(SocialNetworkUserTests gtest gmock gtest_main gmock_main)
target_link_libraries(SocialNetworkTests gtest gmock gtest_main gmock_main)

add_test(TESTS FriendshipTests SocialNetworkUserTests SocialNetworkTests)