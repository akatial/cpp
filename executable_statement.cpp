#include <iostream>

#define N 100

int main(void)
{
  int cnt = 0;
  
  for( int i = 0 ; i < N ; i++ )
    {
      for( int j = i ; j < N ; j++ )
	{
	  cnt++;
	}
    } 
  std::cout << cnt << std::endl;
  return 0;
}
