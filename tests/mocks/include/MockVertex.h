#ifndef TESTS_MOCKVERTEX_H
#define TESTS_MOCKVERTEX_H

#include <string>
#include "gmock/gmock.h"

class VertexInferface
{
public:
    virtual ~VertexInferface() = default;

protected:
    virtual std::string getLabel() const = 0;
    virtual void setLabel(std::string label) = 0;
};

class MockVertex final: public VertexInferface
{
public:
    ~MockVertex() override = default;
    MOCK_CONST_METHOD0(getLabel, std::string());
    MOCK_METHOD1(setLabel, void(std::string));
};


#endif //TESTS_MOCKVERTEX_H
