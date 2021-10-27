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

bool PerformTestEat()
{
    std::string test1 = "ABCD";
    const char* test2 = "ABCD";
    std::cout << "Testing Eating of std::string" << std::endl;
    
    Eat(test1);
    
    if(test1 != "BCD")
    {
        std::cout << TERMINAL_COLOR_RED << test1 << " is not equal to " << "BCD" << TERMINAL_COLOR_RESET << std::endl;
        return false;
    }
    
    std::cout << TERMINAL_COLOR_GREEN << "Passed!" << TERMINAL_COLOR_RESET << std::endl;
    
    Eat(test2);
    
    if(Cstrcmp(test2,"BCD"))
    {
        std::cout << TERMINAL_COLOR_RED << test2 << " is not equal to " << "BCD" << TERMINAL_COLOR_RESET << std::endl;
        return false;
    }
    
    std::cout << TERMINAL_COLOR_GREEN << "Passed!" << TERMINAL_COLOR_RESET << std::endl;
    
    return true;
    
    
}
bool PerformTestFstream()
{
    unsigned char expected[45] =
    {
        0x4e, 0x6f, 0x72, 0x6d,
        0x61, 0x6c, 0x54, 0x65,
        0x78, 0x74, 0x52, 0x69,
        0x67, 0x68, 0x74, 0x20,
        0x68, 0x65, 0x72, 0x65,
        0x0a, 0x00, 0x00, 0x00,
        0x44, 0x33, 0x43, 0x44,
        0x03, 0x32, 0x23, 0x01,
        0x02, 0x03, 0x04, 0x05,
        0x06, 0x07, 0x08, 0x09,
        0x03, 0x04, 0x05, 0x06,
        0x00
    };
    
    std::cout << "Testing File Read with correct parameters..." << std::endl;
    
    size_t bytesRead = 0;
    unsigned char* input = ReadUnsignedFile("testRead.txt",bytesRead);
    if(bytesRead == 45)
    {
    if(!Cstrcmp(reinterpret_cast<char*>(input),bytesRead,reinterpret_cast<char*>(expected),45,true))
    {
        std::cout << TERMINAL_COLOR_RED << GetBytes(input,bytesRead) << " is supposed to be equal to " << GetBytes(expected,45) << TERMINAL_COLOR_RESET << std::endl;
        return false;
    }
    }
    else
    {
        std::cout << TERMINAL_COLOR_RED << GetBytes(input,bytesRead) << " is supposed 45 bytes long.. " << TERMINAL_COLOR_RESET << std::endl;
        return false;
    }
    bytesRead = 0;
    
    std::cout << TERMINAL_COLOR_GREEN << "Passed!" << TERMINAL_COLOR_RESET << std::endl;
    
    std::cout << "Testing File Read with wrong paramenters..." << std::endl;
    delete[] input;
    bytesRead = 40;
    input = ReadPartialUnsignedFile("testRead.txt",bytesRead);
    if(Cstrcmp(reinterpret_cast<char*>(input),bytesRead,reinterpret_cast<char*>(expected),45,true))
    {
        std::cout << TERMINAL_COLOR_RED << GetBytes(expected,bytesRead) << " is not supposed to be equal to " << GetBytes(input,45) << TERMINAL_COLOR_RESET << std::endl;
        return false;
    }
    
    std::cout << TERMINAL_COLOR_GREEN << "Passed!" << TERMINAL_COLOR_RESET << std::endl;
    
    return true;
    
}

bool PerformTestArrayCopy()
{
    std::cout << "Testing ArrayCompare..." << std::endl;
    
    int _arr[] = {0,1,2,3,4,5};
    int _arr2[] = {0,1,2,3,4,5};
    int _arr3[] = {0,1,3,3,4,5};
    
    if(!ArrayCompare(_arr,6,_arr2,6))
    {
        std::cout << TERMINAL_COLOR_RED << GetBytes(_arr,6) << " is supposed to be equal to " << GetBytes(_arr2,6) << TERMINAL_COLOR_RESET << std::endl;
        return false;
    }
    
    std::cout << TERMINAL_COLOR_GREEN << "Equal Test Passed!" << TERMINAL_COLOR_RESET << std::endl;
    
    if(ArrayCompare(_arr,6,_arr3,6))
    {
        std::cout << TERMINAL_COLOR_RED << GetBytes(_arr,6) << " is not supposed to be equal to " << GetBytes(_arr3,6) << TERMINAL_COLOR_RESET << std::endl;
        return false;
    }
    
     std::cout << TERMINAL_COLOR_GREEN << "Unequal Test Passed!" << TERMINAL_COLOR_RESET << std::endl;
    
    int arr[] = {0,0,0,0,2,0,2,0,2,0,2,0,5,6,7,8,5,4,3,1,2,4,5,6,7,4,46,4,5,4,4,3,4,5,6,546,5,65,656,56,56,56,56,56,56,1243,2343,435,346,3,756,7};
    std::cout << "Testing Copy..." << std::endl;
    int* newArr = ArrayCopy(arr,52);
    
    if(!ArrayCompare(arr,52,newArr,52))
    {
        std::cout << TERMINAL_COLOR_RED << GetBytes(arr,52) << " is supposed to be equal to " << GetBytes(newArr,52) << TERMINAL_COLOR_RESET << std::endl;
        delete[] newArr;
        return false;
    }
    delete[] newArr;
     std::cout << TERMINAL_COLOR_GREEN << "All 'arraycpy' Tests Passed!" << TERMINAL_COLOR_RESET << std::endl;
    return true;
}

bool PerformTestInitList()
{
    int arr[] = {1,2,3,4,5};
    size_t size = 0;
    std::cout << "Testing InitToÁrray..." << std::endl;
    int* arr2 = InitilizerToArray({1,2,3,4,5},size);
    if(!ArrayCompare(arr,5,arr2,size))
    {
        std::cout << TERMINAL_COLOR_RED << GetBytes(arr,5) << " is supposed to be equal to " << GetBytes(InitilizerToArray({1,2,3,4,5},size),size) << TERMINAL_COLOR_RESET << std::endl;
        delete[] arr2;
        return false;
    }
    delete[] arr2;
    std::cout << TERMINAL_COLOR_GREEN << "Equal Test Passed!" << TERMINAL_COLOR_RESET << std::endl;
    arr2 = InitilizerToArray({1,2,3,4,9},size);
    if(ArrayCompare(arr,5,arr2,size))
    {
        std::cout << TERMINAL_COLOR_RED << GetBytes(arr,5) << " is not supposed to be equal to " << GetBytes(InitilizerToArray({1,2,3,4,6},size),size) << TERMINAL_COLOR_RESET << std::endl;
        delete[] arr2;
        return false;
    }
    delete[] arr2;
    std::cout << TERMINAL_COLOR_GREEN << "Unequal Test Passed!" << TERMINAL_COLOR_RESET << std::endl;
    std::cout << "Testing InitToVector..." << std::endl;
    
    std::vector<int> v = std::vector<int>();
    v = {1,2,3,4,5};
    
    if(!VectorCompare(v,InitilizerToVector({1,2,3,4,5})))
    {
        std::cout << TERMINAL_COLOR_RED << GetBytes(&v[0],5) << " is supposed to be equal to " << GetBytes(&InitilizerToVector({1,2,3,4,5})[0],5) << TERMINAL_COLOR_RESET << std::endl;
        return false;
    }
    std::cout << TERMINAL_COLOR_GREEN << "Equal Test Passed!" << TERMINAL_COLOR_RESET << std::endl;
    
    if(VectorCompare(v,InitilizerToVector({1,2,3,3,5})))
    {
        std::cout << TERMINAL_COLOR_RED << GetBytes(&v[0],5) << " is not supposed to be equal to " << GetBytes(&InitilizerToVector({1,2,3,4,5})[0],5) << TERMINAL_COLOR_RESET << std::endl;
        return false;
    }
    std::cout << TERMINAL_COLOR_GREEN << "Unequal Test Passed!" << TERMINAL_COLOR_RESET << std::endl;
    return true;
    
}


bool PerformTestArrayToVector()
{
    std::vector<int> vI = {0,1020,222,5838,4444,22222,3};
    int* aI = new int[] {0,1020,222,5838,4444,22222,3};
    std::cout << "Testing ArrayToVector..." << std::endl;
    if(!VectorCompare(ArrayToVector(aI,7),vI))
    {
        std::cout << TERMINAL_COLOR_RED << GetBytes(&vI[0],7) << " is supposed to be equal to " << GetBytes(aI,7) << TERMINAL_COLOR_RESET << std::endl;
        return false;
    }
    std::cout << TERMINAL_COLOR_GREEN << "ArrayToVector Test Passed!" << TERMINAL_COLOR_RESET << std::endl;
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
    std::cout << TERMINAL_COLOR_YELLOW << "Running tests on eat" << TERMINAL_COLOR_RESET << std::endl;
    if(!PerformTestEat())
    {
        std::cout << TERMINAL_COLOR_RED << "eat failed!" << TERMINAL_COLOR_RESET << std::endl;
        exit(0b00100000);
    }
    std::cout << TERMINAL_COLOR_YELLOW << "Running tests on unsignedfstream" << TERMINAL_COLOR_RESET << std::endl;
    if(!PerformTestFstream())
    {
        std::cout << TERMINAL_COLOR_RED << "unsignedfstream failed!" << TERMINAL_COLOR_RESET << std::endl;
        exit(0b01000000);
    }
    std::cout << TERMINAL_COLOR_YELLOW << "Running tests on arraycpy" << TERMINAL_COLOR_RESET << std::endl;
    if(!PerformTestArrayCopy())
    {
        std::cout << TERMINAL_COLOR_RED << "arraycpy failed!" << TERMINAL_COLOR_RESET << std::endl;
        exit(0b10000000);
    }
    std::cout << TERMINAL_COLOR_YELLOW << "Running tests on initconvert" << TERMINAL_COLOR_RESET << std::endl;
    if(!PerformTestInitList())
    {
        std::cout << TERMINAL_COLOR_RED << "initconvert failed!" << TERMINAL_COLOR_RESET << std::endl;
        exit(0b10000001);
    }
    std::cout << TERMINAL_COLOR_YELLOW << "Running tests on arraytovector" << TERMINAL_COLOR_RESET << std::endl;
    if(!PerformTestArrayToVector())
    {
        std::cout << TERMINAL_COLOR_RED << "arraytovector failed!" << TERMINAL_COLOR_RESET << std::endl;
        exit(0b10000010);
    }
    
    std::cout << TERMINAL_COLOR_GREEN << "Test Complete - No errors!" << TERMINAL_COLOR_RESET << std::endl;
    return 0;
}
