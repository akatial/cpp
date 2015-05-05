#include <iostream>
#include <cstdlib>
#include <ctime>

enum dir{ EAST, WEST, SOUTH, NORTH };

int main(void)
{
  srand(static_cast<unsigned int>(time(NULL)));
  
  int w;
  std::cin >> w;
  bool **board = new bool*[w];
  for( int i = 0 ; i < w ; i = i + 1 )
    board[i] = new bool[w];
  
  for( int i = 0 ; i < w ; i = i + 1 )
    for( int j = 0 ; j < w ; j = j + 1 )
      board[i][j] = true;
  
  
  int i = w / 2;
  int j = w / 2;
  int dir;
  while( i >= 0 && i < w && j >= 0 && j < w )
    {
      board[i][j] = false;
      dir = rand() % 4;
      switch(dir)
	{
	case EAST:
	  i = i + 1;
	  break;
	case WEST:
	  i = i - 1;
	  break;
	case SOUTH:
	  j = j + 1;
	  break;
	case NORTH:
	  j = j - 1;
	  break;
	}
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
  
  
    
