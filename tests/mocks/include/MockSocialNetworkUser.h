#ifndef TESTS_MOCK_SOCIAL_NETWORK_USER_H
#define TESTS_MOCK_SOCIAL_NETWORK_USER_H

#include <string>
#include "gmock/gmock.h"

class SocialNetworkUserInterface
{
public:
    virtual ~SocialNetworkUserInterface() = default;

protected:
    [[nodiscard]] virtual std::string getUsername() const = 0;
    virtual void setUsername(std::string label) = 0;
};

class MockSocialNetworkUser : public SocialNetworkUserInterface
{
public:
    ~MockSocialNetworkUser() override = default;
    MOCK_CONST_METHOD0(getUsername, std::string());
    MOCK_METHOD1(setUsername, void(std::string));
};

#endif //TESTS_MOCK_SOCIAL_NETWORK_USER_H