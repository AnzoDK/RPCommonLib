#pragma once
#include <iostream>
#include <cctype>
#include <algorithm>
static std::string ToUpperCase(std::string data)
{
    std::transform(data.begin(), data.end(), data.begin(),
    [](unsigned char c){ return std::toupper(c); });
	return data;
}

static std::string ToLowerCase(std::string data)
{
    std::transform(data.begin(), data.end(), data.begin(),
    [](unsigned char c){ return std::tolower(c); });
	return data;
}


