#include "SocialNetworkUser.h"

SocialNetworkUser::SocialNetworkUser(const std::string &username)
{
    m_username = username;
}

SocialNetworkUser::SocialNetworkUser(SocialNetworkUser &&socialNetworkUser) noexcept
{
    m_username = std::move(socialNetworkUser.m_username);
}

SocialNetworkUser &SocialNetworkUser::operator=(SocialNetworkUser &&socialNetworkUser) noexcept
{
    m_username = std::move(socialNetworkUser.m_username);
    return *this;
}

bool SocialNetworkUser::operator==(const SocialNetworkUser &socialNetworkUser) const
{
    return m_username == socialNetworkUser.m_username;
}

bool SocialNetworkUser::operator!=(const SocialNetworkUser &socialNetworkUser) const
{
    return m_username != socialNetworkUser.m_username;
}

bool SocialNetworkUser::operator<(const SocialNetworkUser &socialNetworkUser) const
{
    return m_username < socialNetworkUser.m_username;
}

std::string SocialNetworkUser::getUsername() const
{
    return m_username;
}

void SocialNetworkUser::setUsername(const std::string& userName)
{
    m_username = userName;
}