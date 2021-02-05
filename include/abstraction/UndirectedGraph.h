#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

// project class headers
#include "Friendship.h"
#include "SocialNetworkUser.h"

// other used libraries
#include <unordered_map>
#include <utility>
#include <vector>

struct VertexMapEq
{
    bool operator()(const std::shared_ptr<Vertex>& Lhs, const std::shared_ptr<Vertex>& Rhs) const
    {
        return *Lhs == *Rhs;
    }
};

struct VertexMapHash
{
    std::size_t operator()(const std::shared_ptr<Vertex>& vertex) const
    {
        std::hash<std::string> hasher;
        return hasher(vertex->getLabel());
    }
};

class UndirectedGraph
{
public:
    // Constructors
    UndirectedGraph() = default;
    UndirectedGraph(const UndirectedGraph& graph) =     default;
    UndirectedGraph(UndirectedGraph&& graph) noexcept = default;

    // Destructor
    virtual ~UndirectedGraph() = 0;

    // Copy and Move assignment operators
    UndirectedGraph& operator=(UndirectedGraph&& graph) noexcept =  default;
    UndirectedGraph& operator=(const UndirectedGraph& graph) =      default;

    [[maybe_unused]] virtual bool addEdge(Vertex *user1, std::shared_ptr<Vertex>& user2) =              delete;
    [[maybe_unused]] virtual bool addEdge(Vertex *user1, const std::shared_ptr<Vertex>& user2) =        delete;
    [[maybe_unused]] virtual bool addEdge(const Vertex *user1, const std::shared_ptr<Vertex>& user2) =  delete;
    [[maybe_unused]] virtual bool addEdge(std::shared_ptr<Vertex>& user1, Vertex * user2) =             delete;
    [[maybe_unused]] virtual bool addEdge(std::shared_ptr<Vertex>& user1, const Vertex * user2) =       delete;
    [[maybe_unused]] virtual bool addEdge(const std::shared_ptr<Vertex>& user1, Vertex * user2) =       delete;
    [[maybe_unused]] virtual bool addEdge(const std::shared_ptr<Vertex>& user1, const Vertex * user2) = delete;

    virtual bool addEdge(Edge* edge) = 0;
    virtual bool addEdge(const std::shared_ptr<Edge>& edge) = 0;
    virtual bool addEdge(Vertex *user1, Vertex *user2) = 0;
    virtual bool addEdge(const std::shared_ptr<Vertex>& user1, const std::shared_ptr<Vertex>& user2) = 0;

    virtual bool addVertex(Vertex* user) = 0;
    virtual bool addVertex(const std::shared_ptr<Vertex>& user) = 0;

    virtual bool isEdgeInGraph(Vertex *user1, std::shared_ptr<Vertex>& user2) =                 delete;
    virtual bool isEdgeInGraph(Vertex *user1, const std::shared_ptr<Vertex>& user2) =           delete;
    virtual bool isEdgeInGraph(const Vertex *user1, const std::shared_ptr<Vertex>& user2) =     delete;
    virtual bool isEdgeInGraph(std::shared_ptr<Vertex>& user2, Vertex * user1) =                delete;
    virtual bool isEdgeInGraph(std::shared_ptr<Vertex>& user2, const Vertex * user1) =          delete;
    virtual bool isEdgeInGraph(const std::shared_ptr<Vertex>& user2, Vertex * user1) =          delete;
    virtual bool isEdgeInGraph(const std::shared_ptr<Vertex>& user2, const Vertex * user1) =    delete;

    virtual bool isEdgeInGraph(Edge *edge) = 0;
    virtual bool isEdgeInGraph(Vertex *user1, Vertex *user2) = 0;
    virtual bool isEdgeInGraph(const std::shared_ptr<Edge>& edge) = 0;
    virtual bool isEdgeInGraph(const std::shared_ptr<Vertex> &user1, const std::shared_ptr<Vertex> &user2) = 0;

    virtual bool isVertexInGraph(Vertex* vertex) = 0;
    virtual bool isVertexInGraph(const std::shared_ptr<Vertex> &vertex) = 0;

    virtual bool shortestPath(const std::shared_ptr<Vertex>& user1, const std::shared_ptr<Vertex>& user2) = 0;
    virtual bool shortestPath(Vertex *user1, Vertex *user2) = 0;
    virtual std::unordered_map<std::shared_ptr<Vertex>, std::vector<std::shared_ptr<Vertex>>, VertexMapHash, VertexMapEq> getAdjList() = 0;
    virtual std::vector<std::shared_ptr<Vertex>> getVertices() = 0;
    virtual bool removeEdge(const std::shared_ptr<Edge>& edge) = 0;
    virtual bool removeEdge(const Edge* edge) = 0;
    virtual bool removeVertex(const std::shared_ptr<Vertex> &vertex) = 0;
    virtual bool removeVertex(const Vertex* vertex) = 0;
    virtual void printFriendList() = 0;
};

#endif //UNDIRECTEDGRAPH_H