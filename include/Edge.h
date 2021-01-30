#ifndef SHORELINE_EDGE_H
#define SHORELINE_EDGE_H

#include "Vertex.h"

class Edge
{
private:
    Vertex m_vertex1;
    Vertex m_vertex2;

public:
    /**
     *
     */
    Edge() = delete;

    /**
     *
     * @param vertex
     */
    Edge(Vertex vertex) = delete;

    /**
     *
     * @param v1
     * @param v2
     */
    explicit Edge(Vertex v1, Vertex v2): m_vertex1(v1), m_vertex2(v2){}

    /**
     *
     * @param edge
     */
    Edge(const Edge& edge);

    /**
     *
     * @param edge
     */
    Edge(Edge&& edge) noexcept;

    /**
     *
     */
    ~Edge() = default;

    /**
     *
     * @param edge
     * @return
     */
    Edge& operator=(const Edge& edge);

    /**
     *
     * @param edge
     * @return
     */
    Edge& operator=(Edge&& edge) noexcept;

    /**
     *
     * @param edge
     * @return
     */
    bool operator==(const Edge& edge);

    /**
     *
     * @return
     */
    Vertex getVertex1() const;

    /**
     *
     * @return
     */
    Vertex getVertex2() const;

    /**
     *
     * @param vertex
     * @param position
     */
    void setVertex(const Vertex& vertex, bool position);
};


#endif //SHORELINE_EDGE_H
