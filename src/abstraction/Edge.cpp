#include "abstraction/Edge.h"

Edge::~Edge() = default;

bool Edge::operator==(Edge &edge)
{
    return (this->getVertex1()->getLabel() == edge.getVertex1()->getLabel() &&
            this->getVertex2()->getLabel() == edge.getVertex2()->getLabel()) ||
           (this->getVertex1()->getLabel() == edge.getVertex2()->getLabel() &&
                   this->getVertex2()->getLabel() == edge.getVertex1()->getLabel());
}
