#include <iostream>
#include <cmath>
#include <climits>

double ipower(double x, int y)
{
  double r = 1;
  int py = std::abs(y);
  while( py )
    {
      if( py & 1 ) 
	r *= x;
      x *= x;
      py >>= 1;
    }
  if( y >= 0 )
    return r;
  else
    return 1/ r;
}

double dpower(double x, double y)
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

double power(double x, double y)
{
  if( y <= INT_MAX && y >= -INT_MAX && y == (int)y )
    return ipower(x, y);
  if( x > 0 )
    return exp(y * log(x));
  else
    return dpower(x, y);
}

int main(void)
{
  double x, y, z;
  std::cin >> x >> y;
  z = power(x, y);
  std::cout << z << std::endl;
  return 0;
}
