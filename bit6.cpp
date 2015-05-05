#include <iostream>

int main(void)
{
  int num;
  std::cin >> num;
  int cnt = 0;
  for( int i = num ; i ; i &= (i-1) ) 
    cnt++;
  std::cout << cnt << std::endl;
  return 0;
}
