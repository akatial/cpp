#include <iostream>

double power(int x, int y)
{
  double r = 1;
  if( y >= 0 )
    {
      for( int i = 0 ; i < y ; i++ )
	  r *= x;
    }
  else
    {
      for( int i = 0 ; i > y ; i-- )
	r /= x;
    }
  return r;
}

int main(void)
{
  int x, y;
  double z;
  std::cin >> x >> y;
  z = power(x, y);
  std::cout << z << std::endl;
}
