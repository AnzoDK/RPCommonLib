//C String comapre
//expecting nulltermination unless "no-null" is specified, in that case the length of the string will need to be provided
#pragma once
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
