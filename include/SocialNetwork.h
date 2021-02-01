#ifndef SOCIALNETWORK_H
#define SOCIALNETWORK_H

// project class headers
#include "abstraction/UndirectedGraph.h"
#include "SocialNetworkUser.h"

class SocialNetwork: public UndirectedGraph
{
private:
    // Members
    std::vector<SocialNetworkUser> m_users;
    std::vector<Friendship> m_friendships;
    std::map<SocialNetworkUser, std::vector<SocialNetworkUser>> m_friendsList;

    // Private functions
    bool breadthFirstSearch(const SocialNetworkUser &source, const SocialNetworkUser &destination,
                            std::map<SocialNetworkUser, SocialNetworkUser> &pred,
                            std::map<SocialNetworkUser, int> &distance);

    void printPath(const std::vector<SocialNetworkUser>& pathDistance);

    std::vector<SocialNetworkUser>getPath(const SocialNetworkUser &source,
                                          const SocialNetworkUser &destination,
                                          std::map<SocialNetworkUser, SocialNetworkUser> &predecessor,
                                          std::map<SocialNetworkUser, int> &distance);

    bool shortestPath(const SocialNetworkUser &source, const SocialNetworkUser &destination, std::vector<SocialNetworkUser> &path);

public:
    // Constructors
    SocialNetwork() = default;
    SocialNetwork(SocialNetwork&& socialNetwork) noexcept ;
    SocialNetwork(const SocialNetwork& socialNetwork) = default;

    // Destructor
    ~SocialNetwork()  = default;

    // Copy and Move assignment operators
    SocialNetwork& operator=(SocialNetwork&& socialNetwork) noexcept;
    SocialNetwork& operator=(const SocialNetwork& socialNetwork) = default;

    bool addUser(const SocialNetworkUser& user) override;
    bool addFriendship(const Friendship &edge) override;
    bool areFriends(const Friendship &edge) override;
    std::map<SocialNetworkUser, std::vector<SocialNetworkUser>> getFriendships() override;
    std::vector<SocialNetworkUser> getUsers() override;
    void shortestChainOfFriends(const SocialNetworkUser& user1, const SocialNetworkUser& user2);
    bool userExists(const SocialNetworkUser &vertex) override;
    bool removeFriendship(const Friendship &edge) override;
    bool removeUser(const SocialNetworkUser &vertex) override;
};

#endif //SOCIALNETWORK_H