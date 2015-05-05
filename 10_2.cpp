#include <iostream>
#include <vector>
#include <algorithm>

typedef unsigned long long int ulli;

int main(void)
{
  ull num = 18446744073709551615ULL;
  std::vector<int> bit; 
  for( ulli i = 1 ; i ; i = i << 1 )
    {
      if( num & i )
	bit.push_back(1);
      else
	bit.push_back(0);
    }
  reverse(bit.begin(), bit.end());
  uint length = bit.size();
  std::cout << length << std::endl;
  for( ulli i = 0 ; i < length ; i++ )
      std::cout << bit[i];
  std::cout << std::endl;
  return 0;
}
