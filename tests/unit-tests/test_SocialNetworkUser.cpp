// include project class headers
#include "SocialNetworkUser.h"

// include mocks
#include "MockSocialNetworkUser.h"

using ::testing::StrictMock;
using ::testing::Return;
using ::testing::SetArgReferee;
using ::testing::InSequence;

class TestSocialNetworkUser: public testing::Test
{
public:
    StrictMock<MockSocialNetworkUser> socialNetworkUserMock;
    SocialNetworkUser unnamedUser{};

    std::string username = "User";
    SocialNetworkUser namedUser{username};
};


TEST_F(TestSocialNetworkUser, GET_USERNAME_TC_1)
{
    InSequence sequence;
    EXPECT_CALL(socialNetworkUserMock, getUsername()).WillOnce(Return(std::string{}));
    EXPECT_EQ(std::string{}, unnamedUser.getUsername());
}

TEST_F(TestSocialNetworkUser, GET_USERNAME_TC_2)
{
    InSequence sequence;
    EXPECT_CALL(socialNetworkUserMock, getUsername()).WillOnce(Return(username));
    EXPECT_EQ(username, namedUser.getUsername());
}

TEST_F(TestSocialNetworkUser, GET_USERNAME_TC_3)
{
    Vertex* vertex = new SocialNetworkUser();

    InSequence sequence;
    EXPECT_CALL(socialNetworkUserMock, getUsername()).WillOnce(Return(std::string{}));
    EXPECT_EQ(std::string{}, vertex->getUsername());

    delete vertex;
}

TEST_F(TestSocialNetworkUser, GET_USERNAME_TC_4)
{
    Vertex* vertex = new SocialNetworkUser(username);

    InSequence sequence;
    EXPECT_CALL(socialNetworkUserMock, getUsername()).WillOnce(Return(username));
    EXPECT_EQ(username, vertex->getUsername());

    delete vertex;
}

TEST_F(TestSocialNetworkUser, GET_USERNAME_TC_5)
{
    InSequence sequence;
    std::shared_ptr<Vertex> vertex{new SocialNetworkUser(std::string{})};

    EXPECT_CALL(socialNetworkUserMock, getUsername()).WillOnce(Return(std::string{}));
    EXPECT_EQ(std::string{}, vertex->getUsername());
}

TEST_F(TestSocialNetworkUser, GET_USERNAME_TC_6)
{
    InSequence sequence;
    std::shared_ptr<Vertex> vertex{new SocialNetworkUser(username)};

    EXPECT_CALL(socialNetworkUserMock, getUsername()).WillOnce(Return(username));
    EXPECT_EQ(username, vertex->getUsername());
}

