// include project classes
#include "SocialNetwork.h"

// include mocks
#include "MockSocialNetwork.h"

// include GTest & Gmock
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::StrictMock;

class SocialNetworkTest: public ::testing::Test
{
public:
    StrictMock<MockSocialNetwork> socialNetworkMock;
    std::string username{"User"};
};

/**
 * @test ADD_VERTEX_TC_1
 * Testing the adding of a vertex type with a pointer which is nullptr
 */
TEST_F(SocialNetworkTest, ADD_VERTEX_TC_1)
{
    SocialNetwork socialNetwork{};
    socialNetwork.addVertex(nullptr);
}

/**
 * @test ADD_VERTEX_TC_2
 * Testing the adding of a vertex type with pointer
 */
TEST_F(SocialNetworkTest, ADD_VERTEX_TC_2)
{
    SocialNetwork socialNetwork{};
    socialNetwork.addVertex(new SocialNetworkUser(username));
}

/**
 * @test ADD_VERTEX_TC_3
 * Testing the adding of a vertex with smart pointer
 */
TEST_F(SocialNetworkTest, ADD_VERTEX_TC_3)
{
    SocialNetwork socialNetwork{};
    std::shared_ptr<Vertex> vertex{new SocialNetworkUser(username)};

    socialNetwork.addVertex(vertex);
}

/**
 * @test ADD_VERTEX_TC_4
 * Trying to add the same element twice. No edges are present in the graph.
 * The size of the vector of vertices shall remain the same as after the first addition call.
 */
TEST_F(SocialNetworkTest, ADD_VERTEX_TC_4)
{
    SocialNetwork socialNetwork{};
    std::shared_ptr<Vertex> vertex{new SocialNetworkUser(username)};
    socialNetwork.addVertex(vertex);

    SocialNetworkUser user{username};
    socialNetwork.addVertex(&user);
}

/**
 * @test REMOVE_VERTEX_TC_1
 * Testing the removal of a vertex with a pointer which is nullptr.
 */
TEST_F(SocialNetworkTest, REMOVE_VERTEX_TC_1)
{
    SocialNetwork socialNetwork{};
    socialNetwork.removeVertex(nullptr);
}

/**
 * @test REMOVE_VERTEX_TC_2
 * Testing the removal of a vertex with raw pointer. No edges are present in the graph.
 */
TEST_F(SocialNetworkTest, REMOVE_VERTEX_TC_2)
{
    SocialNetwork socialNetwork{};
    std::shared_ptr<Vertex> vertex{new SocialNetworkUser(username)};

    socialNetwork.addVertex(vertex);
    socialNetwork.removeVertex(new SocialNetworkUser(username));
}

/**
 * @test REMOVE_VERTEX_TC_3
 * Testing the removal of a vertex with a smart pointer. No edges are present in the graph.
 */
TEST_F(SocialNetworkTest, REMOVE_VERTEX_TC_3)
{
    SocialNetwork socialNetwork{};
    std::shared_ptr<Vertex> vertex{new SocialNetworkUser(username)};

    socialNetwork.addVertex(vertex);
    socialNetwork.removeVertex(std::shared_ptr<Vertex>(new SocialNetworkUser(username)));
}

/**
 * @test REMOVE_VERTEX_TC_4
 * Testing the removal of a vertex with a reference. No edges are present in the graph.
 */
TEST_F(SocialNetworkTest, REMOVE_VERTEX_TC_4)
{
    SocialNetwork socialNetwork{};
    SocialNetworkUser user{username};
    std::shared_ptr<Vertex> vertex{new SocialNetworkUser(username)};

    socialNetwork.addVertex(vertex);
    socialNetwork.removeVertex(&user);
}

/**
 * @test REMOVE_VERTEX_TC_5
 * Try to delete the same element twice. No edges are present in the graph.
 * The size of the vector of vertices shall remain the same after the first deletion call.
 */
TEST_F(SocialNetworkTest, REMOVE_VERTEX_TC_5)
{
    SocialNetwork socialNetwork{};
    SocialNetworkUser user{username};
    std::shared_ptr<Vertex> vertex{&user};
    socialNetwork.addVertex(vertex);

    socialNetwork.removeVertex(std::shared_ptr<Vertex>(new SocialNetworkUser(username)));
    socialNetwork.removeVertex(std::shared_ptr<Vertex>(new SocialNetworkUser(username)));
}

/**
 * @test REMOVE_VERTEX_TC_6
 * Try to delete a vertex with one connection to another vertex.
 * The size of the vector of vertices shall decrease with 1. The size of the vector of edges shall decrease with 1.
 * The adjacency list size of the vertex should decrease with 1.
 */
TEST_F(SocialNetworkTest, REMOVE_VERTEX_TC_6)
{

}

/**
 * @test REMOVE_VERTEX_TC_7
 * Try to delete a vertex with 2 connections to other vertices.
 * The size of the vector of vertices shall decrease with 1. The size of the vector of edges shall decrease with 2.
 * The adjacency list size of the vertex should decrease with 2.
 */
TEST_F(SocialNetworkTest, REMOVE_VERTEX_TC_7)
{

}

/**
 * @test ADD_EDGE_TC1
 * Add an edge which is nullptr.
 */
TEST_F(SocialNetworkTest, ADD_EDGE_TC1)
{

}

/**
 * @test ADD_EDGE_TC2
 * Add an edge from a vertex to itself. The number of edges should not increase
 */
TEST_F(SocialNetworkTest, ADD_EDGE_TC2)
{

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

}

/**
 * @test ADD_EDGE_TC4
 * Add an edge from a vertex A to one that IS present in the graph (B). The number of edges should increase with 1.
 * The vertices list size should not increase.
 * The edges list size should increase with 1.
 * The adjacency list size of vertex A should increase with 1 (addition of vertex B).
 * The adjacency list size of vertex B should increase with 1 (addition of vertex A).
 */
TEST_F(SocialNetworkTest, ADD_EDGE_TC4)
{

}

/**
 * @test REMOVE_EDGE_TC1
 * Remove an edge which is nullptr.
 */
TEST_F(SocialNetworkTest, REMOVE_EDGE_TC1)
{

}

/**
 * @test REMOVE_EDGE_TC2
 * Remove an edge which is not present in the graph. The number of edges should not decrease
 */
TEST_F(SocialNetworkTest, REMOVE_EDGE_TC2)
{

}

/**
 * @test REMOVE_EDGE_TC3
 * Remove an edge which is present in the graph. The number of edges should decrease with 1
 */
TEST_F(SocialNetworkTest, REMOVE_EDGE_TC3)
{

}

/**
 * @test SHORTEST_PATH_TC1
 * Shortest path in graph with only one vertex
 */
TEST_F(SocialNetworkTest, SHORTEST_PATH_TC1)
{

}

/**
 * @test SHORTEST_PATH_TC2
 * Shortest path in an empty graph.
 */
TEST_F(SocialNetworkTest, SHORTEST_PATH_TC2)
{

}

/**
 * @test SHORTEST_PATH_TC3
 * Shortest path between two vertices that are not connected.
 */
TEST_F(SocialNetworkTest, SHORTEST_PATH_TC3)
{

}

/**
 * @test SHORTEST_PATH_TC4
 * Shortest path between 2 adjacent vertices
 */
TEST_F(SocialNetworkTest, SHORTEST_PATH_TC4)
{

}

/**
 * @test SHORTEST_PATH_TC5
 * Shortest path between 2 vertices with distance >= 2
 */
TEST_F(SocialNetworkTest, SHORTEST_PATH_TC5)
{

}
