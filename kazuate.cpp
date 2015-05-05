#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
  int prospect;
  int answer;
  srand((unsigned int)time(NULL));
  answer = rand() % 100 + 1;
  while( true )
    {
      std::cin >> prospect;
      if( prospect < answer ) 
	std::cout << "もっと大きいよ！" << std::endl;
      else if( prospect > answer)
	std::cout << "もっと小さいよ!" << std::endl;
      else 
	{
	  std::cout << "お見事！" << std::endl;
	  break;
	}
    }
  return 0;
}
