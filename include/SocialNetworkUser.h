#ifndef SHORELINE_SOCIALNETWORKUSER_H
#define SHORELINE_SOCIALNETWORKUSER_H

// project class headers
#include "abstraction/Vertex.h"

// other used libraries
#include <utility>

class SocialNetworkUser : public Vertex
{
public:
    // Constructors
    SocialNetworkUser() = default;
    SocialNetworkUser(SocialNetworkUser&& socialNetworkUser) noexcept;
    SocialNetworkUser(const SocialNetworkUser& socialNetworkUser) = default;
    explicit SocialNetworkUser(const std::string& username);

    // Destructor
    ~SocialNetworkUser() override = default;

    // Copy and Move assignment operators
    SocialNetworkUser &operator=(const SocialNetworkUser &socialNetworkUser) = default;
    SocialNetworkUser &operator=(SocialNetworkUser &&socialNetworkUser) noexcept;

    // Other operators
    bool operator==(const SocialNetworkUser &socialNetworkUser) const;
    bool operator!=(const SocialNetworkUser &socialNetworkUser) const;
    bool operator<(const SocialNetworkUser &socialNetworkUser) const;

    [[nodiscard]] std::string getUsername() const override;
    void setUsername(const std::string &userName) override;
};

#endif //SHORELINE_SOCIALNETWORKUSER_H