#include "Vertex.h"

Vertex::Vertex(const Vertex &vertex)
{
    m_label = vertex.m_label;
}

Vertex::Vertex(Vertex &&vertex) noexcept
{
    m_label = std::move(vertex.m_label);
}

bool Vertex::operator==(const Vertex &vertex) const
{
    return m_label == vertex.m_label;
}

Vertex &Vertex::operator=(const Vertex &vertex)
{
    return *this;
}

Vertex &Vertex::operator=(Vertex &&vertex) noexcept
{
    return *this;
}

std::string Vertex::getLabel()
{
    return m_label;
}

void Vertex::setLabel(const std::string& label)
{
    m_label = label;
}