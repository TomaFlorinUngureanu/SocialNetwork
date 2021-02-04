#ifndef TESTS_MOCK_FRIENDSHIPS_H
#define TESTS_MOCK_FRIENDSHIPS_H

#include "Friendship.h"
#include "gmock/gmock.h"

class FriendshipInterface: public Edge
{
public:
    FriendshipInterface() = default;
    ~FriendshipInterface() override = default;

protected:
    [[nodiscard]] std::shared_ptr<Vertex> getVertex1() override = 0;
    [[nodiscard]] std::shared_ptr<Vertex> getVertex2() override = 0;
    void setVertex(const std::shared_ptr<Vertex> &, bool) override = 0;
    void setVertex(const Vertex* vertex, bool position) override = 0;
};

class MockFriendship : public FriendshipInterface
{
public:
    MockFriendship();
    ~MockFriendship() override;
    MOCK_METHOD0(getVertex1, std::shared_ptr<Vertex>());
    MOCK_METHOD0(getVertex2, std::shared_ptr<Vertex>());
    MOCK_METHOD2(setVertex, void(const Vertex* const, bool));
    MOCK_METHOD2(setVertex, void(const std::shared_ptr<Vertex> &, bool));
};

#endif //TESTS_MOCK_FRIENDSHIPS_H