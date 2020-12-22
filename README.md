# double_ended_sorts
C++ library full of two-sided versions of elementary sorts with (varying) support for unspecified containers and datatypes through templating and an STL-like approach to using iterators on iterator-able containers (eg std::vector)

## Includes:
- Double ended selection sort
  - Support for STL vectors, c-style arrays with size variable, and templated generic forward iterators
- Double ended bubble sort
  - Support for STL vectors, c-style arrays with size variable, and templated generic BIDIRECTIONAL iterators

## Will include in the future:
- Double ended insertion sort

## Use example
```c++
#include "double_selection_sort.h"
#include <vector>
#include <iostream>

int main(){
  std::vector<int> vec = {66, 60, 55, 9, 65, 57, 49, 54, 89, 80};
  double_selection_sort dss;

  for(int num : vec) std::cout << num << " ";
  std::cout << std::endl;

  dss(vec);

  for(int num : vec) std::cout << num << " ";
  std::cout << std::endl;
}
```
output:
```
66 60 55 9 65 57 49 54 89 80
9 49 54 55 57 60 65 66 80 89

```