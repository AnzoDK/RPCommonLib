#pragma once
#include <iostream>
#include <vector>

template<typename T>
static inline void PushArrayToVector(std::vector<T>& vec, T* arr, size_t arrLen)
{
    for(size_t i = 0; i < arrLen; i++)
    {
        vec.push_back(arr[i]);
    }
}
