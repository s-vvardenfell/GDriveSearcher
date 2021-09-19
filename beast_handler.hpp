#ifndef BEASTHANDLER_HPP
#define BEASTHANDLER_HPP

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/error.hpp>
#include <boost/asio/ssl/stream.hpp>

#include <cstdlib>
#include <iostream>
#include <string>

#include <boost/certify/extensions.hpp>
#include <boost/certify/https_verification.hpp>

namespace beast = boost::beast; // from <boost/beast.hpp>
namespace http = beast::http;   // from <boost/beast/http.hpp>
namespace net = boost::asio;    // from <boost/asio.hpp>
namespace ssl = net::ssl;       // from <boost/asio/ssl.hpp>
using tcp = net::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

using namespace std;

class BeastHandler
{
public:
    BeastHandler();
    ~BeastHandler();

    void post(string_view host, string_view target, string_view body = "", string_view port = "443");
    void get(string_view host, string_view target, string_view port = "443");

    string getResponseBody() const;
    string getResponseHeaders() const;

private:
    ssl::context ctx;
    net::io_context ioc;
    beast::ssl_stream<beast::tcp_stream> stream;
    tcp::resolver resolver;
    const int version_ = 11;

    void StoreResponse(beast::ssl_stream<beast::tcp_stream> stream);

    string response_headers_;
    string response_body_;
};

#endif // BEASTHANDLER_HPP
