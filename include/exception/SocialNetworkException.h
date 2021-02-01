#ifndef SHORELINE_SOCIALNETWORKEXCEPTION_H
#define SHORELINE_SOCIALNETWORKEXCEPTION_H

#include <exception>

class SocialNetworkException : public std::exception
{
    [[nodiscard]] const char *what() const noexcept override
    {
        return "Cannot create edge to self!";
    }
};


#endif //SHORELINE_SOCIALNETWORKEXCEPTION_H