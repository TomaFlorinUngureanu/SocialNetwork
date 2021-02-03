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

bool SocialNetwork::addEdge(const std::shared_ptr<Edge> &edge)
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

    if (isEdgeInGraph(edge))
    {
        std::cout << "You are already friends!\n";
        return false;
    }

    if (edge->getUser1()->getUsername().empty() || edge->getUser2()->getUsername().empty())
    {
        std::cout << "Cannot add an empty or incomplete edge!\n";
        return false;
    }

    if (!isVertexInGraph(edge->getUser1()))
    {
        addVertex(edge->getUser1());
    }

    if (!isVertexInGraph(edge->getUser2()))
    {
        addVertex(edge->getUser2());
    }

    m_friendships.push_back(edge);
    m_friendsList[edge->getUser1()].push_back(edge->getUser2());
    m_friendsList[edge->getUser2()].push_back(edge->getUser1());
    return true;
}

bool SocialNetwork::addVertex(const std::shared_ptr<Vertex> &user)
{
    if (user == nullptr)
    {
        std::cout << "User is nullptr!";
        return false;
    }

    if (isVertexInGraph(user))
    {
        std::cout << "Vertex already in this graph!\n";
        return false;
    }

    m_users.push_back(user);
    m_friendsList[user] = {};
    return true;
}

bool SocialNetwork::isEdgeInGraph(const std::shared_ptr<Edge> &edge)
{
    return std::any_of(m_friendships.begin(), m_friendships.end(),
                       [&edge](const std::shared_ptr<Edge> &friendship)
                       { return *friendship == *edge; });
}

bool SocialNetwork::breadthFirstSearch(const std::shared_ptr<Vertex> &source, const std::shared_ptr<Vertex> &destination,
                                  std::unordered_map<std::shared_ptr<Vertex>, std::shared_ptr<Vertex>, VertexMapHash, VertexMapEq> &pred,
                                  std::unordered_map<std::shared_ptr<Vertex>, int, VertexMapHash, VertexMapEq> &distance)
{
    std::list<std::shared_ptr<Vertex>> queue;
    std::unordered_map<std::shared_ptr<Vertex>, bool, VertexMapHash, VertexMapEq> visited;

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
        std::shared_ptr<Vertex> queueUser = queue.front();
        queue.pop_front();

        size_t adjListSize = m_friendsList[queueUser].size();
        for (size_t i = 0; i < adjListSize; i++)
        {
            if (!visited[m_friendsList[queueUser][i]])
            {
                visited[m_friendsList[queueUser][i]] = true;
                distance[m_friendsList[queueUser][i]] = distance[queueUser] + 1;
                pred[m_friendsList[queueUser][i]] = queueUser;
                queue.push_back(m_friendsList[queueUser][i]);

                if (m_friendsList[queueUser][i]->getUsername() == destination->getUsername())
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
                                                            std::unordered_map<std::shared_ptr<Vertex>, std::shared_ptr<Vertex>, VertexMapHash, VertexMapEq> &pred,
                                                            std::unordered_map<std::shared_ptr<Vertex>, int, VertexMapHash, VertexMapEq> &distance)
{
    std::vector<std::shared_ptr<Vertex>> path;
    std::shared_ptr<Vertex> crawl = destination;
    path.push_back(crawl);

    while (pred[crawl]->getUsername() != "INVALID")
    {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
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

    if (!isEdgeInGraph(edge))
    {
        std::cout << "Edge is not in the graph!\n";
        return false;
    }

    // Remove the edge from the edges list
    auto pred = [&edge](const std::shared_ptr<Edge>& friendship){return *edge == *friendship;};
    auto it = std::remove_if(m_friendships.begin(), m_friendships.end(), pred);
    m_friendships.erase(it, m_friendships.end());

    // Remove the SECOND VERTEX from the adjacency list of the FIRST VERTEX in the received EDGE
    // 1. for ease of use
    auto pred1 = [&edge](const std::shared_ptr<Vertex>& user){return (*edge->getUser2() == *user || *edge->getUser1() == *user);};
    auto it1 = std::remove_if(m_friendsList[edge->getUser1()].begin(),m_friendsList[edge->getUser1()].end(), pred1);
    m_friendsList[edge->getUser1()].erase(it1 ,m_friendsList[edge->getUser1()].end());

    // Remove the FIRST VERTEX from the adjacency list of the SECOND VERTEX in the received EDGE
    it1 = std::remove_if(m_friendsList[edge->getUser2()].begin(),m_friendsList[edge->getUser2()].end(), pred1);
    m_friendsList[edge->getUser2()].erase(it1,m_friendsList[edge->getUser2()].end());
    return true;
}

bool SocialNetwork::removeVertex(const std::shared_ptr<Vertex> &user)
{
    if (user == nullptr)
    {
        std::cout << "User is nullptr\n";
        return false;
    }

    if (!isVertexInGraph(user))
    {
        std::cout << "Vertex not found in the graph!\n";
    }

    std::shared_ptr<Edge> edgeToBeRemoved{new Friendship()};
    edgeToBeRemoved->setUser(user, false);
    while (!m_friendsList[user].empty())
    {
        edgeToBeRemoved->setUser(m_friendsList[user][0], true);
        removeEdge(edgeToBeRemoved);
    }

    m_users.erase(std::remove(m_users.begin(), m_users.end(), user), m_users.end());
    return true;
}

bool SocialNetwork::shortestPath(const std::shared_ptr<Vertex> &user1, const std::shared_ptr<Vertex> &user2)
{
    if (user1 == nullptr || user2 == nullptr)
    {
        std::cout << "One of the users is nullptr\n";
        return false;
    }

    if (!isVertexInGraph(user1))
    {
        std::cout << "User \"" + user1->getUsername() + "\" is not in the social network\n";
        return false;
    }

    if (!isVertexInGraph(user2))
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
    std::unordered_map<std::shared_ptr<Vertex>, std::shared_ptr<Vertex>, VertexMapHash, VertexMapEq> predecessor;
    std::unordered_map<std::shared_ptr<Vertex>, int, VertexMapHash, VertexMapEq> distance;

    if (!breadthFirstSearch(source, destination, predecessor, distance))
    {
        std::cout << source->getUsername() + " and " + destination->getUsername() + " are not connected\n";
        return false;
    }

    path = std::move(getPath(source, destination, predecessor, distance));
    return true;
}

bool SocialNetwork::isVertexInGraph(const std::shared_ptr<Vertex> &socialNetworkUser)
{
    return std::any_of(m_users.begin(), m_users.end(),
                       [&socialNetworkUser](const std::shared_ptr<Vertex> &user)
                       { return *user == *socialNetworkUser; });
}

bool SocialNetwork::addEdge(const std::shared_ptr<Vertex> &user1, const std::shared_ptr<Vertex> &user2)
{
    if (user1 == nullptr || user2 == nullptr)
    {
        std::cout << "One of the users is nullptr";
        return false;
    }

    addEdge(std::shared_ptr<Edge>(new Friendship(user1, user2)));
    return true;
}

bool SocialNetwork::addEdge(Vertex *user1, Vertex *user2)
{
    if (user1 == nullptr || user2 == nullptr)
    {
        std::cout << "One of the users is nullptr";
        return false;
    }

    addEdge(std::shared_ptr<Edge>(new Friendship(user1, user2)));
    return true;
}

bool SocialNetwork::addVertex(Vertex *user)
{
    if (user == nullptr)
    {
        std::cout << "User is nullptr";
        return false;
    }

    addVertex(std::shared_ptr<Vertex>(user));
    return true;
}

bool SocialNetwork::addEdge(Friendship &friendship)
{
    addEdge(std::shared_ptr<Edge>(new Friendship(friendship.getUser1(), friendship.getUser2())));
    return true;
}

bool SocialNetwork::addEdge(Edge *edge)
{
    if (edge == nullptr)
    {
        std::cout << "Edge is nullptr";
        return false;
    }

    addEdge(std::shared_ptr<Edge>(edge));
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

bool SocialNetwork::shortestPath(Vertex *user1, Vertex *user2)
{
    return shortestPath(std::shared_ptr<Vertex>(user1), std::shared_ptr<Vertex>(user2));
}

bool SocialNetwork::isEdgeInGraph(const SocialNetworkUser& user1, const SocialNetworkUser& user2)
{
    return isEdgeInGraph(std::shared_ptr<Vertex>(const_cast<SocialNetworkUser*>(&user1)),
                      std::shared_ptr<Vertex>(const_cast<SocialNetworkUser*>(&user2)));
}

bool SocialNetwork::addVertex(const SocialNetworkUser& user)
{
    return addVertex(std::shared_ptr<Vertex>(const_cast<SocialNetworkUser*>(&user)));
}

bool SocialNetwork::isEdgeInGraph(Edge *edge)
{
    return isEdgeInGraph(std::shared_ptr<Edge>(edge));
}

bool SocialNetwork::isVertexInGraph(Vertex *vertex)
{
    return isVertexInGraph(std::shared_ptr<Vertex>(vertex));
}

bool SocialNetwork::isEdgeInGraph(Vertex *user1, Vertex *user2)
{
    return isEdgeInGraph(std::shared_ptr<Edge>(new Friendship(user1, user2)));
}

bool SocialNetwork::isEdgeInGraph(Friendship &friendship)
{
    return isEdgeInGraph(std::shared_ptr<Friendship>(&friendship));
}

bool SocialNetwork::isEdgeInGraph(const std::shared_ptr<Vertex> &user1, const std::shared_ptr<Vertex> &user2)
{
    return isEdgeInGraph(std::shared_ptr<Edge>(new Friendship(user1, user2)));
}

bool SocialNetwork::addVertex(const std::shared_ptr<SocialNetworkUser> &user)
{
    return addVertex(std::shared_ptr<Vertex>(user));
}

std::unordered_map<std::shared_ptr<Vertex>, std::vector<std::shared_ptr<Vertex>>, VertexMapHash, VertexMapEq>
SocialNetwork::getAdjList()
{
    return m_friendsList;
}

bool SocialNetwork::removeEdge(const Edge* const edge)
{
    return removeEdge(std::shared_ptr<Edge>(const_cast<Edge*>(edge)));
}

bool SocialNetwork::removeVertex(const Vertex *const vertex)
{
    return removeVertex(std::shared_ptr<Vertex>(const_cast<Vertex*>(vertex)));
}
