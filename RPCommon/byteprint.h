#pragma once
#include <iostream>
#include <vector>
static char __HexTable(unsigned char c)
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

static char __ReverseHexTable(unsigned char c)
{
    switch(c)
    {
        case '0':
            return 0;
        case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		case 'A':
			return 10;
		case 'B':
			return 11;
		case 'C':
			return 12;
		case 'D':
			return 13;
		case 'E':
			return 14;
		case 'F':
			return 15;
		default:
			std::cout << "Unknown hex char " << c << std::endl;
			return -1;
	}
}

static std::string GetHexFromTable(unsigned char b)
{
    std::string res = "";
    unsigned char tmp = b;
    tmp = (tmp >> 4);
    res += __HexTable(tmp);
    tmp = b & 0b00001111;
    res += __HexTable(tmp);
    return res;
    
}

#if __cplusplus > 201703L
/*C++20*/
static unsigned char GetByteFromTable(std::string_view byteStr)
{
    unsigned char byte = 0x0;
    if(byteStr.size() != 2)
    {
        std::cout << "Input string: " << byteStr << " Is not a valid 1 byte string" << std::endl;
        return -1;
    }
    byte = byte | __ReverseHexTable(byteStr.at(0)) << 4;
    byte = byte | __ReverseHexTable(byteStr.at(1));
    return byte;
    
}
#else
// C++ < C++20

static unsigned char GetByteFromTable(const std::string& byteStr)
{
    unsigned char byte = 0x0;
    if(byteStr.size() != 2)
    {
        std::cout << "Input string: " << byteStr << " Is not a valid 1 byte string" << std::endl;
        return -1;
    }
    byte = byte | __ReverseHexTable(byteStr.at(0)) << 4;
    byte = byte | __ReverseHexTable(byteStr.at(1));
    return byte;
    
}
#endif


static void PrintBytes()
{
    
}


template <typename T>
static std::string GetBytes(T* tArr, unsigned int arrLen)
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
static std::string GetBytes(size_t address, unsigned int arrLen, bool showObjs=false)
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
