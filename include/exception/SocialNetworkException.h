#ifndef SOCIALNETWORKEXCEPTION_H
#define SOCIALNETWORKEXCEPTION_H

#include <exception>

class SocialNetworkException : public std::exception
{
    [[nodiscard]] const char *what() const noexcept override
    {
        return "Cannot create edge to self!";
    }
};


#endif //SOCIALNETWORKEXCEPTION_H