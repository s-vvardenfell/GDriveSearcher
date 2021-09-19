#include "beast_handler.hpp"

BeastHandler::BeastHandler():ctx(ssl::context::tlsv12_client), stream(ioc, ctx), resolver(ioc)
{
    ctx.set_verify_mode(ssl::context::verify_peer);
    ctx.set_default_verify_paths();
    boost::certify::enable_native_https_server_verification(ctx);
}

BeastHandler::~BeastHandler()
{
    // Gracefully close the stream
    beast::error_code ec;
    stream.shutdown(ec);
    if(ec == net::error::eof)
    {
        ec = {};
    }
//    if(ec)
    //        throw beast::system_error{ec};
}

void BeastHandler::post(string_view host, string_view target, string_view body, string_view port)
{
    if(! SSL_set_tlsext_host_name(stream.native_handle(), host.data()))
    {
        beast::error_code ec{static_cast<int>(::ERR_get_error()), net::error::get_ssl_category()};
        throw beast::system_error{ec};
    }

    auto const results = resolver.resolve(host, port);

    beast::get_lowest_layer(stream).connect(results);

    stream.handshake(ssl::stream_base::client);

    http::request<http::string_body> req{http::verb::post , target.data(), version_};
    req.set(http::field::host, host);
//    req.set(http::field::body, body);
    req.set(http::field::user_agent, "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:92.0) Gecko/20100101 Firefox/92.0");
//    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
    req.set(http::field::connection, "keep-alive");
    req.set(http::field::accept, "application/json, text/plain, */*");
    req.set(http::field::cache_control, "no-cache");
//    req.set(http::field::content_length, to_string(body.size()));
    req.set(http::field::content_type, "application/json");
    req.set(http::field::referer, "https://agregatoreat.ru/");
    req.set(http::field::pragma, "no-cache");
    req.set(http::field::host, "localhost");
    req.content_length(body.size());
    req.body() = body;

    req.set(http::field::proxy_connection, boost::asio::ip::address_v4::from_string("127.0.0.1"));


//    // Read just the header from the input
//      read_header(input, buffer, p, ec);

    http::write(stream, req);

    beast::flat_buffer buffer;

    http::response<http::dynamic_body> res;

    http::read(stream, buffer, res);

    std::cout << res << std::endl;
}

void BeastHandler::get(string_view host, string_view target, string_view port)
{
    // Set SNI Hostname (many hosts need this to handshake successfully)
    if(! SSL_set_tlsext_host_name(stream.native_handle(), host.data()))
    {
        beast::error_code ec{static_cast<int>(::ERR_get_error()), net::error::get_ssl_category()};
        throw beast::system_error{ec};
    }

    // Look up the domain name
    auto const results = resolver.resolve(host, port);

    // Make the connection on the IP address we get from a lookup
    beast::get_lowest_layer(stream).connect(results);

    // Perform the SSL handshake
    stream.handshake(ssl::stream_base::client);

    // Set up an HTTP GET request message
    http::request<http::string_body> req{http::verb::get, target.data(), version_};
    req.set(http::field::host, host);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    // Send the HTTP request to the remote host
    http::write(stream, req);

    // This buffer is used for reading and must be persisted
    beast::flat_buffer buffer;

    // Declare a container to hold the response
    http::response<http::dynamic_body> res;

    // Receive the HTTP response
    http::read(stream, buffer, res);

    // Write the message to standard out
    std::cout << res << std::endl;

}

string BeastHandler::getResponseBody() const
{
    return response_body_;
}

string BeastHandler::getResponseHeaders() const
{
    return response_headers_;
}
