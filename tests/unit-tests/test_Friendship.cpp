// include project classes
#include "Friendship.h"

// include mocks
#include "MockSocialNetworkUser.h"

using ::testing::StrictMock;
using ::testing::Return;

class FriendshipTest: public testing::Test
{
public:
    StrictMock<MockSocialNetworkUser> snuMock;
};

TEST_F(FriendshipTest, TC_1)
{
    Friendship friendship{};

    std::string username{"User"};
    EXPECT_CALL(snuMock, getUsername()).Times(2).WillRepeatedly(Return(username));
    friendship.setVertex(new SocialNetworkUser(username), false);
    EXPECT_EQ(friendship.getVertex1()->getUsername(), username);
}


