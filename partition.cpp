#include <iostream>
const int N = 11;
using namespace std;

int divide(int n);
static int divide_sub(int n, int k);

int main(void)
{
  int i;
  for( i = 1 ; i < N ; i++)
    {
      cout << divide(i) << endl;
    }
  return 0;
}

int divide(int n)
{
  return divide_sub(n,n);
}

static int divide_sub(int n, int k)
{
  int i, s;

  if( n < 0 ) return 0;
  if( n <= 1 || k == 1) return 1;
  s = 0;
  for( i = 1 ; i <= k ; i++ )
    {
      s += divide_sub(n - i, i);
    }
  return s;
}
