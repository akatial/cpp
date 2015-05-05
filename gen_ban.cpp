#include <cstdio>

#define N 5
#define M 6

int main(void)
{
  for( int y = 0 ; y < N ; y++ )
    {
      for( int x = 0 ; x < M ; x++ )
	{
	  printf("color[%d][%d] = ;\n", y, x);
	}
    }
  return 0;
}
