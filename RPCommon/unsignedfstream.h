#pragma once
#include <fstream>
#include <iostream>

inline unsigned char* ReadPartialUnsignedFile(std::string file, size_t& bytes) //reads 'bytes' bytes from file - Bytes will be updated to match the bytes read
{
    unsigned char* buffer = new unsigned char[bytes];
    std::ifstream in = std::ifstream(file,std::ios::binary | std::ios::ate);
    size_t size = in.tellg();
    in.seekg(0,std::ios::beg);
    if(bytes > size)
    {
        //Err
        std::cout << "Trying to read more bytes than is available in file: '" << file << "', trying to read: '" << bytes << "' but file did only contain: '" << size << "' bytes - reading maxsize instead" << std::endl;
        bytes = size;
    }
    if(in.read(reinterpret_cast<char*>(buffer),size))
    {
            in.close();
            return buffer;
    }
    else
    {
        in.close();
        std::cout << "File read error" << std::endl;
        delete[] buffer;
        bytes = 1;
        return new unsigned char[1];
    }

}
inline unsigned char* ReadUnsignedFile(std::string file, size_t& bytesRead) //Reads the whole file
{
    unsigned char* buffer;
    std::ifstream in = std::ifstream(file,std::ios::binary | std::ios::ate);
    size_t size = in.tellg();
    in.seekg(0,std::ios::beg);
    bytesRead = size;
    buffer = new unsigned char[size];
    if(in.read(reinterpret_cast<char*>(buffer),size))
    {
            in.close();
            return buffer;
    }
    else
    {
        in.close();
        std::cout << "File read error" << std::endl;
        delete[] buffer;
        bytesRead = 1;
        return new unsigned char[1];
    }
}
