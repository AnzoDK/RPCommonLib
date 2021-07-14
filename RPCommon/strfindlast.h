#pragma once
#include <iostream>
size_t StringFindLast(char c, std::string s)
{
    size_t tmp = 0;
    //Keep the length so we don't have to get it from the string every loop
    size_t len = s.length();
    for(size_t i = 0; i < s.length(); i++)
    {
        if(s.at(len-1-i) == c)
        {
            tmp = len-1-1;
            return tmp;
        }
    }
    return std::string::npos;
}
