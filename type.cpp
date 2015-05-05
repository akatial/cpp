#include <iostream>

using namespace std;

int main(void)
{
  double n;
  cin >> n;
  if( n >= -32768 && n <= 32767 )
    cout << "int" << endl;
  else if( n >= 0 && n <= 65535 )
    cout << "unsigned int" << endl;
  else if( n >= -2147483648 && n <= 2147483647 )
    cout << "long" << endl;
  else if( n >= 0 && n <= 4294967295 )
    cout << "unsigned long" << endl;
  else 
    cout << "too big or too small" << endl;
  return 0;
}


/*
int main(void)
{
  char c;
  unsigned short n;
  for( unsigned short i = 32 ; i < 127 ; i++ )
    {
      n = i;
      c = i;
      cout << n << ":" << c << endl;
    }
  return 0;
}
*/
