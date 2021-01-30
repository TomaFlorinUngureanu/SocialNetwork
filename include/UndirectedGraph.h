#ifndef SHORELINE_UNDIRECTEDGRAPH_H
#define SHORELINE_UNDIRECTEDGRAPH_H

#include <vector>
#include <map>
#include "Edge.h"

class UndirectedGraph
{
private:
    std::vector<Vertex> m_vertices;
    std::vector<Edge> m_edges;
    std::map<Vertex, std::vector<Vertex>> m_adjacencyList;

public:

    /**
     *
     */
    UndirectedGraph() = default;

    /**
     *
     * @param graph
     */
    UndirectedGraph(UndirectedGraph&& graph) noexcept;

    /**
     *
     * @param graph
     */
    UndirectedGraph(const UndirectedGraph& graph);

    /**
     *
     * @param vertices
     * @param edges
     */
    UndirectedGraph(std::vector<Vertex> vertices, std::vector<Edge> edges) : m_vertices(vertices), m_edges(edges){}

    /**
     *
     */
    ~UndirectedGraph() = default;

    /**
     *
     * @param graph
     * @return
     */
    UndirectedGraph& operator=(const UndirectedGraph& graph);

    /**
     *
     * @param graph
     * @return
     */
    UndirectedGraph& operator=(UndirectedGraph&& graph) noexcept;

    /**
     *
     * @param edge
     * @return
     */
    bool addEdge(const Edge& edge);

    /**
     *
     * @param vertex
     * @return
     */
    bool addVertex(const Vertex& vertex);

    /**
     *
     * @return
     */
    std::map<Vertex, std::vector<Vertex>> getAdjacencyList();

    /**
     *
     * @return
     */
    std::vector<Edge> getEdges();

    /**
    *
    * @return
    */
    std::vector<Vertex> getVertices();

    /**
     *
     * @param edge
     * @return
     */
    bool isEdgeInGraph(const Edge& edge);

    /**
     *
     * @param vertex
     * @return
     */
    bool isVertexInGraph(const Vertex& vertex);

    /**
     *
     * @param edge
     * @return
     */
    bool removeEdge(const Edge& edge);

    /**
     *
     * @param vertex
     * @return
     */
    bool removeVertex(const Vertex& vertex);
};


#endif //SHORELINE_UNDIRECTEDGRAPH_H
