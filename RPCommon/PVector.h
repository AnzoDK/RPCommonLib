#pragma once
#include <type_traits>
#include <vector>
#include <iostream>
#include <typeinfo>

template <typename T>
class TriEntry
{
    public:
        TriEntry(T a, T b, T c) : m_a(a), m_b(b), m_c(c){}
        T x() {return m_a;}
        T y() {return m_b;}
        T z() {return m_c;}
        typedef T type;
    protected:
        T m_a;
        T m_b;
        T m_c;
};

template <typename T>
class DualEntry
{
    public:
        DualEntry(T a, T b) : m_a(a), m_b(b){}
        T x() { return m_a; }
        T y() { return m_b; }
        typedef T type;
    protected:
        T m_a;
        T m_b;
};

template<typename TB>
class PVector
{
    public:
        template<typename = std::enable_if_t<std::__or_<std::is_same<TB,DualEntry<typename TB::type>>, std::is_same<TB,TriEntry<typename TB::type>>>::value>>
        PVector()
        {
            m_data = std::vector<TB>();
        }
        void Add(TB entry)
        {
            m_data.push_back(entry);
        }
        template<typename = std::enable_if<std::is_same<TB,DualEntry<typename TB::type>>::value>>
        void Add(typename TB::type a, typename TB::type b)
        {
            m_data.push_back(TB(a,b));
        }
        template<typename = std::enable_if<std::is_same<TB,TriEntry<typename TB::type>>::value>>
        void Add(typename TB::type a, typename TB::type b, typename TB::type c)
        {
            m_data.push_back(TB(a,b,c));
        }
        void RemoveAt(size_t index)
        {
            if(index >= m_data.size())
            {
                throw std::out_of_range("PVector Out of bounds - index: " + std::to_string(index) + " - max: " + std::to_string(m_data.size()));
            }
            m_data.erase(m_data.begin() + index);
        }
        TB GetAt(size_t index)
        {
            if(index >= m_data.size())
            {
                throw std::out_of_range("PVector Out of bounds - index: " + std::to_string(index) + " - max: " + std::to_string(m_data.size()));
            }
            return m_data[index];
        }
        size_t size()
        {
            return m_data.size();
        }
        TB operator[] (int i)
        {
            return GetAt(i);
        }
    protected:
        std::vector<TB> m_data;
};
