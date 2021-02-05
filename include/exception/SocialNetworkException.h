#ifndef SOCIAL_NETWORK_EXCEPTION_H
#define SOCIAL_NETWORK_EXCEPTION_H

#include <exception>

class EdgeToSelfException : public std::exception
{
public:
    [[nodiscard]] const char *what() const noexcept override;
};

class VertexNullException: public std::exception
{
public:
    [[nodiscard]] const char *what() const noexcept override;
};

class EdgeNullException: public std::exception
{
public:
    [[nodiscard]] const char *what() const noexcept override;
};

class UndirectedGraphException: public std::exception
{
public :
    [[nodiscard]] const char *what() const noexcept override;
};


#endif //SOCIAL_NETWORK_EXCEPTION_H