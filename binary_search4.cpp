#include <iostream>
#include <random>
#include <algorithm>
#include <vector>

const int N = 10;

void print( const std::vector<int> &num )
{
  for ( int i = 0 ; i < N ; ++i )
    std::cout << num[i] << " ";
  std::cout << std::endl;
}

int main()
{
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(1,100);
  auto random_number = std::bind(distribution, generator);
  std::vector<int> num;
  for ( int i = 0 ; i < N ; ++i )
    num.push_back(random_number());
  print(num);
  std::stable_sort(num.begin(), num.end());
  print(num);

  int target;
  std::cin >> target;
  
  int min = 0;
  int max = N-1;
  int med;

  while ( min <= max )
    {
      med = (max + min ) / 2;
      if ( num[med] == target )
	{
	  std::cout << med << std::endl;break;
	}
      else if ( num[med] > target )
	max = med - 1;
      else if ( num[med] < target )
	min = med + 1;
    }
    

  return 0;
}
