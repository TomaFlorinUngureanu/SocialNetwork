#include "SocialNetwork.h"
#include <memory>
#include <iostream>

int main()
{
    std::shared_ptr<Vertex> user1{new SocialNetworkUser("Tobias")};
    std::shared_ptr<Vertex> user2{new SocialNetworkUser("Andrew")};
    std::shared_ptr<UndirectedGraph> socialNetwork{new SocialNetwork()};

    socialNetwork->addVertex(user1);
    socialNetwork->addVertex(user2);
    socialNetwork->addVertex(new SocialNetworkUser("Thomas"));
    socialNetwork->addVertex(std::shared_ptr<Vertex>(new SocialNetworkUser("User")));
    socialNetwork->addEdge(user1, user2);
    Edge* edge1 = new Friendship{std::shared_ptr<Vertex>(new SocialNetworkUser("Thomas")),
                  std::shared_ptr<Vertex>(new SocialNetworkUser("User1"))};
    socialNetwork->addEdge(edge1);
    socialNetwork->addEdge(new SocialNetworkUser("User4"), new SocialNetworkUser("User5"));


    socialNetwork->printFriendList();
    std::cout << std::endl;
    socialNetwork->addEdge(new SocialNetworkUser("User4"), new SocialNetworkUser("User3"));
    socialNetwork->addEdge(new SocialNetworkUser("User1"), new SocialNetworkUser("User2"));
    socialNetwork->removeEdge(new Friendship(new SocialNetworkUser("User1"), new SocialNetworkUser("User2")));

    //TODO: SOLVE THIS!
    SocialNetworkUser user4("User4");
    socialNetwork->removeVertex(&user4);
    SocialNetworkUser user22("User2");
    Friendship friendship1(user4, user22);
    socialNetwork->removeEdge(&friendship1);
    socialNetwork->printFriendList();
    socialNetwork->shortestPath(new SocialNetworkUser("User2"), new SocialNetworkUser("User1"));
    return 0;
}