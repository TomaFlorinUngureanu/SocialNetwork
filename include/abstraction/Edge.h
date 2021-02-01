#ifndef EDGE_H
#define EDGE_H

// project class headers
#include "SocialNetworkUser.h"

// other used libraries
#include <memory>

class Edge
{
protected:
    // Constructors
    Edge() = default;
    Edge(const Edge &edge) = default;
    Edge(Edge &&edge) noexcept = default;

    // Destructor
    virtual ~Edge() = 0;

    // Copy and Move assignment operators
    Edge &operator=(const Edge &edge) = default;
    Edge &operator=(Edge &&edge) noexcept = default;

    virtual void setUser(const SocialNetworkUser& socialNetworkUser, bool position) = 0;

public:
    Edge(Vertex* vertex) = delete;
    [[nodiscard]] virtual SocialNetworkUser getUser2() const = 0;
    [[nodiscard]] virtual SocialNetworkUser getUser1() const = 0;
};

#endif //EDGE_H