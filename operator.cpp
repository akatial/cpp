#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#define N 10

/*
class Output
{
private:
public:
  void operator()(int num);
};

void Output::operator()(int num)
{
  std::cout << num << std::endl;
}
*/

void output(int num)
{
  std::cout << num << std::endl;
}

void output2(int num)
{
  std::cout << "[" << num  << "]" << std::endl;
}

int main(void)
{
  srand(static_cast<unsigned>(time(NULL)));
  std::vector<int> nums;
  for( int i = 0 ; i < N ; i++ )
    {
      nums.push_back(rand() % 100);
    }
  std::for_each(nums.begin(), nums.end(), output2);
  return 0;
}
