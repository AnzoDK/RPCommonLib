//C String comapre
//expecting nulltermination unless "no-null" is specified, in that case the length of the string will need to be provided
#pragma once
#include <iostream>
bool Cstrcmp(const char* s1, const char* s2)
{
    uint64_t c = 0;
    while(static_cast<unsigned char>(s1[c]) != 0x0 && static_cast<unsigned char>(s2[c]) != 0x0)
    {
        if(s1[c] != s2[c])
        {
            return false;
        }
        c++;
    }
    if(static_cast<unsigned char>(s1[c]) == 0x0 && static_cast<unsigned char>(s2[c]) == 0x0)
    {
        return true;
    }
    return false;
}

//Does not expect null-termination - This also allows comparison against strings with nulls in it
bool Cstrcmp(const char* s1, uint64_t s1l, const char* s2, uint64_t s2l, bool asBytes=false)
{
    //Basically just a sanity check
    if (s1l != s2l)
    {
        return false;
    }
    
    uint64_t c = 0;
    if(asBytes)
    {
        while(c < s1l) //s1l needs to be equal to s2l anyway so it matters not that only compare against s1l
        {
            if(static_cast<unsigned char>(s1[c]) != static_cast<unsigned char>(s2[c])) //This allows comparision against null bytes
            {
                return false;
            }
            c++;
        }
        return true;
    }
    else
    {
        while(c < s1l) //same as before
        {
            if(s1[c] != s2[c]) //This does not allow comarision against null bytes
            {
                return false;
            }
            c++;
        }
        return true;
    }
}
