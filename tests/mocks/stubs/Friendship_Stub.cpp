#include "Friendship.h"
#include "MockFriendship.h"

MockFriendship* mockFriendship = nullptr;

MockFriendship::MockFriendship()
{
    mockFriendship = this;
}

MockFriendship::~MockFriendship() noexcept
{
    mockFriendship = nullptr;
}

std::shared_ptr<Vertex> Friendship::getVertex1()
{
    if (mockFriendship != nullptr)
    {
        return mockFriendship->getVertex1();
    }
    return nullptr;
}

std::shared_ptr<Vertex> Friendship::getVertex2()
{
    if (mockFriendship != nullptr)
    {
        return mockFriendship->getVertex2();
    }
    return nullptr;
}

void Friendship::setVertex(const std::shared_ptr<Vertex> &vertex, bool position)
{
    if (mockFriendship != nullptr)
    {
        mockFriendship->setVertex(vertex, position);
    }
}

void Friendship::setVertex(const Vertex *const vertex, bool position)
{
    if (mockFriendship != nullptr)
    {
        mockFriendship->setVertex(vertex, position);
    }
}

Friendship::Friendship(std::shared_ptr<Vertex> &&user1, std::shared_ptr<Vertex> &&user2)
{

}

Friendship::Friendship(Vertex *user1, Vertex *user2)
{

}

Friendship::Friendship(const std::shared_ptr<Vertex> &user1, const std::shared_ptr<Vertex> &user2)
{
    m_user1 = user1;
    m_user2 = user2;
}
