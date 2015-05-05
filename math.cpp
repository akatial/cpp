#include <iostream>

using namespace std;

int main(void)
{
  int num = 5688;
  int quotient;
  int surplus;
  for( int i = 10 ; i <= 99 ; i++ )
    {
      quotient = num / i;
      surplus = num % i;
      if( quotient == surplus)
	cout << i << endl;
    }
  return 0;
}
