#pragma once
#include <iostream>

template <typename T>
static inline T* AppendArray(T* arr1, size_t arr1Len, T* arr2, size_t arr2Len, size_t& newLen) //DeleteSafe
{
    T* newArr = new T[arr1Len+arr2Len];
    for(size_t i = 0; i < arr1Len; i++)
    {
        newArr[i] = arr1[i];
    }
    for(size_t i = 0; i < arr2Len; i++)
    {
        newArr[i+arr1Len] = arr2[i];
    }
    newLen = arr1Len+arr2Len;
    return newArr;
}
