#ifndef CURL_HANDLER_H
#define CURL_HANDLER_H

#include <string>
#include <exception>

#include <curl/curl.h>

#include "exception.hpp"

enum class methodType
{
    GET = 0,
    POST
};

class CurlHandler
{

private:
    CURL* curl_;
    struct curl_slist* headers_;
    std::string response_body_;
    std::string response_headers_;
    int lastCode_;

    bool proxy_ = false;
    bool verbose_ = true;

    static size_t writeDataToStream(char* ptr, std::size_t sz, std::size_t nmemb, std::ostream* stream);
    static size_t writeDataToString(char* ptr, size_t sz, size_t nmemb, std::string* buffer);

public:
    CurlHandler();
    CurlHandler(const CurlHandler& http) = delete;
    CurlHandler& operator=(const CurlHandler& http) = delete;
    ~CurlHandler();

    const std::string getResponse() const;
    const std::string getResponseHeaders() const;
    const std::string getLastEffectiveURL() const;

    std::string getHostFromURL(const std::string& url);
    int getLastCode() const;
    CURL* getCurlObject() { return curl_; }

    void setCookie(const std::string& value);
    void setMaxRedirects(int16_t count);
    void setHeader(const std::string& type, const std::string& value);

    void findAndDeleteHeader(const std::string& type);
    const std::string urlEncode(const std::string url);

    int query(const std::string& url, const methodType& method = methodType::GET,
              const std::string& data = "", int port = 443, bool ignoreCurlCode = 0);

};

#endif // CURL_HANDLER_H
