#include "curl_handler.hpp"

CurlHandler::CurlHandler() :
    curl_(nullptr), headers_(nullptr), response_body_(), response_headers_(), lastCode_(0)
{
    curl_ = curl_easy_init();

//    if (!curl_)
//        throw std::runtime_error("Curl_handler::Curl_handler(): Cannot to init "
//            "curl object (function curl_easy_init()\n");

    curl_easy_setopt(curl_, CURLOPT_VERBOSE, verbose_);

    if (proxy_)
    {
        curl_easy_setopt(curl_, CURLOPT_PROXY, "5.101.86.170:8000");
        curl_easy_setopt(curl_, CURLOPT_PROXYUSERNAME, "tumuhR");
        curl_easy_setopt(curl_, CURLOPT_PROXYPASSWORD, "Jmr90N");
    }

    curl_easy_setopt(curl_, CURLOPT_SSL_VERIFYPEER, 0);
    curl_easy_setopt(curl_, CURLOPT_SSL_VERIFYHOST, 0);
    curl_easy_setopt(curl_, CURLOPT_AUTOREFERER, true);
    curl_easy_setopt(curl_, CURLOPT_FOLLOWLOCATION, true);

    curl_easy_setopt(curl_, CURLOPT_COOKIEFILE, "");
    curl_easy_setopt(curl_, CURLOPT_COOKIEJAR, "");

    curl_easy_setopt(curl_, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);

    //curl_easy_setopt(curl_, CURLOPT_POSTREDIR, CURL_REDIR_POST_301);
    curl_easy_setopt(curl_, CURLOPT_POSTREDIR, CURL_REDIR_POST_302);
    //curl_easy_setopt(curl_, CURLOPT_POSTREDIR, CURL_REDIR_POST_303);
    //curl_easy_setopt(curl_, CURLOPT_POSTREDIR, CURL_REDIR_POST_ALL);
}

CurlHandler::~CurlHandler()
{
    if (curl_) curl_easy_cleanup(curl_);
    if (headers_) curl_slist_free_all(headers_);
}

std::string CurlHandler::getHostFromURL(const std::string& url)
{
    std::string host = url;

    if (url.find("//") != std::string::npos)
        host = url.substr(url.find("//") + 2);

    if (host.find('/') != std::string::npos)
        host = host.substr(0, host.find('/'));

    return host;
}

int CurlHandler::query(const std::string& url, const methodType& method, const std::string& data, int port, bool ignoreCurlCode)
{

    std::string host = getHostFromURL(url);
    setHeader("Host", host);

    if (method == methodType::POST)
    {
        curl_easy_setopt(curl_, CURLOPT_HTTPGET, 0);
        curl_easy_setopt(curl_, CURLOPT_POST, 1);
        curl_easy_setopt(curl_, CURLOPT_POSTFIELDSIZE, data.size());
        curl_easy_setopt(curl_, CURLOPT_POSTFIELDS, data.c_str());

    }
    else if (method == methodType::GET)
    {
        curl_easy_setopt(curl_, CURLOPT_POST, 0);
        curl_easy_setopt(curl_, CURLOPT_HTTPGET, 1);
    }

    curl_easy_setopt(curl_, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl_, CURLOPT_PORT, port);

    response_body_.clear();
    response_headers_.clear();

    curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION, CurlHandler::writeDataToString);
    curl_easy_setopt(curl_, CURLOPT_WRITEDATA, &this->response_body_);
    curl_easy_setopt(curl_, CURLOPT_HEADERFUNCTION, CurlHandler::writeDataToString);
    curl_easy_setopt(curl_, CURLOPT_WRITEHEADER, &this->response_headers_);

    CURLcode result = curl_easy_perform(curl_);

    if (result != CURLE_OK && !ignoreCurlCode)
    {
        throw CurlHandlerException(std::string("Https::query(): ")
            + curl_easy_strerror(result));
    }

    curl_easy_getinfo(curl_, CURLINFO_RESPONSE_CODE, &this->lastCode_);

    return this->lastCode_;
}

const std::string CurlHandler::getResponse() const
{
    return response_body_;
}

const std::string CurlHandler::getResponseHeaders() const
{
    return response_headers_;
}

const std::string CurlHandler::getLastEffectiveURL() const
{
    char* url = nullptr;
    curl_easy_getinfo(curl_, CURLINFO_EFFECTIVE_URL, &url);

    if (!url) return "";

    return url;
}

int CurlHandler::getLastCode() const
{
    return this->lastCode_;
}

void CurlHandler::findAndDeleteHeader(const std::string& type)
{
    struct curl_slist* current = headers_;
    struct curl_slist* prev = nullptr;
    std::string currentType;

    while (current)
    {
        currentType = current->data;
        currentType = currentType.substr(0, currentType.find(':'));

        if (currentType == type) {

            if (prev) prev->next = current->next;
            else headers_ = current->next;

            break;

        }

        prev = current;
        current = current->next;
    }
}

void CurlHandler::setHeader(const std::string& type, const std::string& value)
{
    findAndDeleteHeader(type);
    headers_ = curl_slist_append(headers_, (type + ": " + value).c_str());
    curl_easy_setopt(curl_, CURLOPT_HTTPHEADER, headers_);
}

void CurlHandler::setMaxRedirects(int16_t count)
{
    curl_easy_setopt(curl_, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl_, CURLOPT_MAXREDIRS, count);
}

const std::string CurlHandler::urlEncode(const std::string data)
{
    std::string result;
    char* escText = curl_easy_escape(curl_, data.c_str(), static_cast<int>(data.length()));
//    if (!escText) throw std::runtime_error("Http::URLencode(): Cannot URL encode\n");

    result = escText;
    curl_free(escText);

    return result;
}

void CurlHandler::setCookie(const std::string& value)
{
    curl_easy_setopt(curl_, CURLOPT_COOKIE, value.c_str());
}


size_t CurlHandler::writeDataToStream(char* ptr, std::size_t sz, std::size_t nmemb, std::ostream* stream)
{
    (*stream) << std::string(ptr, sz * nmemb);
    return sz * nmemb;
}

size_t CurlHandler::writeDataToString(char* ptr, size_t sz, size_t nmemb, std::string* buffer)
{
    if (buffer)
    {
        buffer->append(ptr, sz * nmemb);
        return sz * nmemb;
    }
    else return 0;
}














