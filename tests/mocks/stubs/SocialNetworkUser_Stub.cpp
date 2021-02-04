#include "SocialNetworkUser.h"
#include "MockSocialNetworkUser.h"

MockSocialNetworkUser* snuInterface = nullptr;


MockSocialNetworkUser::~MockSocialNetworkUser()
{
    snuInterface = nullptr;
}

MockSocialNetworkUser::MockSocialNetworkUser()
{
    snuInterface = this;
}

MockSocialNetworkUser::MockSocialNetworkUser(const std::string &username)
{
    snuInterface = this;
}

std::string SocialNetworkUser::getUsername() const
{
    if (snuInterface != nullptr)
    {
        return snuInterface->getUsername();
    }
    return "";
}

void SocialNetworkUser::setUsername(const std::string &userName)
{
    if (snuInterface != nullptr)
    {
        m_username = userName;
        snuInterface->setUsername(userName);
    }
}

SocialNetworkUser::SocialNetworkUser(const std::string &username)
{
    if (snuInterface != nullptr)
    {
        m_username = username;
    }
}