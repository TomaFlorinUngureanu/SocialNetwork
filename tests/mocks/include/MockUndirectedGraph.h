#ifndef TESTS_MOCKUNDIRECTEDGRAPH_H
#define TESTS_MOCKUNDIRECTEDGRAPH_H

// include gmock
#include "gmock/gmock.h"

// include project header(s)
#include "abstraction/Edge.h"

// include other libraries
#include <map>
#include <string>
#include <vector>

class UndirectedGraphInterface
{
public:
    virtual ~UndirectedGraphInterface() = default;

protected:
    virtual bool addEdge(const Edge& edge) = 0;
    virtual bool addVertex(const Vertex& vertex) = 0;
    virtual std::map<Vertex, std::vector<Vertex>> getAdjacencyList() = 0;
    virtual std::vector<Edge> getEdges() = 0;
    virtual std::vector<Vertex> getVertices() = 0;
    virtual void printAdjacencyList() = 0;
    virtual bool isEdgeInGraph(const Edge& edge) = 0;
    virtual bool isVertexInGraph(const Vertex& vertex) = 0;
    virtual bool shortestPath(const Vertex& source, const Vertex& destination) = 0;
    virtual bool removeEdge(const Edge& edge) = 0;
    virtual bool removeVertex(const Vertex& vertex) = 0;
    virtual bool breadthFirstSearch(const Vertex &source, const Vertex &destination, std::map<Vertex, Vertex> &pred,
                            std::map<Vertex, int> &distance) = 0;
    virtual std::pair<std::vector<Vertex>, int> getPath(const Vertex &source, const Vertex &destination, std::map<Vertex,
            Vertex> &predecessor, std::map<Vertex, int> &distance) = 0;
    virtual void printPath(const std::pair<std::vector<Vertex>, int>& pathDistance) = 0;
};

class MockUndirectedGraph final: public UndirectedGraphInterface
{
public:
    ~MockUndirectedGraph() override = default;
    MOCK_METHOD1(addEdge, bool(const Edge&));
    MOCK_METHOD1(addVertex, bool(const Vertex&));
    MOCK_METHOD0(getAdjacencyList, std::map<Vertex, std::vector<Vertex>>());
    MOCK_METHOD0(getEdges, std::vector<Edge>());
    MOCK_METHOD0(getVertices, std::vector<Vertex>());
    MOCK_METHOD0(printAdjacencyList, void());
    MOCK_METHOD1(isEdgeInGraph, bool(const Edge&));
    MOCK_METHOD1(isVertexInGraph, bool(const Vertex&));
    MOCK_METHOD2(shortestPath, bool(const Vertex&, const Vertex&));
    MOCK_METHOD1(removeEdge, bool(const Edge&));
    MOCK_METHOD1(removeVertex, bool(const Vertex&));
    MOCK_METHOD4(breadthFirstSearch, bool(const Vertex&, const Vertex&, std::map<Vertex, Vertex>&, std::map<Vertex, int>&));
    MOCK_METHOD1(printPath, void(const std::pair<std::vector<Vertex>, int>&));
};

#endif //TESTS_MOCKUNDIRECTEDGRAPH_H
