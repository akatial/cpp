#include <iostream>

int main(void)
{
  int w;
  std::cin >> w;
  bool **board = new bool*[w];
  for( int i = 0 ; i < w ; i = i + 1 )
    board[i] = new bool[w];

  bool value = true;
  for( int i = 0 ; i < w / 2 + 1 ; i = i + 1 )
    {
      for( int j = i ; j < w - i ; j = j + 1 )
	board[i][j] = board[j][i] = value;
      value = !value;
    }

  //value = true;
  for( int i = w - 1 ; i > w / 2 ; i = i - 1 )
    {
      for( int j = i ; j >= 0 + (w - i - 1); j = j - 1 )
	board[i][j] = board[j][i] = value;
      value = !value;
    }

  for( int i = 0 ; i < w ; i = i + 1 )
    {
      for( int j = 0 ; j < w ; j = j + 1 )
	std::cout << board[i][j];
      std::cout << std::endl;
    }

  for( int i = 0 ; i < w ; i = i + 1 ) 
    delete[] board[i];
  
  delete[] board;
  return 0;
}

/*
1111111
1000001
1011101
1010101
1011101
1000001
1111111
 */
