#ifndef SOCIALNETWORKEXCEPTION_H
#define SOCIALNETWORKEXCEPTION_H

#include <exception>

class EdgeToSelfException : public std::exception
{
public:
    [[nodiscard]] const char *what() const noexcept override
    {
        return "Cannot create edge to self!";
    }
};

class VertexNullException: public std::exception
{
public:
    [[nodiscard]] const char *what() const noexcept override
    {
        return "Vertex is null!";
    }
};

class EdgeNullException: public std::exception
{
public:
    [[nodiscard]] const char *what() const noexcept override
    {
        return "Edge is null!";
    }
};


#endif //SOCIALNETWORKEXCEPTION_H