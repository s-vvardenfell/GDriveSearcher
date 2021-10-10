#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include <string>

class Response
{
public:
    int code_{ 0 };
    std::string headers_{ "empty headers" };
    std::string body_{ "empty body" };
};

#endif // RESPONSE_HPP
