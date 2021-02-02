#include <algorithm>
#include <list>
#include <iostream>
#include <climits>
#include "SocialNetwork.h"

SocialNetwork::SocialNetwork(SocialNetwork &&socialNetwork) noexcept
{
    *this = std::move(socialNetwork);
}

SocialNetwork &SocialNetwork::operator=(SocialNetwork &&socialNetwork) noexcept
{
    m_users = std::move(socialNetwork.m_users);
    m_friendsList = std::move(socialNetwork.m_friendsList);
    m_friendships = std::move(socialNetwork.m_friendships);
    return *this;
}

bool SocialNetwork::addFriendship(const std::shared_ptr<Edge> &edge)
{
    if (edge == nullptr)
    {
        std::cout << "Edge is nullptr!\n";
        return false;
    }

    if (*edge->getUser1() == *edge->getUser2())
    {
        std::cout << "You cannot be your own friend!\n";
        return false;
    }

    if (areFriends(edge))
    {
        std::cout << "You are already friends!\n";
        return false;
    }

    if (edge->getUser1()->getUsername().empty() || edge->getUser2()->getUsername().empty())
    {
        std::cout << "Cannot add an empty or incomplete edge!\n";
        return false;
    }

    if (!userExists(edge->getUser1()))
    {
        addUser(edge->getUser1());
    }

    if (!userExists(edge->getUser2()))
    {
        addUser(edge->getUser2());
    }

    m_friendships.push_back(edge);
    m_friendsList[std::shared_ptr<Vertex>(edge->getUser1())].push_back(std::shared_ptr<Vertex>(edge->getUser2()));
    m_friendsList[std::shared_ptr<Vertex>(edge->getUser2())].push_back(std::shared_ptr<Vertex>(edge->getUser1()));
    return true;
}

bool SocialNetwork::addUser(const std::shared_ptr<Vertex> &user)
{
    if (user == nullptr)
    {
        std::cout << "User is nullptr!";
        return false;
    }

    if (userExists(user))
    {
        std::cout << "Vertex already in this graph!\n";
        return false;
    }

    m_users.push_back(user);
    m_friendsList[user] = {};
    return true;
}

bool SocialNetwork::areFriends(const std::shared_ptr<Edge> &edge)
{
    return std::any_of(m_friendships.begin(), m_friendships.end(),
                       [&edge](const std::shared_ptr<Edge> &friendship)
                       { return *friendship == *edge; });
}

bool
SocialNetwork::breadthFirstSearch(const std::shared_ptr<Vertex> &source, const std::shared_ptr<Vertex> &destination,
                                  std::map<std::shared_ptr<Vertex>, std::shared_ptr<Vertex>> &pred,
                                  std::map<std::shared_ptr<Vertex>, int> &distance)
{
    std::list<std::shared_ptr<Vertex>> queue;
    std::map<std::shared_ptr<Vertex>, bool> visited;

    for (const std::shared_ptr<Vertex> &user: m_users)
    {
        visited[user] = false;
        distance[user] = INT_MAX;
        pred[user] = std::shared_ptr<Vertex>{new SocialNetworkUser{"INVALID"}};
    }

    visited[source] = true;
    distance[source] = 0;
    queue.push_back(source);

    while (!queue.empty())
    {
        std::shared_ptr<Vertex> queueUser{queue.front()};
        queue.pop_front();

        size_t adjListSize = m_friendsList[queueUser].size();
        for (size_t i = 0; i < adjListSize; i++)
        {
            std::shared_ptr<Vertex> adjListElement = m_friendsList[queueUser][i];
            if (!visited[adjListElement])
            {
                visited[adjListElement] = true;
                distance[adjListElement] = distance[queueUser] + 1;
                pred[adjListElement] = queueUser;
                queue.push_back(adjListElement);

                if (adjListElement == destination)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

std::vector<std::shared_ptr<Vertex>> SocialNetwork::getPath(const std::shared_ptr<Vertex> &source,
                                                            const std::shared_ptr<Vertex> &destination,
                                                            std::map<std::shared_ptr<Vertex>, std::shared_ptr<Vertex>> &predecessor,
                                                            std::map<std::shared_ptr<Vertex>, int> &distance)
{
    std::vector<std::shared_ptr<Vertex>> path;
    std::shared_ptr<Vertex> crawl = destination;
    path.push_back(crawl);

    while (predecessor[crawl]->getUsername() != "INVALID")
    {
        path.push_back(predecessor[crawl]);
        crawl = predecessor[crawl];
    }

    return path;
}

std::vector<std::shared_ptr<Vertex>> SocialNetwork::getVertices()
{
    return m_users;
}

void SocialNetwork::printPath(const std::vector<std::shared_ptr<Vertex>> &path)
{
    std::cout << "Shortest path length: " << path.size() - 1;
    std::cout << "\nPath: ";
    for (auto it = path.rbegin(); it != path.rend(); ++it)
    {
        std::cout << (*it)->getUsername() << " ";
    }
    std::cout << "\n";
}

bool SocialNetwork::removeEdge(const std::shared_ptr<Edge> &edge)
{
    if (edge == nullptr)
    {
        std::cout << "Edge is nullptr!\n";
        return false;
    }

    if (!areFriends(edge))
    {
        std::cout << "Edge is not in the graph!\n";
        return false;
    }

    // Remove the edge from the edges list
    m_friendships.erase(std::remove(m_friendships.begin(), m_friendships.end(), edge), m_friendships.end());

    // Remove the SECOND VERTEX from the adjacency list of the FIRST VERTEX in the received EDGE
    // 1. for ease of use
    std::vector<std::shared_ptr<Vertex>> adjList = std::move(m_friendsList[edge->getUser1()]);
    adjList.erase(std::remove(adjList.begin(), adjList.end(), edge->getUser2()), adjList.end());
    m_friendsList[edge->getUser1()] = std::move(adjList);

    // Remove the FIRST VERTEX from the adjacency list of the SECOND VERTEX in the received EDGE
    adjList = std::move(m_friendsList[edge->getUser2()]);
    adjList.erase(std::remove(adjList.begin(), adjList.end(), edge->getUser1()), adjList.end());
    m_friendsList[edge->getUser2()] = std::move(adjList);
    return true;
}

bool SocialNetwork::removeVertex(const std::shared_ptr<Vertex> &user)
{
    if (user == nullptr)
    {
        std::cout << "User is nullptr\n";
        return false;
    }

    if (!userExists(user))
    {
        std::cout << "Vertex not found in the graph!\n";
    }

    std::shared_ptr<Edge> edgeToBeRemoved{new Friendship()};
    edgeToBeRemoved->setUser(user, false);
    while (!m_friendsList[user].empty())
    {
        edgeToBeRemoved->setUser(m_friendsList[user][0], true);
    }
    m_users.erase(std::remove(m_users.begin(), m_users.end(), user), m_users.end());
    return true;
}

bool SocialNetwork::shortestChainOfFriends(const std::shared_ptr<Vertex> &user1, const std::shared_ptr<Vertex> &user2)
{
    if (user1 == nullptr || user2 == nullptr)
    {
        std::cout << "One of the users is nullptr\n";
        return false;
    }

    if (!userExists(user1))
    {
        std::cout << "User \"" + user1->getUsername() + "\" is not in the social network\n";
        return false;
    }

    if (!userExists(user2))
    {
        std::cout << "User " + user2->getUsername() + " is not in the social network\n";
        return false;
    }

    std::vector<std::shared_ptr<Vertex>> chain;
    shortestPath(user1, user2, chain);
    if (!chain.empty())
    {
        printPath(chain);
        return true;
    }

    return false;
}

bool SocialNetwork::shortestPath(const std::shared_ptr<Vertex> &source, const std::shared_ptr<Vertex> &destination,
                                 std::vector<std::shared_ptr<Vertex>> &path)
{
    std::map<std::shared_ptr<Vertex>, std::shared_ptr<Vertex>> predecessor;
    std::map<std::shared_ptr<Vertex>, int> distance;

    if (!breadthFirstSearch(source, destination, predecessor, distance))
    {
        std::cout << source->getUsername() + " and " + destination->getUsername() + " are not connected\n";
        return false;
    }

    path = std::move(getPath(source, destination, predecessor, distance));
    return true;
}

bool SocialNetwork::userExists(const std::shared_ptr<Vertex> &socialNetworkUser)
{
    return std::any_of(m_users.begin(), m_users.end(),
                       [&socialNetworkUser](const std::shared_ptr<Vertex> &user)
                       { return *user == *socialNetworkUser; });
}

bool SocialNetwork::addFriendship(const std::shared_ptr<Vertex> &user1, const std::shared_ptr<Vertex> &user2)
{
    if (user1 == nullptr || user2 == nullptr)
    {
        std::cout << "One of the users is nullptr";
        return false;
    }

    addFriendship(std::shared_ptr<Edge>(new Friendship(user1, user2)));
    return true;
}

bool SocialNetwork::addFriendship(Vertex *user1, Vertex *user2)
{
    if (user1 == nullptr || user2 == nullptr)
    {
        std::cout << "One of the users is nullptr";
        return false;
    }

    addFriendship(std::shared_ptr<Edge>(new Friendship(user1, user2)));
    return true;
}

bool SocialNetwork::addUser(Vertex *user)
{
    if (user == nullptr)
    {
        std::cout << "User is nullptr";
        return false;
    }

    addUser(std::shared_ptr<Vertex>(user));
    return true;
}

bool SocialNetwork::addFriendship(Friendship &friendship)
{
    addFriendship(std::shared_ptr<Edge>(new Friendship(friendship.getUser1(), friendship.getUser2())));
    return true;
}

bool SocialNetwork::addFriendship(Edge *edge)
{
    if (edge == nullptr)
    {
        std::cout << "Edge is nullptr";
        return false;
    }

    addFriendship(std::shared_ptr<Edge>(edge));
    return true;
}

void SocialNetwork::printFriendList()
{
    for (const auto &adjList: m_friendsList)
    {
        std::cout << "\nUser \"" + adjList.first->getUsername() + "\" has " + std::to_string(adjList.second.size()) +
                     " friend(s): \t";
        for (const auto &socialFriend: adjList.second)
        {
            std::cout << "\"" << socialFriend->getUsername() << "\", ";
        }
    }
    std::cout << "\n";
}

bool SocialNetwork::shortestChainOfFriends(Vertex *user1, Vertex *user2)
{
    return shortestChainOfFriends(std::shared_ptr<Vertex>(user1), std::shared_ptr<Vertex>(user2));
}

bool SocialNetwork::areFriends(const SocialNetworkUser& user1, const SocialNetworkUser& user2)
{
    return areFriends(std::shared_ptr<Vertex>(const_cast<SocialNetworkUser*>(&user1)),
                      std::shared_ptr<Vertex>(const_cast<SocialNetworkUser*>(&user2)));
}

bool SocialNetwork::addUser(const SocialNetworkUser& user)
{
    return addUser(std::shared_ptr<Vertex>(const_cast<SocialNetworkUser*>(&user)));
}

bool SocialNetwork::areFriends(Edge *edge)
{
    return areFriends(std::shared_ptr<Edge>(edge));
}

bool SocialNetwork::userExists(Vertex *vertex)
{
    return userExists(std::shared_ptr<Vertex>(vertex));
}

bool SocialNetwork::areFriends(Vertex *user1, Vertex *user2)
{
    return areFriends(std::shared_ptr<Edge>(new Friendship(user1, user2)));
}

bool SocialNetwork::areFriends(Friendship &friendship)
{
    return areFriends(std::shared_ptr<Friendship>(&friendship));
}

bool SocialNetwork::areFriends(const std::shared_ptr<Vertex> &user1, const std::shared_ptr<Vertex> &user2)
{
    return areFriends(std::shared_ptr<Edge>(new Friendship(user1, user2)));
}

bool SocialNetwork::addUser(const std::shared_ptr<SocialNetworkUser> &user)
{
    return addUser(std::shared_ptr<Vertex>(user));
}

std::unordered_map<std::shared_ptr<Vertex>, std::vector<std::shared_ptr<Vertex>>, AdjListHash, AdjListEquality>
SocialNetwork::getFriendships()
{
    return m_friendsList;
}
