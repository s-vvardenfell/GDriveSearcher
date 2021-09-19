#include "gdrive_handler.hpp"

GDriveHandler::GDriveHandler() : curl_(nullptr)
{
    curl_ = make_unique<CurlHandler>();
}

json GDriveHandler::query(const string &keyword, const string other_data)
{
    string cse_tok = "AJvRUv3t6lJkz0i88B-xtzKANTVR:1631990628269";
    string gs_l = "partner-generic.3...101475.103271.1.103757.0.0.0.0.0.0.0.0..0.0.csems%2Cnrl%3D13...0.1926j510842j10...1.34.partner-generic..0.0.0.";
    string apinum = "14921";

    const string url = "https://cse.google.com/cse/element/v1?rsz=filtered_cse&num=10"
        "&hl=en&source=gcsc&gss=.com&cselibv=b54a745638da8bbb"
        "&cx=partner-pub-8443442485992789:ee4spwofmt8&q="
        + curl_->urlEncode(keyword) + "&safe=off&cse_tok=" + cse_tok + "&exp=csqr,cc&oq="
        + curl_->urlEncode(keyword) + "&gs_l=" + gs_l +
        "&callback=google.search.cse.api" + apinum;


    curl_->setHeader("User-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/93.0.4577.82 Safari/537.36");
    curl_->setHeader("Accept-Language", "en-US,en;q=0.9");
    curl_->setHeader("Accept", "*/*");
    curl_->setHeader("Connection", "keep-alive");
    curl_->setHeader("Host", "cse.google.com");

    curl_->query(url, methodType::GET);

    Utility::saveDocument("/home/chaginsergey/Downloads/response.txt", curl_->getResponse());
}
