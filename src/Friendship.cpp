#include <exception/SocialNetworkException.h>
#include "Friendship.h"

Friendship::Friendship(const SocialNetworkUser &socialNetworkUser1, const SocialNetworkUser &socialNetworkUser2)
{
    m_user1 = socialNetworkUser1;
    m_user2 = socialNetworkUser2;
}

Friendship::Friendship(Friendship &&friendship) noexcept
{
    *this = std::move(friendship);
}

Friendship::Friendship(const Friendship &friendship)
{
    m_user1 = friendship.m_user1;
    m_user2 = friendship.m_user2;
}

Friendship &Friendship::operator=(Friendship &&friendship) noexcept
{
    m_user1 = std::move(friendship.m_user1);
    m_user2 = std::move(friendship.m_user2);
    return *this;
}

bool Friendship::operator==(const Friendship &edge)
{
    return false;
}

SocialNetworkUser Friendship::getUser1() const
{
    return m_user1;
}

SocialNetworkUser Friendship::getUser2() const
{
    return m_user2;
}

void Friendship::setUser(const SocialNetworkUser& socialNetworkUser, bool position)
{
    if (!socialNetworkUser.getUsername().empty() && !socialNetworkUser.getUsername().empty() && m_user2 == m_user1)
    {
        throw SocialNetworkException();
    }

    if (!position)
    {
        m_user1 = socialNetworkUser;
    } else
    {
        m_user2 = socialNetworkUser;
    }
}