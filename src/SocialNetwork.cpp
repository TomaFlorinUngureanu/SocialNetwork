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

bool SocialNetwork::addFriendship(const Friendship &friendship)
{
    if (areFriends(friendship))
    {
        std::cout << "Edge already in the graph!\n";
        return false;
    }

    if (friendship.getUser1().getUsername().empty() || friendship.getUser2().getUsername().empty())
    {
        std::cout << "Cannot add an empty or incomplete edge!\n";
        return false;
    }

    if (!userExists(friendship.getUser1()))
    {
        addUser(friendship.getUser1());
    }

    if (!userExists(friendship.getUser2()))
    {
        addUser(friendship.getUser2());
    }

    m_friendships.push_back(friendship);
    m_friendsList[friendship.getUser1()].push_back(friendship.getUser2());
    m_friendsList[friendship.getUser2()].push_back(friendship.getUser1());
    return true;
}

bool SocialNetwork::addUser(const SocialNetworkUser &user)
{
    if (userExists(user))
    {
        std::cout << "Vertex already in this graph!\n";
        return false;
    }

    m_users.push_back(user);
    return true;
}

bool SocialNetwork::areFriends(const Friendship &friendship)
{
    return std::find(m_friendships.begin(), m_friendships.end(), friendship) != m_friendships.cend();
}

bool SocialNetwork::breadthFirstSearch(const SocialNetworkUser &source, const SocialNetworkUser &destination,
                                       std::map<SocialNetworkUser, SocialNetworkUser> &pred,
                                       std::map<SocialNetworkUser, int> &distance)
{
    std::list<SocialNetworkUser> queue;
    std::map<SocialNetworkUser, bool> visited;

    for (const SocialNetworkUser &user: m_users)
    {
        visited[user] = false;
        distance[user] = INT_MAX;
        pred[user] = SocialNetworkUser{"INVALID"};
    }

    visited[source] = true;
    distance[source] = 0;
    queue.push_back(source);

    while (!queue.empty())
    {
        SocialNetworkUser queueUser = queue.front();
        queue.pop_front();

        size_t adjListSize = m_friendsList[queueUser].size();
        for (size_t i = 0; i < adjListSize; i++)
        {
            SocialNetworkUser adjListElement = m_friendsList[queueUser][i];
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

std::map<SocialNetworkUser, std::vector<SocialNetworkUser>> SocialNetwork::getFriendships()
{
    return m_friendsList;
}

std::vector<SocialNetworkUser> SocialNetwork::getPath(const SocialNetworkUser &source, const SocialNetworkUser &destination,
                                                      std::map<SocialNetworkUser, SocialNetworkUser> &predecessor,
                                                      std::map<SocialNetworkUser, int> &distance)
{
    std::vector<SocialNetworkUser> path;
    SocialNetworkUser crawl = destination;
    path.push_back(crawl);

    while (predecessor[crawl] != SocialNetworkUser("INVALID"))
    {
        path.push_back(predecessor[crawl]);
        crawl = predecessor[crawl];
    }

    return path;
}

std::vector<SocialNetworkUser> SocialNetwork::getUsers()
{
    return m_users;
}

void SocialNetwork::printPath(const std::vector<SocialNetworkUser> &path)
{
    std::cout << "Shortest path length: " << path.size() - 1;
    std::cout << "\nPath: ";
    for (auto it = path.rbegin(); it != path.rend(); ++it)
    {
        std::cout << it->getUsername() << " ";
    }
    std::cout << "\n";
}

bool SocialNetwork::removeFriendship(const Friendship &friendship)
{
    if (!areFriends(friendship))
    {
        std::cout << "Edge is not in the graph!\n";
        return false;
    }

    // Remove the edge from the edges list
    m_friendships.erase(std::remove(m_friendships.begin(), m_friendships.end(), friendship), m_friendships.end());

    // Remove the SECOND VERTEX from the adjacency list of the FIRST VERTEX in the received EDGE
    // 1. for ease of use
    std::vector<SocialNetworkUser> adjList = std::move(m_friendsList[friendship.getUser1()]);
    adjList.erase(std::remove(adjList.begin(), adjList.end(), friendship.getUser2()), adjList.end());
    m_friendsList[friendship.getUser1()] = std::move(adjList);

    // Remove the FIRST VERTEX from the adjacency list of the SECOND VERTEX in the received EDGE
    adjList = std::move(m_friendsList[friendship.getUser2()]);
    adjList.erase(std::remove(adjList.begin(), adjList.end(), friendship.getUser1()), adjList.end());
    m_friendsList[friendship.getUser2()] = std::move(adjList);
    return true;
}

bool SocialNetwork::removeUser(const SocialNetworkUser &user)
{
    if (!userExists(user))
    {
        std::cout << "Vertex not found in the graph!\n";
    }

    while (!m_friendsList[user].empty())
    {
        removeFriendship({user, m_friendsList[user][0]});
    }
    m_users.erase(std::remove(m_users.begin(), m_users.end(), user), m_users.end());
    return true;
}

void SocialNetwork::shortestChainOfFriends(const SocialNetworkUser &user1, const SocialNetworkUser &user2)
{
    std::vector<SocialNetworkUser> chain;
    shortestPath(user1, user2, chain);
    if (!chain.empty())
    {
        printPath(chain);
    }
}

bool SocialNetwork::shortestPath(const SocialNetworkUser &source, const SocialNetworkUser &destination,
                                 std::vector<SocialNetworkUser> &path)
{
    std::map<SocialNetworkUser, SocialNetworkUser> predecessor;
    std::map<SocialNetworkUser, int> distance;

    if (!breadthFirstSearch(source, destination, predecessor, distance))
    {
        std::cout << "Given source and destination are not connected\n";
        return false;
    }

    path = std::move(getPath(source, destination, predecessor, distance));
    return true;
}

bool SocialNetwork::userExists(const SocialNetworkUser &socialNetworkUser)
{
    return std::find(m_users.begin(), m_users.end(), socialNetworkUser) != m_users.cend();
}