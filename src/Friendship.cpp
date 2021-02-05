#include <exception/SocialNetworkException.h>
#include <iostream>
#include "Friendship.h"

Friendship::Friendship(Friendship &&friendship) noexcept
{
    *this = std::move(friendship);
}

Friendship &Friendship::operator=(Friendship &&friendship) noexcept
{
    m_user1 = std::move(friendship.m_user1);
    m_user2 = std::move(friendship.m_user2);
    return *this;
}

std::shared_ptr<Vertex> Friendship::getVertex1()
{
    if (m_user1 == nullptr)
    {
        throw VertexNullException();
    }
    return m_user1;
}

std::shared_ptr<Vertex> Friendship::getVertex2()
{
    if (m_user2 == nullptr)
    {
        throw VertexNullException();
    }
    return m_user2;
}

void Friendship::setVertex(const std::shared_ptr<Vertex> &socialNetworkUser, bool position)
{
    if (socialNetworkUser == nullptr)
    {
        throw VertexNullException();
    }

    if (socialNetworkUser->getLabel().empty())
    {
        std::cout<<"User has no name!\n";
        return;
    }

    if (!position)
    {
        if (m_user2 == socialNetworkUser)
        {
            std::cout<<"Cannot set vertex as itself!\n";
            return;
        }
        m_user1 = socialNetworkUser;
    }
    else
    {
        if (m_user1 == socialNetworkUser)
        {
            std::cout<<"Cannot set vertex as itself!";
            return;
        }
        m_user2 = socialNetworkUser;
    }
}

Friendship::Friendship(const std::shared_ptr<Vertex> &socialNetworkUser1, const std::shared_ptr<Vertex> &socialNetworkUser2)
{
    if (socialNetworkUser1 == nullptr || socialNetworkUser2 == nullptr)
    {
        throw VertexNullException();
    }
    m_user1 = socialNetworkUser1;
    m_user2 = socialNetworkUser2;
}

Friendship::Friendship(std::shared_ptr<Vertex> &&socialNetworkUser1, std::shared_ptr<Vertex> &&socialNetworkUser2)
{
    if (socialNetworkUser1 == nullptr || socialNetworkUser2 == nullptr)
    {
        throw VertexNullException();
    }
    m_user1 = std::move(socialNetworkUser1);
    m_user2 = std::move(socialNetworkUser2);
}

Friendship::Friendship(Vertex *socialNetworkUser1, Vertex *socialNetworkUser2)
{
    if (socialNetworkUser1 == nullptr || socialNetworkUser2 == nullptr)
    {
        throw VertexNullException();
    }
    m_user1 = std::shared_ptr<Vertex>(socialNetworkUser1);
    m_user2 = std::shared_ptr<Vertex>(socialNetworkUser2);
}

void Friendship::setVertex(const Vertex *const vertex, bool position)
{
    setVertex(std::shared_ptr<Vertex>(const_cast<Vertex*>(vertex)), position);
}