#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

// project class headers
#include "Friendship.h"
#include "SocialNetworkUser.h"

// other used libraries
#include <unordered_map>
#include <utility>
#include <vector>

struct AdjListEquality
{
    bool operator()(const std::shared_ptr<Vertex>& Lhs, const std::shared_ptr<Vertex>& Rhs) const
    {
        return *Lhs == *Rhs;
    }
};

struct AdjListHash
{
    std::size_t operator()(const std::shared_ptr<Vertex>& vertex) const
    {
        std::hash<std::string> hasher;
        return hasher(vertex->getUsername());
    }
};

class UndirectedGraph
{
public:
    // Constructors
    UndirectedGraph() = default;
    UndirectedGraph(const UndirectedGraph& graph) = default;
    UndirectedGraph(UndirectedGraph&& graph) noexcept = default;

    // Destructor
    virtual ~UndirectedGraph() = 0;

    // Copy and Move assignment operators
    UndirectedGraph& operator=(UndirectedGraph&& graph) noexcept = default;
    UndirectedGraph& operator=(const UndirectedGraph& graph) = default;

    [[maybe_unused]] virtual bool addFriendship(Vertex *user1, std::shared_ptr<Vertex>& user2) = delete;
    [[maybe_unused]] virtual bool addFriendship(Vertex *user1, const std::shared_ptr<Vertex>& user2) = delete;
    [[maybe_unused]] virtual bool addFriendship(const Vertex *user1, const std::shared_ptr<Vertex>& user2) = delete;
    [[maybe_unused]] virtual bool addFriendship(std::shared_ptr<Vertex>& user1, Vertex * user2) = delete;
    [[maybe_unused]] virtual bool addFriendship(std::shared_ptr<Vertex>& user1, const Vertex * user2) = delete;
    [[maybe_unused]] virtual bool addFriendship(const std::shared_ptr<Vertex>& user1, Vertex * user2) = delete;
    [[maybe_unused]] virtual bool addFriendship(const std::shared_ptr<Vertex>& user1, const Vertex * user2) = delete;

    virtual bool addFriendship(Edge* edge) = 0;
    virtual bool addFriendship(Friendship& friendship) = 0;
    virtual bool addFriendship(const std::shared_ptr<Edge>& edge) = 0;
    virtual bool addFriendship(Vertex *user1, Vertex *user2) = 0;
    virtual bool addFriendship(const std::shared_ptr<Vertex>& user1, const std::shared_ptr<Vertex>& user2) = 0;

    virtual bool addUser(Vertex* user) = 0;
    virtual bool addUser(const std::shared_ptr<Vertex>& user) = 0;

    virtual bool areFriends(Vertex *user1, std::shared_ptr<Vertex>& user2) = delete;
    virtual bool areFriends(Vertex *user1, const std::shared_ptr<Vertex>& user2) = delete;
    virtual bool areFriends(const Vertex *user1, const std::shared_ptr<Vertex>& user2) = delete;
    virtual bool areFriends(std::shared_ptr<Vertex>& user2, Vertex * user1) = delete;
    virtual bool areFriends(std::shared_ptr<Vertex>& user2, const Vertex * user1) = delete;
    virtual bool areFriends(const std::shared_ptr<Vertex>& user2, Vertex * user1) = delete;
    virtual bool areFriends(const std::shared_ptr<Vertex>& user2, const Vertex * user1) = delete;

    virtual bool areFriends(Edge *edge) = 0;
    virtual bool areFriends(Vertex *user1, Vertex *user2) = 0;
    virtual bool areFriends(const std::shared_ptr<Edge>& edge) = 0;
    virtual bool areFriends(const std::shared_ptr<Vertex> &user1, const std::shared_ptr<Vertex> &user2) = 0;

    virtual bool userExists(Vertex* vertex) = 0;
    virtual bool userExists(const std::shared_ptr<Vertex> &vertex) = 0;

    virtual bool shortestChainOfFriends(const std::shared_ptr<Vertex>& user1, const std::shared_ptr<Vertex>& user2) = 0;
    virtual bool shortestChainOfFriends(Vertex *user1, Vertex *user2) = 0;
    virtual std::unordered_map<std::shared_ptr<Vertex>, std::vector<std::shared_ptr<Vertex>>, AdjListHash, AdjListEquality> getFriendships() = 0;
    virtual std::vector<std::shared_ptr<Vertex>> getVertices() = 0;
    virtual bool removeEdge(const std::shared_ptr<Edge>&) = 0;
    virtual bool removeVertex(const std::shared_ptr<Vertex> &vertex) = 0;
    virtual void printFriendList() = 0;
};

#endif //UNDIRECTEDGRAPH_H