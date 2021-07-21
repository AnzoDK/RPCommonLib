#pragma once
#include <iostream>

unsigned int Cstrlen(const char* c_str)
{
    unsigned int i = 0;
    while(static_cast<unsigned char>(c_str[i]) != 0x0)
    {
        i++;
    }
    return i;
}
