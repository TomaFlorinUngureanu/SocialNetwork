#ifndef TESTS_MOCK_SOCIAL_NETWORK_USER_H
#define TESTS_MOCK_SOCIAL_NETWORK_USER_H

#include <string>
#include "gmock/gmock.h"

class VertexInterface: public Vertex
{
public:
    ~VertexInterface() override = default;
    VertexInterface() = default;
protected:
    [[nodiscard]] std::string getLabel() const override = 0;
    void setLabel(const std::string& username) override = 0;
};

class MockSocialNetworkUser : public VertexInterface
{
public:
    MockSocialNetworkUser();
    explicit MockSocialNetworkUser(const std::string &username);
    ~MockSocialNetworkUser() override;
    MOCK_CONST_METHOD0(getLabel, std::string());
    MOCK_METHOD1(setLabel, void(const std::string&));
};

#endif //TESTS_MOCK_SOCIAL_NETWORK_USER_H