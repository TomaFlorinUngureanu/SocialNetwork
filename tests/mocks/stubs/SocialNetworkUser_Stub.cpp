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

std::string SocialNetworkUser::getLabel() const
{
    if (snuInterface != nullptr)
    {
        return snuInterface->getLabel();
    }
    return "";
}

void SocialNetworkUser::setLabel(const std::string &userName)
{
    if (snuInterface != nullptr)
    {
        m_username = userName;
        snuInterface->setLabel(userName);
    }
}

SocialNetworkUser::SocialNetworkUser(const std::string &username)
{
    if (snuInterface != nullptr)
    {
        m_username = username;
    }
}