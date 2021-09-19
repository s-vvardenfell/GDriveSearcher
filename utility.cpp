#include "utility.hpp"

namespace Utility
{
    const string loadDocument(const string& file_name)
    {
        ifstream ifile;
        ifile.open(file_name);

        if(!ifile)
        {
            qDebug() <<"Cannot open file: "<<file_name.c_str()<<Qt::endl;
            return "";
        }


        string doc, line;

        while(getline(ifile, line))
            doc+=line;

        return doc;
    }

    bool saveDocument(const std::string& filename, const std::string& data)
    {
        std::ofstream ofile(filename);
        if (!ofile) { qDebug() << "Cannot open file"<<Qt::endl; return false; }
        ofile << data;
        ofile.close();
        return true;

    }

    const std::string parseDataFromPage(const std::string& where, const std::string& lstr, const std::string& rstr, bool with_left)
    {
        size_t lpos{}, rpos{};
        std::string ret_val;

        if ((where.find(lstr) == std::string::npos) || (where.find(rstr) == std::string::npos))
        {
            qDebug()<<"No data to parse\n"<<Qt::endl;
            return "";
        }

        if (!with_left)
        {
            lpos = where.find(lstr);
            rpos = where.find(rstr, lpos);
            ret_val = where.substr(lpos + lstr.size(), rpos - lpos - lstr.size());
        }
        else
        {
            lpos = where.find(lstr);
            rpos = where.find(rstr, lpos);
            ret_val = where.substr(lpos, rpos - lpos);
        }

        while ((lpos = ret_val.find("\"")) != std::string::npos) ret_val.erase(lpos, 1);

        return ret_val;
    }

    const string getDateTime(const string& format)
    {
        std::time_t t = std::time(nullptr);
        std::tm tm = *std::localtime(&t);
        std::stringstream ss; ss<< put_time(&tm, format.c_str());
        return ss.str();
    }

    const string getHostFromUrl(const string &file)
    {
        std::string temp;
        temp = file.substr(file.find("//")+2);
        temp = temp.substr(0, temp.find("/"));

        return temp;
    }

}
