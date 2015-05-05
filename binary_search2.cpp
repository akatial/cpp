#include <iostream>
#include <deque>
#include <algorithm>
#include <ctime>
#define N 100

int main(void)
{
    std::deque<int> nums;
    srand(static_cast<unsigned>(time(NULL)));
    for( int i = 0 ; i < N ; i++ )
    {
        nums.push_back(rand() % 100);
    }
    std::sort(nums.begin(), nums.end());
    /*for( int tmp : nums )
    {
        std::cout << tmp << " ";
    }*/
    if(std::binary_search(nums.begin(), nums.end(), 30))
    {
        std::cout << "found!" << std::endl;
    }
    else
    {
        std::cout << "not found!" << std::endl;
    }
    return 0;
}
