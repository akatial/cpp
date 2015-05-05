#include <iostream>

using namespace std;

int main(void)
{
  double sum = 0 ;
  for( int i = 0 ; i < 1000000000 ; i++ )
    sum += i;
  cout << sum << endl;
  return 0;
}
