#pragma once
#include <iostream>
size_t StringFindLast(char c, std::string s)
{
    size_t tmp = 0;
    //Keep the length so we don't have to get it from the string every loop
    size_t len = s.length();
    for(size_t i = 0; i < len; i++)
    {
        if(s.at(len-1-i) == c)
        {
            tmp = len-i-1;
            return tmp;
        }
    }
    return std::string::npos;
}
size_t StringFindLast(std::string search, std::string s)
{
    size_t tmp = 0;
    //Keep the length so we don't have to get it from the string every loop
    size_t len = s.length();
    size_t searchLen = search.length();
    for(size_t i = 0; i < len-searchLen; i++)
    {
        if(s.substr(len-i-1-searchLen,searchLen) == search)
        {
            tmp = len-i-1-searchLen;
            return tmp;
        }
    }
    return std::string::npos;
}
