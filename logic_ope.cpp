#include <iostream>
#include <cstdio>

int main(void)
{
  for( int a = 0 ; a < 2 ; a++ )
    {
      for( int b = 0 ; b < 2 ; b++ )
	{
	  for( int c = 0 ; c < 2 ; c++ )
	    {
	      printf("%d %d %d: ", a, b, c);
	      if( (a || b) && c) std::cout << 1 << " ";
	      else std::cout << 0 << " ";
	      if( a || (b && c)) std::cout << 1;
	      else std::cout << 0 << " ";
	      std::cout << std::endl;
	    }
	}
    }

  std::cout << (1 || 0 && 0) << std::endl;
  std::cout << (1 || 1 && 0) << std::endl;

  return 0;
}
