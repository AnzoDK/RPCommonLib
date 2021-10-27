#pragma once
#include <vector>
template <typename T>
static inline std::vector<T> ArrayToVector(T* arr, size_t len)
{
    std::vector<T> v = std::vector<T>();
    for(size_t i = 0; i < len; i++)
    {
        v.push_back(arr[i]);
    }
    return v;
}
