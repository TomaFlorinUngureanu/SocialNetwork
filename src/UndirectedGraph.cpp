#include "../include/UndirectedGraph.h"
#include <algorithm>
#include <iostream>

UndirectedGraph::UndirectedGraph(UndirectedGraph &&graph) noexcept
{
    m_vertices = std::move(graph.m_vertices);
    m_edges = std::move(graph.m_edges);
}

UndirectedGraph::UndirectedGraph(const UndirectedGraph &graph)
{
    m_edges = graph.m_edges;
    m_vertices = graph.m_vertices;
}

UndirectedGraph &UndirectedGraph::operator=(UndirectedGraph &&graph) noexcept
{
    return *this;
}

UndirectedGraph &UndirectedGraph::operator=(const UndirectedGraph &graph)
{
    return *this;
}

bool UndirectedGraph::addEdge(const Edge &edge)
{
    if (isEdgeInGraph(edge))
    {
        std::cout << "Edge already in the graph!\n";
        return false;
    }
    m_edges.push_back(edge);
    return true;
}

bool UndirectedGraph::addVertex(const Vertex &vertex)
{
    if (isVertexInGraph(vertex))
    {
        std::cout << "Vertex already in this graph!\n";
        return false;
    }
    m_vertices.push_back(vertex);
    return true;
}

std::vector<Vertex> UndirectedGraph::getVertices()
{
    return m_vertices;
}

std::vector<Edge> UndirectedGraph::getEdges()
{
    return m_edges;
}

bool UndirectedGraph::isEdgeInGraph(const Edge &edge)
{
    return std::find(m_edges.begin(), m_edges.end(), edge) != m_edges.cend();
}

bool UndirectedGraph::isVertexInGraph(const Vertex &vertex)
{
    return std::find(m_vertices.begin(), m_vertices.end(), vertex) != m_vertices.cend();
}

bool UndirectedGraph::removeEdge(const Edge &edge)
{
    if (!isEdgeInGraph(edge))
    {
        std::cout << "Edge is not in the graph!\n";
        return false;
    }
    m_edges.erase(std::remove(m_edges.begin(), m_edges.end(), edge), m_edges.end());
    return true;
}

bool UndirectedGraph::removeVertex(const Vertex &vertex)
{
    if (!isVertexInGraph(vertex))
    {
        std::cout << "Vertex not found in the graph!\n";
    }
    return true;
}