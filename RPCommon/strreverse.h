#pragma once
#include <iostream>
inline static std::string ReverseString(std::string s)
{
    std::string tmp = "";
    size_t len = s.length();
    for(size_t i = 0; i < len; i++)
    {
        tmp+=s.at(len-i-1);
    }
    return tmp;
}
