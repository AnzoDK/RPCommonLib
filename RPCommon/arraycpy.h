#pragma once
#include <iostream>
template<typename T>
inline static T* ArrayCopy(T* orig, size_t orig_len) //We dont return a length as it is a copy of the original - so same length
{
    T* newArr = new T[orig_len];
    
    for(size_t i = 0; i < orig_len; i++)
    {
        newArr[i] = orig[i];
    }
    return newArr;
    
}

template <typename T>
inline static bool ArrayCompare(T* t1, size_t t1_len, T* t2, size_t t2_len)
{
    if(t1_len != t2_len)
    {
        return false;
    }
    for(size_t i = 0; i < t1_len; i++) //t1_len == t2_len so this is not a problem
    {
        if(t1[i] != t2[i])
        {
            return false;
        }
    }
    return true;
}
