#ifndef TESTS_MOCK_SOCIAL_NETWORK_H
#define TESTS_MOCK_SOCIAL_NETWORK_H

// include gmock
#include "gmock/gmock.h"

// include project header(s)
#include "Friendship.h"

// include other libraries
#include <map>
#include <string>
#include <vector>

class SocialNetworkInterface
{
public:
    virtual ~SocialNetworkInterface() = default;

protected:
    virtual bool addVertex(const SocialNetworkUser&) = 0;
    virtual bool addEdge(const Friendship &) = 0;
    virtual bool isEdgeInGraph(const Friendship &) = 0;
    virtual std::map<SocialNetworkUser, std::vector<SocialNetworkUser>> getAdjList() = 0;
    virtual std::vector<SocialNetworkUser> getUsers() = 0;
    virtual void shortestPath(const SocialNetworkUser&, const SocialNetworkUser&) = 0;
    virtual bool isVertexInGraph(const SocialNetworkUser &) = 0;
    virtual bool removeFriendship(const Friendship &) = 0;
    virtual bool removeUser(const SocialNetworkUser &) = 0;
    virtual bool breadthFirstSearch(const SocialNetworkUser &, const SocialNetworkUser &,
                                    std::map<SocialNetworkUser, SocialNetworkUser> &,
                                    std::map<SocialNetworkUser, int> &) = 0;
    virtual void printPath(const std::vector<SocialNetworkUser>&) = 0;
    virtual std::vector<SocialNetworkUser> getPath(const SocialNetworkUser &,
                                          const SocialNetworkUser &,
                                          std::map<SocialNetworkUser, SocialNetworkUser> &,
                                          std::map<SocialNetworkUser, int> &) = 0;
    virtual bool shortestPath(const SocialNetworkUser &source, const SocialNetworkUser &, std::vector<SocialNetworkUser> &) = 0;
};

class MockSocialNetwork : public SocialNetworkInterface
{
public:
    ~MockSocialNetwork() override = default;
    MOCK_METHOD1(addVertex, bool(const SocialNetworkUser&));
    MOCK_METHOD1(addEdge, bool(const Friendship&));
    MOCK_METHOD1(isEdgeInGraph, bool(const Friendship&));
    MOCK_METHOD4(breadthFirstSearch, bool(const SocialNetworkUser &, const SocialNetworkUser &,
                                          std::map<SocialNetworkUser, SocialNetworkUser> &,
                                          std::map<SocialNetworkUser, int> &));
    MOCK_METHOD0(getAdjList, std::map<SocialNetworkUser, std::vector<SocialNetworkUser>>());
    MOCK_METHOD4(getPath, std::vector<SocialNetworkUser>(const SocialNetworkUser &, const SocialNetworkUser &,
                               std::map<SocialNetworkUser, SocialNetworkUser> &, std::map<SocialNetworkUser, int> &));
    MOCK_METHOD0(getUsers, std::vector<SocialNetworkUser>());
    MOCK_METHOD1(printPath, void(const std::vector<SocialNetworkUser>&));
    MOCK_METHOD1(removeFriendship, bool(const Friendship&));
    MOCK_METHOD1(removeUser, bool(const SocialNetworkUser&));
    MOCK_METHOD2(shortestPath, void(const SocialNetworkUser&, const SocialNetworkUser&));
    MOCK_METHOD3(shortestPath, bool(const SocialNetworkUser &source, const SocialNetworkUser &, std::vector<SocialNetworkUser> &));
    MOCK_METHOD1(isVertexInGraph, bool(const SocialNetworkUser&));
};

#endif //TESTS_MOCK_SOCIAL_NETWORK_H