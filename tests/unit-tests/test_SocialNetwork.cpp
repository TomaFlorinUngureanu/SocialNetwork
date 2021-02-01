// include project classes
#include "SocialNetwork.h"

// include mocks
#include "MockSocialNetwork.h"

// include GTest & Gmock
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::StrictMock;

class SocialNetworkTest: public ::testing::Test
{
    StrictMock<MockSocialNetwork> socialNetworkMock;
};

TEST_F(SocialNetworkTest, TC_1)
{
    SocialNetwork socialNetwork{};
}