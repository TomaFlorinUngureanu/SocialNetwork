#ifndef EDGE_H
#define EDGE_H

// project class headers
#include "SocialNetworkUser.h"

// other used libraries
#include <memory>

class Edge
{
public:
    // Constructors
    Edge() = default;
    Edge(const Edge &edge) = default;
    Edge(Edge &&edge) noexcept = default;

    Edge(Vertex* vertex) = delete;
    Edge(std::shared_ptr<Vertex> vertex) = delete;

    // Destructor
    virtual ~Edge() = 0;

    // Copy and Move assignment operators
    Edge &operator=(const Edge &edge) = default;
    Edge &operator=(Edge &&edge) noexcept = default;
    bool operator==(Edge &edge);

    virtual void setVertex(const Vertex* vertex, bool position) = 0;
    virtual void setVertex(const std::shared_ptr<Vertex> &socialNetworkUser, bool position) = 0;

    [[nodiscard]] virtual std::shared_ptr<Vertex> getVertex2() = 0;
    [[nodiscard]] virtual std::shared_ptr<Vertex> getVertex1() = 0;
};

#endif //EDGE_H