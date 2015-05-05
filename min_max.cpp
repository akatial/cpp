#include <algorithm>
#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>

#define N 10
#define UPPER 80
#define LOWER 20

int myrand()
{
  return static_cast<double>(rand()) / RAND_MAX * (UPPER - LOWER) + LOWER;
}

int main(void)
{
  srand(static_cast<unsigned>(time(NULL)));
  std::cout << RAND_MAX << std::endl;
  std::list<int> nums;
  for( int i = 0 ; i < N ; i++ )
    {
      nums.push_back(myrand());
    }
	
  // 最小値と最大値の位置を調べる
  std::list<int>::iterator min_it = std::min_element( nums.begin(), nums.end() );
  std::list<int>::iterator max_it = std::max_element( nums.begin(), nums.end() );
	
  // 結果を出力
  std::cout << "最小値" << *min_it << std::endl;
  std::cout << "最大値" << *max_it << std::endl;

  return 0;
}
