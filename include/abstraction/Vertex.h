#ifndef VERTEX_H
#define VERTEX_H

// other used libraries
#include <string>
#include <utility>
#include <vector>
#include <memory>

class Vertex
{
public:
    // Constructors
    Vertex() = default;
    Vertex(const Vertex& vertex) = default;
    Vertex(Vertex&& vertex) noexcept = default;

    // Destructor
    virtual ~Vertex() = 0;

    // Copy and Move assignment operators
    Vertex &operator=(const Vertex &vertex) = default;
    Vertex &operator=(Vertex &&vertex) noexcept = default;
    bool operator==(Vertex& vertex) const;

    virtual void setLabel(const std::string& username) = 0;
    [[nodiscard]] virtual std::string getLabel() const = 0;
};

#endif //VERTEX_H