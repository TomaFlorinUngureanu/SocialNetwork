#include "MockSocialNetworkUser.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::StrictMock;

class SocialNetworkUserTest: public testing::Test
{
    StrictMock<MockSocialNetworkUser> socialNetworkUserMock;
};

TEST_F(SocialNetworkUserTest, TC_1)
{
    MockSocialNetworkUser socialNetworkUser{};
}

