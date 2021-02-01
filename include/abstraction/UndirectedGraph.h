#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

// project class headers
#include "Friendship.h"
#include "SocialNetworkUser.h"

// other used libraries
#include <map>
#include <utility>
#include <vector>

class UndirectedGraph
{
protected:
    // Constructors
    UndirectedGraph() = default;
    UndirectedGraph(const UndirectedGraph& graph) = default;
    UndirectedGraph(UndirectedGraph&& graph) noexcept = default;

    // Destructor
    ~UndirectedGraph() = default;

    // Copy and Move assignment operators
    UndirectedGraph& operator=(UndirectedGraph&& graph) noexcept = default;
    UndirectedGraph& operator=(const UndirectedGraph& graph) = default;

    virtual bool addFriendship(const Friendship& friendship) = 0;
    virtual bool addUser(const SocialNetworkUser& socialNetworkUser) = 0;
    virtual bool areFriends(const Friendship& friendship) = 0;
    virtual std::map<SocialNetworkUser, std::vector<SocialNetworkUser>> getFriendships() = 0;
    virtual std::vector<SocialNetworkUser> getUsers() = 0;
    virtual bool userExists(const SocialNetworkUser& socialNetworkUser) = 0;
    virtual bool removeFriendship(const Friendship& friendship) = 0;
    virtual bool removeUser(const SocialNetworkUser& socialNetworkUser) = 0;
};

#endif //UNDIRECTEDGRAPH_H