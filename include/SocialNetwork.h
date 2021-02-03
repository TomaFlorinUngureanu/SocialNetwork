#ifndef SOCIALNETWORK_H
#define SOCIALNETWORK_H

// project class headers
#include <map>
#include "abstraction/UndirectedGraph.h"
#include "SocialNetworkUser.h"

class SocialNetwork : public UndirectedGraph
{
private:

    // Members
    std::vector<std::shared_ptr<Vertex>> m_users;
    std::vector<std::shared_ptr<Edge>> m_friendships;
    std::unordered_map<std::shared_ptr<Vertex>, std::vector<std::shared_ptr<Vertex>>, VertexMapHash, VertexMapEq> m_friendsList;

    // Private functions
    bool breadthFirstSearch(const std::shared_ptr<Vertex> &source,
                            const std::shared_ptr<Vertex> &destination,
                            std::unordered_map<std::shared_ptr<Vertex>, std::shared_ptr<Vertex>, VertexMapHash, VertexMapEq> &pred,
                            std::unordered_map<std::shared_ptr<Vertex>, int, VertexMapHash, VertexMapEq> &distance);
    void printPath(const std::vector<std::shared_ptr<Vertex>> &pathDistance);
    std::vector<std::shared_ptr<Vertex>> getPath(const std::shared_ptr<Vertex> &source,
                                                 const std::shared_ptr<Vertex> &destination,
                                                 std::unordered_map<std::shared_ptr<Vertex>, std::shared_ptr<Vertex>, VertexMapHash, VertexMapEq> &pred,
                                                 std::unordered_map<std::shared_ptr<Vertex>, int, VertexMapHash, VertexMapEq> &distance);
    bool shortestPath(const std::shared_ptr<Vertex> &source, const std::shared_ptr<Vertex> &destination,
                      std::vector<std::shared_ptr<Vertex>> &path);
public:

    // Constructors
    SocialNetwork() = default;
    SocialNetwork(SocialNetwork &&socialNetwork) noexcept;
    SocialNetwork(const SocialNetwork &socialNetwork) = default;

    // Destructor
    ~SocialNetwork() override = default;

    // Copy and Move assignment operators
    SocialNetwork &operator=(SocialNetwork &&socialNetwork) noexcept;
    SocialNetwork &operator=(const SocialNetwork &socialNetwork) = default;

    bool removeVertex(const Vertex *const vertex) override;

    bool addVertex(Vertex *user) override;
    bool addVertex(const SocialNetworkUser& user);
    bool addVertex(const std::shared_ptr<SocialNetworkUser> &user);
    bool addVertex(const std::shared_ptr<Vertex> &user) override;

    bool addEdge(Edge *edge) override;
    bool addEdge(Vertex *user1, Vertex *user2) override;
    bool addEdge(Friendship &friendship);
    bool addEdge(const std::shared_ptr<Edge> &edge) override;
    bool addEdge(const std::shared_ptr<Vertex> &user1, const std::shared_ptr<Vertex> &user2) override;

    bool removeEdge(const Edge* edge) override;

    bool isEdgeInGraph(Edge *edge) override;
    bool isEdgeInGraph(Vertex *user1, Vertex *user2) override;
    bool isEdgeInGraph(const SocialNetworkUser& user1, const SocialNetworkUser& user2);
    bool isEdgeInGraph(Friendship &friendship);
    bool isEdgeInGraph(const std::shared_ptr<Edge> &edge) override;
    bool isEdgeInGraph(const std::shared_ptr<Vertex> &user1, const std::shared_ptr<Vertex> &user2) override;

    bool isVertexInGraph(Vertex *vertex) override;
    bool isVertexInGraph(const std::shared_ptr<Vertex> &vertex) override;

    bool shortestPath(const std::shared_ptr<Vertex> &user1, const std::shared_ptr<Vertex> &user2) override;
    bool shortestPath(Vertex *user1, Vertex *user2) override;

    std::unordered_map<std::shared_ptr<Vertex>, std::vector<std::shared_ptr<Vertex>>, VertexMapHash, VertexMapEq>
    getAdjList() override;
    std::vector<std::shared_ptr<Vertex>> getVertices() override;
    bool removeEdge(const std::shared_ptr<Edge> &edge) override;
    bool removeVertex(const std::shared_ptr<Vertex> &vertex) override;
    void printFriendList() override;
};

#endif //SOCIALNETWORK_H