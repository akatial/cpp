#include <iostream>

#define N 10

int main(void)
{
  for( int i = 0 ; i < N ; i = i + 1 )
    {
      for( int j = 0 ; j < i; j = j + 1 )
	{
	  std::cout << 1;
	}
      for( int j = i ; j < N ; j = j + 1 )
	{
	  std::cout << 0;
	}
      std::cout << std::endl;
    }
  for( int i = 0 ; i < N ; i = i + 1 )
    {
      std::cout << 1;
    }
  std::cout << std::endl;
  return 0;
}

/*
00000000000
10000000000
11000000000
11100000000
11110000000
 */
