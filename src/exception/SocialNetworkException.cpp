#include "exception/SocialNetworkException.h"

const char *EdgeToSelfException::what() const noexcept
{
    return "Cannot create edge to self!";
}

const char *VertexNullException::what() const noexcept
{
    return "Vertex is null!";
}

const char *EdgeNullException::what() const noexcept
{
    return "Edge is null!";
}

const char *UndirectedGraphException::what() const noexcept
{
    return "UndirectedGraph is null!";
}
