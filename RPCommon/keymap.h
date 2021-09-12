#pragma once
#include <iostream>
#include <vector>
template <typename T>
struct Key
{
    Key(){keyName = "";};
    //Don't use this - This is meant to be used to create empty keys for errors
    Key(std::string name){ keyName = name;};
    
    //Key(std::string name, T val){keyName = name; keyValue = &val;};
    Key(std::string name, T val){keyName = name; keyValue = val;};
    
    Key(std::string name, T* val){keyName = name; keyValue = *val;}
    
    ~Key(){}
    std::string keyName;
    T keyValue;
    //T _backupKey;
    
};

template <typename T>
class KeyMap
{
public:
    KeyMap(){};
    Key<T> Find(std::string name)
    {
        for(size_t i = 0; i < keys.size(); i++)
        {
            if(keys.at(i).keyName == name)
            {
                return keys.at(i);
            }
        }
        return Key<T>("Error");
    }
    void Insert(Key<T> key)
    {
        keys.push_back(key);
    }
    void Insert(std::string keyName, T keyValue)
    {
        keys.push_back(Key<T>(keyName, keyValue));
    }
private:
    std::vector<Key<T>> keys = std::vector<Key<T>>();
};

