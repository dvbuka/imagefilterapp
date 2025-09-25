#include "utils.hpp"
#include <algorithm>

using namespace std;
string tolower(string str)
{
    string ret = str;
    transform(str.begin(), str.end(), ret.begin(), [](unsigned char c)
              { return std::tolower(c); });
    return ret;
}

bool isnumber(const std::string &str)
{
    if (str.empty())
    {
        return false;
    }
    bool dot = false;
    for (char c : str)
    {
        if (c == '.' && !dot)
        {
            dot = true;
            continue;
        }
        if (!std::isdigit(c))
        {
            return false;
        }
    }
    return true;
}