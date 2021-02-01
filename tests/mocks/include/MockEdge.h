#ifndef TESTS_MOCKEDGE_H
#define TESTS_MOCKEDGE_H

#include "abstraction/Vertex.h"
#include "gmock/gmock.h"

class EdgeInterface
{
public:
    virtual ~EdgeInterface() = default;

protected:
    virtual Vertex getVertex1() const = 0;
    virtual Vertex getVertex2() const = 0;
    virtual void setVertex(const Vertex &vertex, bool position) = 0;
};


class MockEdge : public EdgeInterface
{
public:
    ~MockEdge() override = default;
    MOCK_CONST_METHOD0(getVertex1, Vertex());
    MOCK_CONST_METHOD0(getVertex2, Vertex());
    MOCK_METHOD2(setVertex, void(const Vertex &vertex, bool position));
};

#endif //TESTS_MOCKEDGE_H
