#pragma once
#include <iostream>
#include "strlen.h"
#include "strreverse.h"
inline void Eat(const char* cs)
{
    std::string s = std::string(cs);
    size_t len = Cstrlen(cs);
    if(len > 0)
    {
        s = ReverseString(s);
        s.erase(s.begin()+s.size()-1);
        s = ReverseString(s);
    }
    cs = s.c_str();
    
}

inline void Eat(std::string &s)
{
    if(s.size() > 0)
    {
        s = ReverseString(s);
        s.erase(s.begin()+s.size()-1);
        s = ReverseString(s);
        
    }
}
