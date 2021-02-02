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
    std::unordered_map<std::shared_ptr<Vertex>, std::vector<std::shared_ptr<Vertex>>, AdjListHash, AdjListEquality> m_friendsList;

    // Private functions
    bool breadthFirstSearch(const std::shared_ptr<Vertex> &source, const std::shared_ptr<Vertex> &destination,
                            std::map<std::shared_ptr<Vertex>, std::shared_ptr<Vertex>> &pred,
                            std::map<std::shared_ptr<Vertex>, int> &distance);
    void printPath(const std::vector<std::shared_ptr<Vertex>> &pathDistance);
    std::vector<std::shared_ptr<Vertex>> getPath(const std::shared_ptr<Vertex> &source,
                                                 const std::shared_ptr<Vertex> &destination,
                                                 std::map<std::shared_ptr<Vertex>, std::shared_ptr<Vertex>> &predecessor,
                                                 std::map<std::shared_ptr<Vertex>, int> &distance);
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

    bool addUser(Vertex *user) override;
    bool addUser(const SocialNetworkUser& user);
    bool addUser(const std::shared_ptr<SocialNetworkUser> &user);
    bool addUser(const std::shared_ptr<Vertex> &user) override;

    bool addFriendship(Edge *edge) override;
    bool addFriendship(Vertex *user1, Vertex *user2) override;
    bool addFriendship(Friendship &friendship) override;
    bool addFriendship(const std::shared_ptr<Edge> &edge) override;
    bool addFriendship(const std::shared_ptr<Vertex> &user1, const std::shared_ptr<Vertex> &user2) override;

    bool areFriends(Edge *edge) override;
    bool areFriends(Vertex *user1, Vertex *user2) override;
    bool areFriends(const SocialNetworkUser& user1, const SocialNetworkUser& user2);
    bool areFriends(Friendship &friendship);
    bool areFriends(const std::shared_ptr<Edge> &edge) override;
    bool areFriends(const std::shared_ptr<Vertex> &user1, const std::shared_ptr<Vertex> &user2) override;

    bool userExists(Vertex *vertex) override;
    bool userExists(const std::shared_ptr<Vertex> &vertex) override;

    bool shortestChainOfFriends(const std::shared_ptr<Vertex> &user1, const std::shared_ptr<Vertex> &user2) override;
    bool shortestChainOfFriends(Vertex *user1, Vertex *user2) override;

    std::unordered_map<std::shared_ptr<Vertex>, std::vector<std::shared_ptr<Vertex>>, AdjListHash, AdjListEquality>
    getFriendships() override;
    std::vector<std::shared_ptr<Vertex>> getVertices() override;
    bool removeEdge(const std::shared_ptr<Edge> &edge) override;
    bool removeVertex(const std::shared_ptr<Vertex> &vertex) override;
    void printFriendList() override;
};

#endif //SOCIALNETWORK_H