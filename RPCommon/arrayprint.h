#pragma once
#include <iostream>
#include <vector>
#include <type_traits>
#include "arrayprint.h"

template<typename T>
inline T* VecToArr(std::vector<T> vec, size_t& returnSize)
{
    T* arr = new T[vec.size()];
    for(size_t i = 0; i < vec.size(); i++)
    {
        arr[i] = vec.at(i);
    }
    returnSize = vec.size();
    return arr;
}

template<typename T> //T has to be able to be casted to a string via std::to_string
inline typename std::enable_if<std::is_convertible<T,int>::value && !std::is_same<T,char>::value,void>::type  //*Sigh* Chars will be casted to ints here... Fml - This fix for chars is so fucking stupid
PrintVector(std::vector<T> vec)
{

    for(size_t i = 0; i < vec.size(); i++)
    {
        std::cout << std::to_string(static_cast<T>(vec.at(i))) << std::endl;
    }
}
template<typename T>
inline typename std::enable_if<std::is_same<T,char>::value,void>::type
PrintVector(std::vector<T> vec)
{
    for(size_t i = 0; i < vec.size(); i++)
    {
        /*Actually just kill me.... I mean it works.. but at what cost??? :(
        const char c = static_cast<char>(vec.at(i));
        std::string s = std::string(&c);
        std::cout << s << std::endl;
        */
        //This is much better :)
        std::cout << static_cast<char>(vec.at(i)) << std::endl;
    }
}

//T has to be able to be casted to a string via std::to_string
/*void PrintVector(std::vector<int> vec)
{

        for(size_t i = 0; i < vec.size(); i++)
        {
            std::cout << std::to_string(vec.at(i)) << std::endl;
        }
}*/

/*void PrintVector(std::vector<float> vec)
{

        for(size_t i = 0; i < vec.size(); i++)
        {
            std::cout << std::to_string(vec.at(i)) << std::endl;
        }
}*/

/*void PrintVector(std::vector<double> vec)
{

        for(size_t i = 0; i < vec.size(); i++)
        {
            std::cout << std::to_string(vec.at(i)) << std::endl;
        }
}*/

/*void PrintVector(std::vector<bool> vec)
{

        for(size_t i = 0; i < vec.size(); i++)
        {
            std::cout << std::to_string(vec.at(i)) << std::endl;
        }
}*/

template<typename T>
inline typename std::enable_if<!std::is_convertible<T,int>::value,void>::type
PrintVector(std::vector<T> vec)
{
    std::cout << TERMINAL_COLOR_YELLOW << "Type unknown - Returning Hex values for object of size: " << std::to_string(sizeof(T)) << TERMINAL_COLOR_RESET << std::endl;
    size_t arr_size = 0;
    T* arr = VecToArr(vec,arr_size);
    std::string arrBytesString = GetBytes<T>(reinterpret_cast<size_t>(arr),arr_size,true);
    std::cout << TERMINAL_COLOR_BLUE << arrBytesString << TERMINAL_COLOR_RESET << std::endl;
}

template <typename T>//T has to be able to be casted to a string via std::to_string
inline void PrintArray(T* arr, size_t arrSize)
{
    size_t TSize = sizeof(T);
    for(size_t i = 0; i < arrSize; i++)
    {
         std::cout << std::to_string(arr[i]) << std::endl;
    }
}

