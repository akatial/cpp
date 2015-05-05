#include <iostream>

const int N = 1 << 7;

int main(void)
{
  for( int i = 1 ; i <= N ; i++ )
    {
      for( int j = N ; j > 0 ; j = j >> 1 )
	{
	  if( i & j )
	    std::cout << 1;
	  else
	    std::cout << 0;
	}
      std::cout << " -> ";
      int k = i & (i - 1);
      for( int j = N ; j > 0 ; j = j >> 1 )
	{
	  if( k & j )
	    std::cout << 1;
	  else
	    std::cout << 0;
	}
      std::cout << std::endl;
    }

  return 0;
}
