#include <iostream>
#include <algorithm>
#include <list>
#include <cstdlib>
#include <ctime>

#define N 100

int main(void)
{
  srand(static_cast<unsigned>(time(NULL)));
  std::list<int> nums;
  for( int i = 0 ; i < N ; i++ )
    {
      nums.push_back(rand() % 100);
    }
  std::cout << std::count(nums.begin(), nums.end(), 42) << std::endl;
  return 0;
}
