#include "SocialNetwork.h"
#include <memory>
#include <iostream>

int main()
{
    UndirectedGraph* socialNetwork = new SocialNetwork();
    std::shared_ptr<Vertex> v0{new SocialNetworkUser("User0")};
    unsigned int added_vertices = 10;
    for (int i = 0; i < added_vertices; i+=3)
    {
        std::shared_ptr<Vertex> v1{new SocialNetworkUser("User" + std::to_string(i + 1))};
        std::shared_ptr<Vertex> v2{new SocialNetworkUser("User" + std::to_string(i + 2))};
        std::shared_ptr<Vertex> v3{new SocialNetworkUser("User" + std::to_string(i + 3))};
        socialNetwork->addEdge(v1, v2);
        socialNetwork->addEdge(v2, v3);
        socialNetwork->addEdge(new SocialNetworkUser("User" + std::to_string(i + 3)),
                               new SocialNetworkUser("User" + std::to_string(i + 4)));
    }

    socialNetwork->addVertex(v0);
    socialNetwork->addEdge(v0, std::shared_ptr<Vertex>(new SocialNetworkUser("User1")));
    socialNetwork->printFriendList();
    socialNetwork->shortestPath(new SocialNetworkUser("User0"),
                                new SocialNetworkUser("User" + std::to_string(added_vertices - 1)));
    std::cout<<"Number of friendships: "<<socialNetwork->getEdges().size();
    return 0;
}