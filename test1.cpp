#include <iostream>
#include "RPCommon/RPCommon.h"

#ifndef NO_COLOR
#define TERMINAL_COLOR_RESET "\e[0m"
#define TERMINAL_COLOR_RED "\e[1;31m"
#define TERMINAL_COLOR_GREEN "\e[1;32m"
#define TERMINAL_COLOR_YELLOW "\e[1;33m"
#define TERMINAL_COLOR_BLUE "\e[1;34m"

#else

#define TERMINAL_COLOR_RESET
#define TERMINAL_COLOR_RED 
#define TERMINAL_COLOR_GREEN 
#define TERMINAL_COLOR_YELLOW
#define TERMINAL_COLOR_BLUE

#endif

bool b_working = true;
bool PerformTestCstrcmp()
{
    //strcomp test
    const char* testChar1 = "Hello World!";
    const char* testChar2 = "Hello World!";
    const char* testChar3 = "Hello";
    const char* testChar4 = "World!";
    const char testChar5[] = {
        static_cast<char>('H'),
        static_cast<char>(0x0),
        static_cast<char>('e'),
        static_cast<char>(0x0),
        static_cast<char>('l'),
        static_cast<char>(0x0),
        static_cast<char>('l'),
        static_cast<char>(0x0),
        static_cast<char>('o')
        
    };
        const char testChar6[] = {
        static_cast<char>('H'),
        static_cast<char>(0x0),
        static_cast<char>('e'),
        static_cast<char>(0x0),
        static_cast<char>('l'),
        static_cast<char>(0x0),
        static_cast<char>('l'),
        static_cast<char>(0x0),
        static_cast<char>('o')
        
    };
        const char testChar7[] = {
        static_cast<char>('H'),
        static_cast<char>(0x0),
        static_cast<char>('e'),
        static_cast<char>(0x0),
        static_cast<char>('l'),
        static_cast<char>(0x0),
        static_cast<char>('l'),
        static_cast<char>(0x0),
        static_cast<char>('a'),
        static_cast<char>(0x0)
        
    };
    
    
    std::cout << "Comparing " << TERMINAL_COLOR_BLUE << std::string(testChar1) << TERMINAL_COLOR_RESET << " to " TERMINAL_COLOR_BLUE << std::string(testChar2) << TERMINAL_COLOR_RESET << std::endl;
    
    if(!Cstrcmp(testChar1,testChar2))
    {
        std::cout << "[" << TERMINAL_COLOR_BLUE << std::string(testChar1) << TERMINAL_COLOR_RESET << "]" << TERMINAL_COLOR_RED << " was not equal to [" << TERMINAL_COLOR_BLUE << std::string(testChar2) << TERMINAL_COLOR_RED << "] FATAL" << TERMINAL_COLOR_RESET << std::endl;
        return false;
    }
    
    std::cout << TERMINAL_COLOR_GREEN << "Passed!" << TERMINAL_COLOR_RESET << std::endl;
    
    std::cout << "Comparing " << TERMINAL_COLOR_BLUE << std::string(testChar2) << TERMINAL_COLOR_RESET << " to " TERMINAL_COLOR_BLUE << std::string(testChar3) << TERMINAL_COLOR_RESET << std::endl;
    
    if(Cstrcmp(testChar2,testChar3))
    {
        std::cout << "[" << TERMINAL_COLOR_BLUE << std::string(testChar2) << TERMINAL_COLOR_RESET << "]" << TERMINAL_COLOR_RED << " was equal to [" << TERMINAL_COLOR_BLUE << std::string(testChar3) << TERMINAL_COLOR_RED << "] FATAL" << TERMINAL_COLOR_RESET << std::endl;
        return false;
    }
    
    std::cout << TERMINAL_COLOR_GREEN << "Passed!" << TERMINAL_COLOR_RESET << std::endl;
    
    std::cout << "Comparing " << TERMINAL_COLOR_BLUE << std::string(testChar5) << TERMINAL_COLOR_RESET << " to " TERMINAL_COLOR_BLUE << std::string(testChar6) << TERMINAL_COLOR_RESET << std::endl;
    
    if(!Cstrcmp(testChar5,9,testChar6,9))
    {
        std::cout << "[" << TERMINAL_COLOR_BLUE << std::string(testChar5) << TERMINAL_COLOR_RESET << "]" << TERMINAL_COLOR_RED << " was not equal to [" << TERMINAL_COLOR_BLUE << std::string(testChar6) << TERMINAL_COLOR_RED << "] FATAL" << TERMINAL_COLOR_RESET << std::endl;
        return false;
    }
    
    std::cout << TERMINAL_COLOR_GREEN << "Passed!" << TERMINAL_COLOR_RESET << std::endl;
    
    std::cout << "Comparing " << TERMINAL_COLOR_BLUE << std::string(testChar6) << TERMINAL_COLOR_RESET << " to " TERMINAL_COLOR_BLUE << std::string(testChar7) << TERMINAL_COLOR_RESET << std::endl;
    
    if(Cstrcmp(testChar6,9,testChar7,9))
    {
        std::cout << "[" << TERMINAL_COLOR_BLUE << std::string(testChar6) << TERMINAL_COLOR_RESET << "]" << TERMINAL_COLOR_RED << " was equal to [" << TERMINAL_COLOR_BLUE << std::string(testChar7) << TERMINAL_COLOR_RED << "] FATAL" << TERMINAL_COLOR_RESET << std::endl;
        return false;
    }
    
    std::cout << TERMINAL_COLOR_GREEN << "Passed!" << TERMINAL_COLOR_RESET << std::endl;
    
    return true;
}

bool PerformTestBytePrint()
{
    const char* byteTest1 = "Hello World!";
    const char* byteAnswer1 = "0x48 0x65 0x6C 0x6C 0x6F 0x20 0x57 0x6F 0x72 0x6C 0x64 0x21";
    
    std::cout << "Printing Bytes of: " << TERMINAL_COLOR_BLUE << std::string(byteTest1) << TERMINAL_COLOR_RESET << TERMINAL_COLOR_RESET << std::endl;
    std::string tmp = GetBytes<const char>(byteTest1,12);
    
    std::cout << "Comparing " << TERMINAL_COLOR_BLUE << std::string(tmp) << TERMINAL_COLOR_RESET << " to " TERMINAL_COLOR_BLUE << std::string(byteAnswer1) << TERMINAL_COLOR_RESET << std::endl;
    
    if(!Cstrcmp(tmp.c_str(),byteAnswer1))
    {
        std::cout << "[" << TERMINAL_COLOR_BLUE << std::string(tmp) << TERMINAL_COLOR_RESET << "]" << TERMINAL_COLOR_RED << " was not equal to [" << TERMINAL_COLOR_BLUE << std::string(byteAnswer1) << TERMINAL_COLOR_RED << "] FATAL" << TERMINAL_COLOR_RESET << std::endl;
        return false;
    }
    
    std::cout << TERMINAL_COLOR_GREEN << "Passed!" << TERMINAL_COLOR_RESET << std::endl;
    
    return true;
    
    
}

bool PerformTestStringFindLast()
{
    
}

int main()
{
    std::cout << TERMINAL_COLOR_YELLOW << "Running tests on Cstrcmp" << TERMINAL_COLOR_RESET << std::endl;
    if(!PerformTestCstrcmp())
    {
        std::cout << TERMINAL_COLOR_RED << "Cstrcmp failed!" << TERMINAL_COLOR_RESET << std::endl;
        exit(0b00000001);
    }
    std::cout << TERMINAL_COLOR_YELLOW << "Running tests on byteprint" << TERMINAL_COLOR_RESET << std::endl;
    if(!PerformTestBytePrint())
    {
        std::cout << TERMINAL_COLOR_RED << "byteprint failed!" << TERMINAL_COLOR_RESET << std::endl;
        exit(0b00000010);
    }
        std::cout << TERMINAL_COLOR_YELLOW << "Running tests on StringFindLast" << TERMINAL_COLOR_RESET << std::endl;
        //Not added yet
    /*if(!PerformTestStringFindLast())
    {
        std::cout << TERMINAL_COLOR_RED << "strfindlast failed!" << TERMINAL_COLOR_RESET << std::endl;
        exit(0b00000100);
    }*/
    
    std::cout << TERMINAL_COLOR_GREEN << "Test Complete - No errors!" << TERMINAL_COLOR_RESET << std::endl;
    return 0;
}
