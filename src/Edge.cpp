#include "../include/Edge.h"

Edge::Edge(const Edge &edge)
{
    m_vertex1 = edge.m_vertex1;
    m_vertex2 = edge.m_vertex2;
}

Edge::Edge(Edge &&edge) noexcept
{
    m_vertex1 = std::move(edge.m_vertex1);
    m_vertex2 = std::move(edge.m_vertex2);
}

Edge &Edge::operator=(const Edge &edge)
{
    return *this;
}

Edge &Edge::operator=(Edge &&edge) noexcept
{
    return *this;
}

bool Edge::operator==(const Edge& edge)
{
    return (m_vertex1 == edge.m_vertex1 && m_vertex2 == edge.m_vertex2) ||
           (m_vertex1 == edge.m_vertex2 && m_vertex2 == edge.m_vertex1);
}


Vertex Edge::getVertex1() const
{
    return m_vertex1;
}

Vertex Edge::getVertex2() const
{
    return m_vertex2;
}

void Edge::setVertex(const Vertex& vertex, bool position)
{
    if (position)
    {
        m_vertex1 = vertex;
    }
    else
    {
        m_vertex2 = vertex;
    }
}