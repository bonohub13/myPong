#include "../include/utils.hpp"

#include <sstream>

std::string GameUtils::int2str(int x)
{
    std::stringstream ss;

    ss << x;

    return ss.str( );
}

std::string GameUtils::int2str(int &x)
{
    std::stringstream ss;

    ss << x;

    return ss.str( );
}