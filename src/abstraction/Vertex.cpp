#include "abstraction/Vertex.h"

Vertex::~Vertex()= default;

bool Vertex::operator==(Vertex &vertex) const
{
    return this->getUsername() == vertex.getUsername();
}
