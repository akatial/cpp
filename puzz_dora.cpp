#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
  for( int i = 1 ; i < 21 ; i++ )
    {
      cout << i << ":" << 30 * pow(3, i) << endl;
    }
  return 0;
}
