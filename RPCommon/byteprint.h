#pragma once
#include <iostream>
#include <vector>
inline char __HexTable(unsigned char c)
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

inline std::string GetHexFromTable(unsigned char b)
{
    std::string res = "";
    unsigned char tmp = b;
    tmp = (tmp >> 4);
    res += __HexTable(tmp);
    tmp = b & 0b00001111;
    res += __HexTable(tmp);
    return res;
    
}

inline void PrintBytes()
{
    
}


template <typename T>
inline std::string GetBytes(T* tArr, unsigned int arrLen)
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
            if(u != t_size-1)
            {
                res += " ";
            }
        }
        if(i != full_arr_size-t_size)
        {
            res += " ";
        }
        
    }
    return res;
}
//Vectors made me do this..... Blame them, not me XD
//Get Object at memaddress and print it's hex values
template <typename T>
inline std::string GetBytes(size_t address, unsigned int arrLen, bool showObjs=false)
{
    std::string res = "";
    unsigned int t_size = sizeof(T);
    unsigned int full_arr_size = t_size*arrLen;
    for(unsigned int i = 0; i < full_arr_size; i+=t_size)
    {
        if(showObjs)
        {
            res+= "Obj {";
        }
        for(unsigned int u = 0; u < t_size; u++)
        {
            //res += (unsigned char)(*(tArr+u+(i*t_size)));
            res += "0x";
            res += GetHexFromTable(*(reinterpret_cast<uint8_t*>(address)+u+(i*t_size))); //Fuck this line >:(
            if(u != t_size-1)
            {
                res += " ";
            }
        }
        if(showObjs)
        {
            res += "}";
        }
        if(i != full_arr_size-t_size && showObjs)
        {
            res += "\n";
        }
        if(i != full_arr_size-t_size && !showObjs)
        {
            res += " ";
        }
        
    }
    return res;
}
