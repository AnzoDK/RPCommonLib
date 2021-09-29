#pragma once
#include <iostream>
#include <vector>
template <typename T>
static T* InitilizerToArray(std::initializer_list<T> list, size_t& size)
{
    std::vector<T> v = std::vector<T>();
    v.insert(v.begin(), list.begin(), list.end());
    size = v.size();
    T* ret = new T[v.size()];
    for(size_t i = 0; i < v.size(); i++)
    {
        
       ret[i] = v.at(i);
    }
    return ret;
}

template <typename T>
inline static std::vector<T> InitilizerToVector(std::initializer_list<T> list)
{
    std::vector<T> v = std::vector<T>();
    v.insert(v.end(), list.begin(), list.end());
    return v;
}
