#pragma once
#include <iostream>

char __HexTable(unsigned char c)
{
    switch(c)
    {
        case 10:
        {
            return 'A';
        }
        case 11:
        {
            return 'B';
        }
        case 12:
        {
            return 'C';
        }
        case 13:
        {
            return 'D';
        }
        case 14:
        {
            return 'E';
        }
        case 15:
        {
            return 'F';
        }
        default:
        {
            return std::to_string(static_cast<int>(c)).at(0);
        }
    }
}

std::string GetHexFromTable(unsigned char b)
{
    std::string res = "";
    unsigned char tmp = b;
    tmp = (tmp >> 4);
    res += __HexTable(tmp);
    tmp = b & 0b00001111;
    res += __HexTable(tmp);
    return res;
    
}

void PrintBytes()
{
    
}

template <typename T>
std::string GetBytes(T* tArr, unsigned int arrLen)
{
    std::string res = "";
    unsigned int t_size = sizeof(T);
    unsigned int full_arr_size = t_size*arrLen;
    for(unsigned int i = 0; i < full_arr_size; i+=t_size)
    {
        for(unsigned int u = 0; u < t_size; u++)
        {
            //res += (unsigned char)(*(tArr+u+(i*t_size)));
            res += "0x";
            res += GetHexFromTable((unsigned char)(*(tArr+u+(i*t_size))));
        }
        if(i != full_arr_size-t_size)
        {
            res += " ";
        }
        
    }
    return res;
}
