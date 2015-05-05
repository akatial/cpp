#include <iostream>

#define SIZE 8
#define SUCCESS 0
#define FAILURE 1

using namespace std;

enum type {BLACK, WHITE, NONE};


int dir[8][2] = { {-1, -1}, {0, -1}, {1, -1},
		  {-1, 0},           {1, 0},
		  {-1, 1},  {0, 1},  {1, 1} };

int board[SIZE][SIZE];

void change_board(int X, int Y, bool turn, int dir_x, int dir_y)
{
  int x = X;
  int y = Y;
  while(board[x][y] != turn)
  {
    x += dir_x;
    y += dir_y;
    if(board[x][y] == !turn) board[x][y] = !turn;
  } 
}

int check_ligality(int X, int Y, bool turn)
{
  int x = X;
  int y = Y;
  for(int i = 0; i < 8; i++)
  {
    bool flag = false;
    while(true)
    {
      x += dir[i][0];
      y += dir[i][1];
      if(flag && board[x][y] == turn && board[x+dir[i][0]][y+dir[i][1]] == NONE)
      {
	change_board(X, Y, turn, dir[i][0], dir[i][1]);
	return 1;
      }
      if(x < 0 || x > SIZE || y < 0 || y > SIZE) break;;
      if(board[x][y] == NONE || board[x][y] == turn) break;
      if(board[x][y] == !turn) 
	{
	  flag = true;
	  continue;
	}
    }
  }
  return 0;
}

void display_board(void)
{
  cout << " ";
  for(int i = 0; i < SIZE; i++)
    cout << i + 1;
  cout << endl;

  for(int i = 0; i < SIZE; i++)
  {
    for(int j = 0; j < SIZE; j++)
    {
      if(j == 0) cout << i + 1;
      switch(board[i][j])
      {
      case NONE:
	cout << "-";
	break;
      case BLACK:
	cout << "x";
	break;
      case WHITE:
	cout << "o";
	break;
      }
    }
    cout << endl;
  }
}

void initialize_board(void)
{
  for (int i = 0; i < SIZE * SIZE; i++)
  {
    board[i / SIZE][i % SIZE] = NONE;
  }

  board[SIZE / 2 - 1][SIZE / 2] = BLACK;
  board[SIZE / 2][SIZE / 2 - 1] = BLACK;
  board[SIZE / 2 - 1][SIZE / 2 - 1] = WHITE;
  board[SIZE / 2][SIZE / 2] = WHITE;
}

int main(int argc, char **argv)
{
  initialize_board();
 
  bool turn = WHITE;
  while(true)
  {
    display_board();
    
    cout << "どこにおく? 半角で整数(横軸) 整数(縦軸)" << endl;
    int X, Y;
    cin >> X >> Y;
    if(X < 1 || X > SIZE || Y < 1 || Y > SIZE) 
    {
	cout << "{X, Y|1≦X≦8, 1≦Y≦8, XとYはともに整数}" << endl;
	continue;
    }
    if(board[X][Y] != NONE) 
    {
      cout << "既に置いてあるので置けないよ。ほかの所を選んでね" << endl;
      continue;
    }
    
    check_ligality(X, Y, turn);
    /*
    if(check_ligality(X, Y, turn))
    {
      cout << "合法手ではないので置けないよ。ほかの所を選んでね" << endl;
    }
    */

  }

  return SUCCESS;
}
