// include project classes
#include "SocialNetworkUser.h"
#include "Friendship.h"

// include mocks
#include "MockFriendship.h"

using ::testing::StrictMock;

class FriendshipTest: public testing::Test
{
public:
    StrictMock<MockFriendship> friendshipMock;
};

TEST_F(FriendshipTest, TC_1)
{
    Friendship friendship{};
    Vertex *vertex = new SocialNetworkUser("");

    EXPECT_CALL(friendshipMock, setVertex(vertex, false));
    friendship.setVertex(vertex, false);
}
