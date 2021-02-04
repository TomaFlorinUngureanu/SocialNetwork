#include "abstraction/Edge.h"

Edge::~Edge() = default;

bool Edge::operator==(Edge &edge)
{
    return (this->getVertex1()->getUsername() == edge.getVertex1()->getUsername() &&
            this->getVertex2()->getUsername() == edge.getVertex2()->getUsername()) ||
           (this->getVertex1()->getUsername() == edge.getVertex2()->getUsername() &&
                   this->getVertex2()->getUsername() == edge.getVertex1()->getUsername());
}
