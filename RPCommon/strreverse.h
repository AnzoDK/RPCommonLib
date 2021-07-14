#include <iostream>
#pragma once
static std::string ReverseString(std::string s)
{
    std::string tmp = "";
    for(size_t i = 0; i < s.length(); i++)
    {
        tmp+=s.at(s.length()-i-1);
    }
    return tmp;
}
