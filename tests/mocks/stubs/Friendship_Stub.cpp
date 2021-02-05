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

Friendship::F
