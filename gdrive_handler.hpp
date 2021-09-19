#ifndef GDRIVEHANDLER_HPP
#define GDRIVEHANDLER_HPP

#include "nlohmann/json.hpp"

#include "curl_handler.hpp"
#include "utility.hpp"

using json = nlohmann::json;
using namespace std;

class GDriveHandler
{
public:
    GDriveHandler();

    json query(const string& keyword, const string other_data);

private:
    unique_ptr<CurlHandler> curl_;
};

#endif // GDRIVEHANDLER_HPP
