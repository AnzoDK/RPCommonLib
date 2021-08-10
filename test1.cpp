#include <iostream>
#include "RPCommon/RPCommon.h"

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
    
    std::cout << "Comparing " << TERMINAL_COLOR_BLUE << std::string(GetBytes<const char>(testChar5,9)) << TERMINAL_COLOR_RESET << " to " TERMINAL_COLOR_BLUE << std::string(GetBytes<const char>(testChar6,9)) << TERMINAL_COLOR_RESET << std::endl;
    
    if(!Cstrcmp(testChar5,9,testChar6,9))
    {
        std::cout << "[" << TERMINAL_COLOR_BLUE << std::string(testChar5) << TERMINAL_COLOR_RESET << "]" << TERMINAL_COLOR_RED << " was not equal to [" << TERMINAL_COLOR_BLUE << std::string(testChar6) << TERMINAL_COLOR_RED << "] FATAL" << TERMINAL_COLOR_RESET << std::endl;
        return false;
    }
    
    std::cout << TERMINAL_COLOR_GREEN << "Passed!" << TERMINAL_COLOR_RESET << std::endl;
    
    std::cout << "Comparing " << TERMINAL_COLOR_BLUE << std::string(GetBytes<const char>(testChar6,9)) << TERMINAL_COLOR_RESET << " to " TERMINAL_COLOR_BLUE << std::string(GetBytes<const char>(testChar7,10)) << TERMINAL_COLOR_RESET << std::endl;
    
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

bool PerformTestCstrlen()
{
    const char* lengthTest1 = "0123456789";
    std::cout << "Checking length of: " << TERMINAL_COLOR_BLUE << std::string(lengthTest1) << TERMINAL_COLOR_RESET << TERMINAL_COLOR_RESET << std::endl;
    if (Cstrlen(lengthTest1) != 10)
    {
        std::cout << "[\"" << TERMINAL_COLOR_BLUE << std::string(lengthTest1) << TERMINAL_COLOR_RESET << "\"]" << TERMINAL_COLOR_RED << " was determined to be: " << std::to_string(Cstrlen(lengthTest1)) << " Should have been [" << TERMINAL_COLOR_BLUE << std::to_string(10) << TERMINAL_COLOR_RED << "] FATAL" << TERMINAL_COLOR_RESET << std::endl;
        return false;
    }
    std::cout << TERMINAL_COLOR_GREEN << "Passed!" << TERMINAL_COLOR_RESET << std::endl;
    return true;
}

bool PerformTestStringFindLast()
{
   std::string findLastTest1 = "Hello! World!";
   std::string findLastTest2 = "Hi There Hello Hi Hello";
   
   std::cout << "Finding last of '!' in: " << TERMINAL_COLOR_BLUE << std::string(findLastTest1) << TERMINAL_COLOR_RESET << TERMINAL_COLOR_RESET << std::endl;
   if(StringFindLast('!',findLastTest1) != 12)
   {
        std::cout << "Last ['" << TERMINAL_COLOR_BLUE << "!" << TERMINAL_COLOR_RESET << "']" << TERMINAL_COLOR_RED << " was determined to be located at: " << std::to_string(StringFindLast('!',findLastTest1)) << " Should have been [" << TERMINAL_COLOR_BLUE << std::to_string(12) << TERMINAL_COLOR_RED << "] FATAL" << TERMINAL_COLOR_RESET << std::endl;
        return false;
   }
   
   std::cout << TERMINAL_COLOR_GREEN << "Passed!" << TERMINAL_COLOR_RESET << std::endl;
   
   std::cout << "Finding last of \"Hi\" in: " << TERMINAL_COLOR_BLUE << std::string(findLastTest2) << TERMINAL_COLOR_RESET << TERMINAL_COLOR_RESET << std::endl;
   if(StringFindLast("Hi",findLastTest2) != 15)
   {
        std::cout << "Last [\"" << TERMINAL_COLOR_BLUE << "Hi" << TERMINAL_COLOR_RESET << "\"]" << TERMINAL_COLOR_RED << " was determined to be located at: " << std::to_string(StringFindLast("Hi",findLastTest2)) << " Should have been [" << TERMINAL_COLOR_BLUE << std::to_string(15) << TERMINAL_COLOR_RED << "] FATAL" << TERMINAL_COLOR_RESET << std::endl;
        return false;
   }
   
   std::cout << TERMINAL_COLOR_GREEN << "Passed!" << TERMINAL_COLOR_RESET << std::endl;
   
   return true;
   
}

bool PerformTestVecPrint()
{
    std::vector<int> testErrVec = {1,2,3,4,5,6,7};
    std::vector<std::vector<int>> testErrVec2 = {testErrVec, testErrVec};
    std::vector<float> testErrVec3 = {1.1,1.2,1.3,1.4,1.5,1.6,1.7};
    std::vector<double> testErrVec4 = {1.11,1.112,1.113,1.114,1.115,1.115,1.116,1.117};
    std::vector<char> testErrVec5 = {'A','B','C','D','E','F','G','H','I','J'};
    
    
    std::cout << "Testing Normal and Strange VecPrint Calls..." << std::endl;
    
    std::cout << "Testing 'int'" << std::endl;
    
    PrintVector(testErrVec);
    
    std::cout << "Testing 'float'" << std::endl;
    
    PrintVector(testErrVec3);
    
    std::cout << "Testing 'double'" << std::endl;
    
    PrintVector(testErrVec4);
    
    std::cout << "Testing 'char'" << std::endl;
    
    PrintVector(testErrVec5);
    
    std::cout << TERMINAL_COLOR_GREEN << "Standard Vec Print Complete!" << TERMINAL_COLOR_RESET << std::endl;
    
    PrintVector(testErrVec2);

    std::cout << TERMINAL_COLOR_GREEN << "Strange Vec Print Complete!" << TERMINAL_COLOR_RESET << std::endl;
    
    std::cout << TERMINAL_COLOR_GREEN << "Passed!" << TERMINAL_COLOR_RESET << std::endl;
    return true;
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
    if(!PerformTestStringFindLast())
    {
        std::cout << TERMINAL_COLOR_RED << "strfindlast failed!" << TERMINAL_COLOR_RESET << std::endl;
        exit(0b00000100);
    }
    std::cout << TERMINAL_COLOR_YELLOW << "Running tests on Cstrlen" << TERMINAL_COLOR_RESET << std::endl;
    if(!PerformTestCstrlen())
    {
        std::cout << TERMINAL_COLOR_RED << "Cstrlen failed!" << TERMINAL_COLOR_RESET << std::endl;
        exit(0b00001000);
    }
    std::cout << TERMINAL_COLOR_YELLOW << "Running tests on arrayprint" << TERMINAL_COLOR_RESET << std::endl;
    if(!PerformTestVecPrint())
    {
        std::cout << TERMINAL_COLOR_RED << "arrayprint failed!" << TERMINAL_COLOR_RESET << std::endl;
        exit(0b00010000);
    }
    
    std::cout << TERMINAL_COLOR_GREEN << "Test Complete - No errors!" << TERMINAL_COLOR_RESET << std::endl;
    return 0;
}
