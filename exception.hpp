#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <string>
#include <stdexcept>

class Exception : public std::exception
{
protected:
    std::string msg_;

public:
    Exception(const char* msg) : msg_(msg) { }
    Exception(const std::string& msg) : msg_(msg) { }
    virtual ~Exception() noexcept { }

    virtual const char* what() const noexcept
    {
        return msg_.c_str();
    }

};

class CurlHandlerException : public Exception
{

public:
    CurlHandlerException(const char* msg) : Exception(msg) { }
    CurlHandlerException(const std::string& msg) : Exception(msg) { }
    virtual ~CurlHandlerException() { }

    virtual const char* what() const noexcept
    {
        return msg_.c_str();
    }

};

#endif // EXCEPTION_HPP
