# RPCommonLib
A compilation of small and common functions, divided into seperate headers to make the dev life easier.

## Usage

Just include `RPCommon.h` or one (or more) of the headers to get either all functions or just the ones you need :)


**NOTE** If installed through the [PKGBUILD](https://github.com/AnzoDK/RPCommonLib/blob/master/PKGBUILD) the include command for `RPCommon` will be `#include <RPCommon/RPCommon.h>` or in case of a single header `<RPCommon/<header_name_here>`

#### Example:

```c++
#include "RPCommon.h"


int main()
{
  std::string revThis = "sihTver";
  std::cout << ReverseString(revThis) << std::endl;
  return 0;
}
```
or in this case, where only `ReverseString()` is needed, you could also just do:

```c++
#include "strreverse.h"


int main()
{
  std::string revThis = "sihTver";
  std::cout << ReverseString(revThis) << std::endl;
  return 0;
}
```
 
## Documentation

List of Functions included + Documentation can be found [here](https://github.com/AnzoDK/RPCommonLib/blob/master/Doc.md)
