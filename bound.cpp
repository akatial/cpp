#include <iostream>
#include <deque>
#include <algorithm>

int main(void)
{
  std::deque<int> nums;
  /*
  for( int i = 0 ; i < 10 ; i++ )
    {
      nums.push_back(i*2);
    }
  //std::deque<int>::iterator it = std::lower_bound(nums.begin(), nums.end(), 7);
  //std::deque<int>::iterator it = std::upper_bound(nums.begin(), nums.end(), 6);
  //nums.insert(it, 7);
  */
  nums.push_back(7);
  nums.push_back(10);
  nums.push_back(10);
  nums.push_back(10);
  nums.push_back(10);
  nums.push_back(12);
  std::pair< std::deque<int>::iterator, std::deque<int>::iterator > range;
  range = std::equal_range( nums.begin(), nums.end(), 10);
  std::cout << std::distance(range.first, range.second) << std::endl;
  /*
  for( int tmp : nums)
    {
      std::cout << tmp << std::endl;
    }
  */
  return 0;
}
