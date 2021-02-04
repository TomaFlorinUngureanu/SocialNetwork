#ifndef FRIENDSHIP_H
#define FRIENDSHIP_H

// project class headers
#include "SocialNetworkUser.h"
#include "abstraction/Edge.h"

// other used libraries
#include "memory"

class Friendship : public Edge
{
private:

    // Members
    std::shared_ptr<Vertex> m_user1{};
    std::shared_ptr<Vertex> m_user2{};

public:
    // Constructors
    Friendship() = default;
    Friendship(Friendship &&friendship) noexcept;
    Friendship(const SocialNetworkUser& user1, const SocialNetworkUser& user2);
    Friendship(const Friendship &friendship);
    Friendship(Vertex *user1, Vertex *user2);
    Friendship(const std::shared_ptr<Vertex> &user1, const std::shared_ptr<Vertex> &user2);
    Friendship(std::shared_ptr<Vertex> &&user1, std::shared_ptr<Vertex> &&user2);

    Friendship(const std::shared_ptr<Vertex> &user1, Vertex *user2) = delete;
    Friendship(Vertex *user2, const std::shared_ptr<Vertex> &user1) = delete;
    Friendship(Vertex *user) = delete;
    Friendship(Vertex *&user) = delete;
    Friendship(const Vertex *user) = delete;
    Friendship(const Vertex *&user) = delete;
    Friendship(const std::shared_ptr<Vertex> &user) = delete;
    Friendship(std::shared_ptr<Vertex> &user) = delete;
    Friendship(std::shared_ptr<Vertex> user) = delete;

    // Destructor
    ~Friendship() override = default;

    // Copy and Move assignment operators
    Friendship &operator=(const Friendship &friendship) = delete;
    Friendship &operator=(Friendship &&friendship) noexcept;

    // Other operators
    [[nodiscard]] std::shared_ptr<Vertex> getVertex1() override;
    [[nodiscard]] std::shared_ptr<Vertex> getVertex2() override;
    void setVertex(const Vertex* vertex, bool position) override;
    void setVertex(const std::shared_ptr<Vertex> &socialNetworkUser, bool position) override;
};

#endif //FRIENDSHIP_H