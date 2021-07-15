# RPCommonLib
A compilation of small and common functions to make the dev life easier

List of Functions included:

### std::string ReverseString(std::string)
Takes a string and reverses it, without deleting the input string, and returns the reversed string

### size_t StringFindLast(char, std::string)
Finds the last instance of a given char in a given string, and returns the position

### bool Cstrcmp(const char*, const char*)
Compares two null-terminated C-strings without including \<stdio> or \<string>

### bool Cstrcmp(const char*, uint64_t, const char*, uint64_t, bool=false)
Compares two NON-nullterminated C-strings without including \<stdio> or \<string> and allows for comparing bytes (with null bytes using the bool arg)
