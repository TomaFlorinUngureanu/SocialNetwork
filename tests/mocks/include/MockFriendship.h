#ifndef TESTS_MOCK_FRIENDSHIPS_H
#define TESTS_MOCK_FRIENDSHIPS_H

#include "SocialNetworkUser.h"
#include "gmock/gmock.h"

class FriendshipInterface
{
public:
    virtual ~FriendshipInterface() = default;

protected:
    [[nodiscard]] virtual SocialNetworkUser getVertex1() const = 0;
    [[nodiscard]] virtual SocialNetworkUser getVertex2() const = 0;
    virtual void setVertex(const SocialNetworkUser &, bool position) = 0;
};

class MockFriendship : public FriendshipInterface
{
public:
    ~MockFriendship() override = default;
    MOCK_CONST_METHOD0(getVertex1, SocialNetworkUser());
    MOCK_CONST_METHOD0(getVertex2, SocialNetworkUser());
    MOCK_METHOD2(setVertex, void(const SocialNetworkUser &, bool position));
};

#endif //TESTS_MOCK_FRIENDSHIPS_H