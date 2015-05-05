#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
  int bits;
  cin >> bits;
  bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
  bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
  bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
  bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
  cout << (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff) << endl;

  /*
    int num;
    cin >> num;
    int cnt = 0;
    for( int mask = 1 ; mask != 0 ; mask = mask << 1 )
    {
    if( num & mask ) cnt++;
    }
    cout << cnt << endl;
  */
  /*
    int a;
    a = 6 & 12;
    cout << a << endl;
    a = ~4;
    cout << a << endl;
    a = (3 | 4 ) << 2;
    cout << a << endl;
    a = 5 ^ 3;
    cout << a << endl;
  */
  /*
    for( int i = 0 ; i < 10 ; i++ )
    {
    cout << ~11 << endl;
    }
  */
  /*
    int n = 16;
    int m = n || 1;
    cout << m << endl;
  */
  /*
    int n = 0;
    n |= 1;
    n <<= 1;
    n |= 1;
    n <<= 1;
    n |= 1;
    n &= 7;
    n &= ~7;
    cout << n << endl;
    bool a = true;
    bool b = false;
    if ( a ^ b ) cout << "different" << endl;
    else cout << "same" << endl;
  */
  return 0;
}
