#include <iostream>
#include <cmath>

#define EPS 1.0e-10

using namespace std;

int main(void)
{
  double left = 0.0;
  double right = 1.0;
  double x = left + right / 2.0;
  while( true )
    {
      if( x*x*x + x*x + x > 1)
	  right = x;
      else if( x*x*x + x*x + x < 1 )
	  left = x;
      else if( fabs(x*x*x + x*x + x - 1) < EPS )
	{
	  cout << x << endl;
	  break;
	}
      x = (left + right) / 2.0;
    } 
  return 0;
}
