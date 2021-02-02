#include "abstraction/Edge.h"

Edge::~Edge() = default;

bool Edge::operator==(Edge &edge)
{
    return (this->getUser1()->getUsername() == edge.getUser1()->getUsername() &&
            this->getUser2()->getUsername() == edge.getUser2()->getUsername()) ||
           (this->getUser1()->getUsername() == edge.getUser2()->getUsername() &&
            this->getUser2()->getUsername() == edge.getUser1()->getUsername());
}
