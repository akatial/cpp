#include <iostream>  
#include <algorithm>  
#include <array>  
#include <bitset>  
  
int main()  
{  
    std::array<int, 10> arr;  
    std::generate(arr.begin(), arr.end(), []{static int index; return index++;});  
  
    std::cout << "before: ";  
    std::for_each(arr.begin(), arr.end(), [](int value){ std::cout << std::bitset<4>(value) << " "; });  
    std::cout << std::endl;  
  
    std::sort(arr.begin(), arr.end(), [](const int &l, const int &r){ return __builtin_popcount(l) > __builtin_popcount(r); });  
  
    std::cout << "after : ";  
    std::for_each(arr.begin(), arr.end(), [](int value){ std::cout << std::bitset<4>(value) << " "; });  
    std::cout << std::endl;  
  
    return 0;  
}  
