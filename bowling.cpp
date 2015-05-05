#include <iostream>

void out(int n, int t)
{
  for( int i = 0 ; i < t ; i++ )
    std::cout << n;
}

int main(void)
{
  int w;
  std::cin >> w;
  for( int i = 1 ; i < w / 2 ; i = i + 1 )
    out(1, i), out(0, w - i * 2), out(1, i), std::cout << std::endl;
  out(1, w), std::cout << std::endl;
  for( int i = w / 2 - 1 ; i > 0 ; i = i - 1 )
    out(1, i), out(0, w - i * 2), out(1, i), std::cout << std::endl;
  return 0;
}

/*
10000001
11000011
11100111
11111111
11100111
11000011
10000001



 */

/*
int main(void)
{
  int w;
  std::cin >> w;
  for( int i = 1 ; i < w + 1 ; i = i + 1 )
    out(0, w-i), out(1, i), std::cout << std::endl;
  
  return 0;
}

*/
/*
0000000000
0000000001
0000000011
0000000111
0000001111
0000011111
0000111111
0001111111
0011111111
0111111111
1111111111
 */
