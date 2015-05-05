#include <iostream>

const int N = 5;

int main(void)
{
  int array[N][N];

  for( int i = 0 ; i < N ; i++ )
    {
      for( int j = 0 ; j < N ; j++ )
	{
	  if( j == 0 )
	    {
	      array[i][j] = 1;
	    }
	  else
	    {
	      array[i][j] = 0;
	    }
	}
    }

  for( int i = 0 ; i < N ; i++ )
    {
      for( int j = 0 ; j < N ; j++ )
	{
	  std::cout << array[i][j];
	}
    }
  std::cout << std::endl;

  unsigned long long int binary_digit_string = 0;
  for( int i = 0 ; i < N ; i++ )
    {
      for( int j = 0 ; j < N ; j++ )
	{
	  binary_digit_string >>= 1;
	  binary_digit_string |= (unsigned long long int)(array[i][j]<<(N*N-1));
      }
    }
  for( int i = 1, j = 0 ; j != N * N ; i = i << 1, j++ )
    {
      if( binary_digit_string & i )
	{
	  std::cout << 1; 
	}
      else
	{
	  std::cout << 0;
	}
    }
  std::cout << std::endl;

  return 0;
}
