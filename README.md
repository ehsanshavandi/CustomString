# CustomString

CustomString is a c++ library for dealing with strings.

## Installation
header-only, all you need is to get customstring.hpp file

## Usage

```cpp
#include "customstring.hpp"

using namespace std;

int main() {
  CustomString csExample("Ehsan Shavandi");
  string exLower = csExample.toLowerCase();
  string exUpper = csExample.toUpperCase();
  cout << exLower << endl;
  cout << exUpper << endl;

  return 0;
}
```
