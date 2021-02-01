#ifndef SHORELINE_VERTEX_H
#define SHORELINE_VERTEX_H

// other used libraries
#include <string>
#include <utility>
#include <vector>

class Vertex
{
protected:
    // Members
    std::string m_username;

    // Constructors
    Vertex() = default;
    Vertex(const Vertex& vertex) = default;
    Vertex(Vertex&& vertex) noexcept;

    // Destructor
    virtual ~Vertex() = 0;

    // Copy and Move assignment operators
    Vertex &operator=(const Vertex &socialNetworkUser) = default;
    Vertex &operator=(Vertex &&socialNetworkUser) noexcept;

    virtual void setUsername(const std::string& label) = 0;

public:
    [[nodiscard]] virtual std::string getUsername() const = 0;
};

#endif //SHORELINE_VERTEX_H