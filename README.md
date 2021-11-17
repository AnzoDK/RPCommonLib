# RPCommonLib
A compilation of small and common functions to make the dev life easier

List of Functions included:

## arraycpy.h

### T* ArrayCopy(T*, size_t)
Takes an array and saftly copies it and returns it.

### bool ArrayCompare(T*, size_t, T*, size_t)
Takes two Carrays and compares them, assuming that T==(T) is defined.

### bool VectorCompare(std::vector<T>, std::vector<T>)
Takes two vectors and compares them, assuming that T==(T) is defined.

## arrayprint.h

### T* VecToArr(std::vector<T>, size_t&)
Takes a vector and a size_t refrence and creates a Carray from the vector, returning the vector and placing the size in the size_t& argument.

### void PrintVector(std::vector<T> vec)
Prints the vector to standard output.

## arraytovector.h

### std::vector<T> ArrayToVector(T*, size_t)
Takes a Carray and a size and returns a vector.
  
## byteprint.h

### char __HexTable(unsigned char)
[Intended for internal use only] Takes a number from a char and returns the corrosponding hex value.
  
### std::string GetHexFromTable(unsigned char)
Takes a byte and returns it as a hexstring.

### std::string GetBytes(T*, uint)
Takes a Carray and a size and returns a hexstring containing the bytes of the array.
  
### std::string template<typename T>GetBytes(size_t, uint, bool=false)
Takes a object array, a size and a bool (toggling object packing on or off) and returns a hexstring of the bytes from the object array.
  
## eat.h
  
### void Eat(const char*)
Eats a char from a Cstring

### void Eat(std::string&)
Eats a char from a string
  
## initconvert.h

### T* InitilizerToArray(std::initializer_list<T>, size_t&)
Takes a initilizer_list, sets size_t to the size of the array and returns a Carray with the objects.
  
### T* InitilizerToVector(std::initializer_list<T>)
Takes a initilizer_list and returns a vector with the objects.
  
## keymap.h
  
EXPERIMENTAL!!

## strcomp.h

### bool Cstrcmp(const char*, const char*)
Compares two Cstrings without <stdio.h>

### bool Cstrcmp(const char*, uint64_t, const char*, uint64_t, bool=false)
Compares two NON-nullterminated C-strings without including \<stdio> or \<string> and allows for comparing bytes (with null bytes using the bool arg)

## strfindlast.h

### size_t StringFindLast(char, std::string)
Finds the last instance of a given char in a given string, and returns the position

### size_t StringFindLast(std::string, std::string)
Finds the last instance of a given string in a given string, and returns the position

## strlen.h
  
### uint Cstrlen(const char*)
Takes a Cstring and returns the length (as long as it is null-terminated)
  
## strreverse.h
  
### std::string ReverseString(std::string)
Takes a string and reverses it, without deleting the input string, and returns the reversed string
  
## unsignedfstream.h

### unsigned char* ReadPartialUnsignedFile(std::string, size_t&)
Read size_t& bytes from a file as an unsigned file stream returning a Carray of the bytes updating size_t& with the bytes read in case of less bytes found than requested.
  
### unsigned char* ReadUnsignedFile(std::string, size_t&)
Takes a filepath and returns an unsigned char Carray with the bytes read, updating size_t& with the bytes read.



