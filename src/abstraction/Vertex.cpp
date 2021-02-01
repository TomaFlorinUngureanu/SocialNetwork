#include "abstraction/Vertex.h"

Vertex::Vertex(Vertex &&vertex) noexcept
{
    m_username = std::move(vertex.m_username);
}

Vertex &Vertex::operator=(Vertex &&vertex) noexcept
{
    m_username = std::move(vertex.m_username);
    return *this;
}

Vertex::~Vertex()= default;