#ifndef UTILITY_H
#define UTILITY_H


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include <QDebug>

#include "exception.hpp"

using namespace std;

namespace Utility
{
    const string loadDocument(const string& file_name);

    bool saveDocument(const std::string& filename, const std::string& data);

    const std::string parseDataFromPage(const std::string& where, const std::string& lstr, const std::string& rstr, bool with_left);

    const std::string getDateTime(const string& format = "%d.%m.%Y %T");

    const std::string getHostFromUrl(const std::string& file);
}

#endif // UTILITY_H
