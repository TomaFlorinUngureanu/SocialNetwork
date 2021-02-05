// include project classes
#include "Friendship.h"
#include "exception/SocialNetworkException.h"

// include mocks
#include "MockSocialNetworkUser.h"

using ::testing::StrictMock;
using ::testing::Return;

class FriendshipTest: public testing::Test
{
public:
    StrictMock<MockSocialNetworkUser> snuMock;
};

/**
 * @test CONSTRUCTOR_TC1
 * Construct a friendship object with nullptr as vertices
 */
TEST_F(FriendshipTest, CONSTRUCTOR_TC1)
{
    try
    {
        // variable declarations and initializations
        Friendship friendship{nullptr, nullptr};
    }
    catch (const VertexNullException& exception)
    {
        EXPECT_STREQ(exception.what(), "Vertex is null!");
    }
}

/**
 * @test CONSTRUCTOR_TC2
 * Construct a friendship object with vertices
 */
TEST_F(FriendshipTest, CONSTRUCTOR_TC2)
{
    // variable declarations and initializations
    std::string username{"Username"};
    std::string username1{"Username1"};

    // function under test
    Friendship friendship{new SocialNetworkUser(username), new SocialNetworkUser(username1)};

    // expectations
    EXPECT_CALL(snuMock, getLabel()).Times(2).WillOnce(Return(username)).WillOnce(Return(username1));

    // postconditions
    EXPECT_EQ(friendship.getVertex1()->getLabel(), username);
    EXPECT_EQ(friendship.getVertex2()->getLabel(), username1);
}

/**
 * @test SET_VERTEX_TC1
 * Set a vertex which is nullptr
 */
TEST_F(FriendshipTest, SET_VERTEX_TC1)
{
    try
    {
        // variable declarations and initializations
        Friendship friendship{};

        // function under test
        friendship.setVertex(nullptr, false);
    }
    catch (const VertexNullException& exception)
    {
        EXPECT_STREQ(exception.what(), "Vertex is null!");
    }
}

/**
 * @test SET_VERTEX_TC2
 * Set one of the 2 vertices with generic username
 */
TEST_F(FriendshipTest, SET_VERTEX_TC2)
{
    // variable declarations and initializations
    Friendship friendship{};
    std::string username{"User"};

    // expectations
    EXPECT_CALL(snuMock, getLabel()).Times(2).WillRepeatedly(Return(username));

    // function under test
    friendship.setVertex(new SocialNetworkUser(username), false);

    // postconditions
    EXPECT_EQ(friendship.getVertex1()->getLabel(), username);
}


