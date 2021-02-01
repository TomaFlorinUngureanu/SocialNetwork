// include project classes
#include "Friendship.h"

// include mocks
#include "MockFriendship.h"

// include GTest & Gmock
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::StrictMock;

class FriendshipTest: public testing::Test
{
    StrictMock<MockFriendship> friendshipMock;
};

TEST_F(FriendshipTest, TC_1)
{
    Friendship friendship{};
}
