#include <stdio.h>

#define MAX_X 3
#define MAX_Y 3

enum type{MARU, BATU, NONE};

int main(void)
{
  int board[MAX_X][MAX_Y];
  bool turn = MARU;
  
  for(int x = 0; x < MAX_X; x++){
    for(int y = 0; y < MAX_Y; y++){
      board[x][y] = NONE;
    }
  }

  while(1){
    int posX, posY;
    char buf[256];
    printf("どこにおく？半角で\"整数(縦軸) 整数(横軸)\"\n");
    gets(buf);
    sscanf(buf,"%d %d", &posX, &posY);

    if(posX < 1 || posX > 3 || posY < 1 || posY > 3) { puts("XもYも1~3の整数で回答してね。"); continue; }
    if(board[posX-1][posY-1] != NONE) { puts("そこには既に置いてあるよ。ほかの所を選んでね。"); continue; }
    
    if(turn == MARU) board[posX-1][posY-1] = MARU; 
    if(turn == BATU) board[posX-1][posY-1] = BATU;
    
    printf("-------------------------------------------------------------------\n");
    printf("　１２３\n");
    for(int x = 0; x < MAX_X; x++)
      {
	switch(x){
	case 0:
	  printf("１");
	  break;
	case 1:
	  printf("２");
	  break;
	case 2:
	  printf("３");
	  break;
	}
	for(int y = 0; y < MAX_Y; y++)
	  {
	    if(board[x][y] == NONE) printf("　");
	    if(board[x][y] == MARU) printf("◯ ");
	    if(board[x][y] == BATU) printf("× ");
	  }
	printf("\n");
      }
    printf("-------------------------------------------------------------------\n");
    
    //勝敗判定
    if(board[0][0] == turn && board[1][1] == turn && board[2][2] == turn){ printf("%s WIN\n", turn?"BATU":"MARU"); break; }
    if(board[0][2] == turn && board[1][1] == turn && board[2][0] == turn){ printf("%s WIN\n", turn?"BATU":"MARU"); break; }
    if(board[0][0] == turn && board[0][1] == turn && board[0][2] == turn){ printf("%s WIN\n", turn?"BATU":"MARU"); break; }
    if(board[1][0] == turn && board[1][1] == turn && board[1][2] == turn){ printf("%s WIN\n", turn?"BATU":"MARU"); break; }
    if(board[2][0] == turn && board[2][1] == turn && board[2][2] == turn){ printf("%s WIN\n", turn?"BATU":"MARU"); break; }
    if(board[0][0] == turn && board[1][0] == turn && board[2][0] == turn){ printf("%s WIN\n", turn?"BATU":"MARU"); break; }
    if(board[0][1] == turn && board[1][1] == turn && board[2][1] == turn){ printf("%s WIN\n", turn?"BATU":"MARU"); break; }
    if(board[0][2] == turn && board[1][2] == turn && board[2][2] == turn){ printf("%s WIN\n", turn?"BATU":"MARU"); break; }
    
    //引き分けかどうか
    bool draw = true;
    for(int x = 0; x < MAX_X; x++){
      for(int y = 0; y < MAX_Y; y++){
	if(board[x][y] == NONE){ draw = false; goto escape;}
      }
    }
    escape:
    if(draw){ printf("GAME DRAW\n"); break;}

    turn = !turn;

  }
  
  return 0;
}

