#ifndef SHORELINE_FRIENDSHIP_H
#define SHORELINE_FRIENDSHIP_H

// project class headers
#include "SocialNetworkUser.h"
#include "abstraction/Edge.h"

// other used libraries
#include "memory"

class Friendship: public Edge
{
private:
    // Members
    SocialNetworkUser m_user1{};
    SocialNetworkUser m_user2{};

public:
    // Constructors
    Friendship() = default;
    Friendship(SocialNetworkUser vertex) = delete;
    Friendship(Friendship &&friendship) noexcept;
    Friendship(const Friendship &friendship);
    Friendship(const SocialNetworkUser &socialNetworkUser1, const SocialNetworkUser &socialNetworkUser2);

    // Destructor
    ~Friendship() override = default;

    // Copy and Move assignment operators
    Friendship &operator=(const Friendship &edge) = delete;
    Friendship &operator=(Friendship &&friendship) noexcept;

    // Other operators
    bool operator==(const Friendship &edge);

    [[nodiscard]] SocialNetworkUser getUser1() const override;
    [[nodiscard]] SocialNetworkUser getUser2() const override;
    void setUser(const SocialNetworkUser& socialNetworkUser, bool position) override;
};

#endif //SHORELINE_FRIENDSHIP_H