// include project classes
#include <exception/SocialNetworkException.h>
#include "SocialNetwork.h"

// include mocks
#include "MockSocialNetworkUser.h"
#include "MockFriendship.h"

// include GTest & Gmock
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::StrictMock;
using ::testing::Return;
using ::testing::InSequence;
using ::testing::_;

class SocialNetworkTest: public ::testing::Test
{
public:
    StrictMock<MockFriendship> frMock;
    StrictMock<MockSocialNetworkUser> snuMock;
    std::string genericUsername{"User"};
};

/**
 * @test ADD_VERTEX_TC_1
 * Testing the adding of a vertex type with a pointer which is nullptr
 */
TEST_F(SocialNetworkTest, ADD_VERTEX_TC_1)
{
    try
    {
        // variable declarations and initializations
        SocialNetwork socialNetwork{};

        // function under test
        socialNetwork.addVertex(nullptr);
    }
    catch (const VertexNullException& exception)
    {
        EXPECT_STREQ(exception.what(), "Vertex is null!");
    }
}

/**
 * @test ADD_VERTEX_TC_2
 * Testing the adding of a vertex type with a raw pointer
 */
TEST_F(SocialNetworkTest, ADD_VERTEX_TC_2)
{
    // variable declarations and initializations
    SocialNetwork socialNetwork{};

    // expectations
    EXPECT_CALL(snuMock, getLabel()).WillOnce(Return(genericUsername));

    // function under test
    socialNetwork.addVertex(new SocialNetworkUser(genericUsername));
}

/**
 * @test ADD_VERTEX_TC_3
 * Testing the adding of a vertex with smart pointer
 */
TEST_F(SocialNetworkTest, ADD_VERTEX_TC_3)
{
    SocialNetwork socialNetwork{};
    std::shared_ptr<Vertex> vertex{new SocialNetworkUser(genericUsername)};

    // expectations
    EXPECT_CALL(snuMock, getLabel()).WillOnce(Return(genericUsername));

    // function under test
    socialNetwork.addVertex(vertex);
}

/**
 * @test ADD_VERTEX_TC_4
 * Trying to add the same element twice. No edges are present in the graph.
 * The size of the vector of vertices shall remain the same as after the first addition call.
 */
TEST_F(SocialNetworkTest, ADD_VERTEX_TC_4)
{
    // variable declarations and initializations
    SocialNetwork socialNetwork{};
    std::shared_ptr<Vertex> vertex{new SocialNetworkUser(genericUsername)};
    SocialNetworkUser user{genericUsername};

    // expectations
    EXPECT_CALL(snuMock, getLabel()).Times(3).WillRepeatedly(Return(genericUsername));

    // prerequisites
    socialNetwork.addVertex(vertex);
    unsigned int numberOfVertices = socialNetwork.getVertices().size();
    
    // function under test
    socialNetwork.addVertex(&user);

    EXPECT_EQ(socialNetwork.getVertices().size(), numberOfVertices);
}

/**
 * @test REMOVE_VERTEX_TC_1
 * Testing the removal of a vertex with a pointer which is nullptr.
 */
TEST_F(SocialNetworkTest, REMOVE_VERTEX_TC_1)
{
    try
    {
        // variable declarations and initializations
        SocialNetwork socialNetwork{};

        // function under test
        socialNetwork.removeVertex(nullptr);
    }
    catch (const VertexNullException& exception)
    {
        EXPECT_STREQ(exception.what(), "Vertex is null!");
    }
}

/**
 * @test REMOVE_VERTEX_TC_2
 * Testing the removal of a vertex with raw pointer. No edges are present in the graph.
 */
TEST_F(SocialNetworkTest, REMOVE_VERTEX_TC_2)
{
    // variable declarations and initializations
    SocialNetwork socialNetwork{};
    std::shared_ptr<Vertex> vertex{new SocialNetworkUser(genericUsername)};

    // expectations
    EXPECT_CALL(snuMock, getLabel()).Times(8).WillRepeatedly(Return(genericUsername));

    InSequence seq;
    // prerequisites
    socialNetwork.addVertex(vertex);
    unsigned int numberOfVertices = socialNetwork.getVertices().size();

    // function under test
    socialNetwork.removeVertex(new SocialNetworkUser(genericUsername));

    // postconditions
    EXPECT_EQ(socialNetwork.getVertices().size(), numberOfVertices - 1);
}

/**
 * @test REMOVE_VERTEX_TC_3
 * Testing the removal of a vertex with a smart pointer. No edges are present in the graph.
 */
TEST_F(SocialNetworkTest, REMOVE_VERTEX_TC_3)
{
    // variable declarations and initializations
    SocialNetwork socialNetwork{};
    std::shared_ptr<Vertex> vertex{new SocialNetworkUser(genericUsername)};

    // expectations
    EXPECT_CALL(snuMock, getLabel()).Times(8).WillRepeatedly(Return(genericUsername));

    InSequence seq;
    // prerequisites
    socialNetwork.addVertex(vertex);
    unsigned int numberOfVertices = socialNetwork.getVertices().size();
    
    // function under test
    socialNetwork.removeVertex(std::shared_ptr<Vertex>(new SocialNetworkUser(genericUsername)));

    // postconditions
    EXPECT_EQ(socialNetwork.getVertices().size(), numberOfVertices - 1);
}

/**
 * @test REMOVE_VERTEX_TC_5
 * Try to delete the same element twice. No edges are present in the graph.
 * The size of the vector of vertices shall remain the same after the first deletion call.
 */
TEST_F(SocialNetworkTest, REMOVE_VERTEX_TC_5)
{
    // variable declarations and initializations
    SocialNetwork socialNetwork{};
    std::shared_ptr<Vertex> vertex{new SocialNetworkUser(genericUsername)};

    InSequence seq;
    // expectations
    EXPECT_CALL(snuMock, getLabel()).Times(11).WillRepeatedly(Return(genericUsername));

    // prerequisites
    socialNetwork.addVertex(vertex);
    unsigned int numberOfVertices = socialNetwork.getVertices().size();
    socialNetwork.removeVertex(std::shared_ptr<Vertex>(new SocialNetworkUser(genericUsername)));
    
    // function under test
    socialNetwork.removeVertex(std::shared_ptr<Vertex>(new SocialNetworkUser(genericUsername)));

    // postconditions
    EXPECT_EQ(socialNetwork.getVertices().size(), numberOfVertices - 1);
}

/**
 * @test REMOVE_VERTEX_TC_6
 * Try to delete a vertex with one connection to another vertex.
 * The size of the vector of vertices shall decrease with 1. The size of the vector of edges shall decrease with 1.
 * The adjacency list size of the vertex should decrease with 1.
 */
TEST_F(SocialNetworkTest, REMOVE_VERTEX_TC_6)
{
    // variable declarations and initializations
    SocialNetwork socialNetwork;
    std::string username{"User"};
    std::string username1{"User1"};
    std::shared_ptr<Vertex> v1{new SocialNetworkUser(username)};
    std::shared_ptr<Vertex>v2{new SocialNetworkUser(username1)};

    // expectations
    EXPECT_CALL(snuMock, getLabel()).Times(4)
    .WillOnce(Return(username))
    .WillOnce(Return(username1))
    .WillOnce(Return(username))
    .WillOnce(Return(username1));
    socialNetwork.addVertex(v1);
    socialNetwork.addVertex(v2);

    EXPECT_CALL(frMock, getVertex1()).WillRepeatedly(Return(v1));
    EXPECT_CALL(frMock, getVertex2()).WillRepeatedly(Return(v2));
    EXPECT_CALL(snuMock, getLabel()).WillRepeatedly(Return(username));
    EXPECT_CALL(snuMock, getLabel()).WillRepeatedly(Return(username1));

    unsigned int numberOfVertices = socialNetwork.getVertices().size();
    socialNetwork.addEdge(v1, v2);
    unsigned int numberOfEdges = socialNetwork.getEdges().size();

    // function under test
    socialNetwork.removeVertex(v1);

    // postconditions
    EXPECT_EQ(socialNetwork.getVertices().size(), numberOfVertices - 1);
    EXPECT_EQ(socialNetwork.getEdges().size(), numberOfEdges - 1);
}

/**
 * @test REMOVE_VERTEX_TC_7
 * Try to delete a vertex with 2 connections to other vertices.
 * The size of the vector of vertices shall decrease with 1. The size of the vector of edges shall decrease with 2.
 * The adjacency list size of the vertex should decrease with 2.
 */
TEST_F(SocialNetworkTest, REMOVE_VERTEX_TC_7)
{
    // variable declarations and initializations
    SocialNetwork socialNetwork;
    std::shared_ptr<Vertex>v1 = std::make_shared<SocialNetworkUser>(SocialNetworkUser("User"));
    std::shared_ptr<Vertex>v2 = std::make_shared<SocialNetworkUser>(SocialNetworkUser("User1"));
    std::shared_ptr<Vertex>v3 = std::make_shared<SocialNetworkUser>(SocialNetworkUser("User2"));

    // prerequisites
    socialNetwork.addVertex(v1);
    socialNetwork.addVertex(v2);
    socialNetwork.addEdge(v1, v2);
    socialNetwork.addEdge(v1, v3);

    // function under test
    socialNetwork.removeVertex(v1);
}

/**
 * @test ADD_EDGE_TC1
 * Add an edge which is nullptr.
 */
TEST_F(SocialNetworkTest, ADD_EDGE_TC1)
{
    // variable declarations and initializations
    SocialNetwork socialNetwork;

    // function under test
    socialNetwork.addEdge(nullptr);
}

/**
 * @test ADD_EDGE_TC2
 * Add an edge from a vertex to a vertex with the same genericUsername. The number of edges should not increase
 * The number of vertices should not increase
 */
TEST_F(SocialNetworkTest, ADD_EDGE_TC2)
{
    // variable declarations and initializations
    SocialNetwork socialNetwork;
    Vertex* v1 = new SocialNetworkUser(genericUsername);
    Vertex* v2 = new SocialNetworkUser(genericUsername);

    // prerequisites
    socialNetwork.addVertex(v1);
    
    // function under test
    socialNetwork.addEdge(v1, v2);
}

/**
 * @test ADD_EDGE_TC3
 * Add an edge from a vertex A to one that is not present in the graph (B). The number of edges should increase with 1.
 * The vertices list size should increase with 1.
 * The edges list size should increase with 1.
 * The adjacency list size of vertex A should increase with 1 (addition of vertex B).
 * The adjacency list of vertex B should be created and will have 1 element, vertex A.
 */
TEST_F(SocialNetworkTest, ADD_EDGE_TC3)
{
    // variable declarations and initializations
    SocialNetwork socialNetwork;
    Vertex* v1 = new SocialNetworkUser("UserA");
    Vertex* v2 = new SocialNetworkUser("UserB");

    // prerequisites
    socialNetwork.addVertex(v1);

    // function under test
    socialNetwork.addEdge(v1, v2);
}

/**
 * @test ADD_EDGE_TC4
 * Add an edge from two vertices A and B which are present in the graph. The number of edges should increase with 1.
 * The vertices list size should not increase.
 * The edges list size should increase with 1.
 * The adjacency list size of vertex A should increase with 1 (addition of vertex B).
 * The adjacency list size of vertex B should increase with 1 (addition of vertex A).
 */
TEST_F(SocialNetworkTest, ADD_EDGE_TC4)
{
    // variable declarations and initializations
    SocialNetwork socialNetwork;
    Vertex* v1 = new SocialNetworkUser("UserA");
    Vertex* v2 = new SocialNetworkUser("UserB");

    // prerequisites
    socialNetwork.addVertex(v1);
    socialNetwork.addVertex(v2);

    // function under test
    socialNetwork.addEdge(v1, v2);
}

/**
 * @test REMOVE_EDGE_TC1
 * Remove an edge which is nullptr.
 */
TEST_F(SocialNetworkTest, REMOVE_EDGE_TC1)
{
    // variable declarations and initializations
    SocialNetwork socialNetwork;

    // function under test
    socialNetwork.removeVertex(nullptr);
}

/**
 * @test REMOVE_EDGE_TC2
 * Remove an edge which is not present in the graph. The number of edges should not decrease
 */
TEST_F(SocialNetworkTest, REMOVE_EDGE_TC2)
{
    // variable declarations and initializations
    SocialNetwork socialNetwork;
    Vertex* v1 = new SocialNetworkUser("UserA");
    Vertex* v2 = new SocialNetworkUser("UserB");

    // prerequisites
    socialNetwork.addVertex(v1);
    socialNetwork.addVertex(v2);
    socialNetwork.addEdge(new Friendship(v2, v1));

    // function under test
    socialNetwork.removeEdge(new Friendship(new SocialNetworkUser("UserB"), new SocialNetworkUser("UserC")));
}

/**
 * @test REMOVE_EDGE_TC3
 * Remove an edge which is present in the graph. The number of edges should decrease with 1
 */
TEST_F(SocialNetworkTest, REMOVE_EDGE_TC3)
{
    // variable declarations and initializations
    SocialNetwork socialNetwork;
    Vertex* v1 = new SocialNetworkUser("UserA");
    Vertex* v2 = new SocialNetworkUser("UserB");

    // prerequisites
    socialNetwork.addVertex(v1);
    socialNetwork.addVertex(v2);
    socialNetwork.addEdge(v1, v2);

    // function under test
    std::shared_ptr<Friendship> fr = std::make_shared<Friendship>();
    fr->setVertex(v1, false);
    fr->setVertex(v2, true);
    socialNetwork.removeEdge(fr);
}

/**
 * @test SHORTEST_PATH_TC1
 * Shortest path in graph with only one vertex
 */
TEST_F(SocialNetworkTest, SHORTEST_PATH_TC1)
{
    // variable declarations and initializations

    // function under test
}

/**
 * @test SHORTEST_PATH_TC2
 * Shortest path in an empty graph.
 */
TEST_F(SocialNetworkTest, SHORTEST_PATH_TC2)
{
    // variable declarations and initializations

    // function under test
}

/**
 * @test SHORTEST_PATH_TC3
 * Shortest path between two vertices that are not connected.
 */
TEST_F(SocialNetworkTest, SHORTEST_PATH_TC3)
{

    // variable declarations and initializations

    // function under test
}

/**
 * @test SHORTEST_PATH_TC4
 * Shortest path between 2 adjacent vertices
 */
TEST_F(SocialNetworkTest, SHORTEST_PATH_TC4)
{

    // variable declarations and initializations

    // function under test
}

/**
 * @test SHORTEST_PATH_TC5
 * Shortest path between 2 vertices with distance >= 2
 */
TEST_F(SocialNetworkTest, SHORTEST_PATH_TC5)
{
    // variable declarations and initializations

    // function under test
}
