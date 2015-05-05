#include <cstdio>
#include <cstdlib>
#include <ctime>

///////////////////////////////////////////////////////////////

#define BAN_SIZE 8
#define	BUF_SIZE 256
#define NO_VALUE  10000
#define MAX_VALUE 1000
#define MIN_VALUE (-1000)

#define GET_I( C )      ((C) >> 8)
#define GET_J( C )      ((C) & 0xff)
#define MAKE_IJ( I, J ) (((I) << 8) + (J))

///////////////////////////////////////////////////////////////

int board[BAN_SIZE][BAN_SIZE];    
int first_value = 0;
int last_value = 0;
int depth = 3;            

///////////////////////////////////////////////////////////////

void set_depth( char *sdepth );
void init_board( void );
void play_game( void );
void print_board( int line );
int input_number( int i );
int select_first( int cdepth, int prev_move, int *move );
int select_last( int cdepth, int prev_move, int *move );
int calc_value( void );
int check_finish( int i, int j );

///////////////////////////////////////////////////////////////

int main( int argc, char *argv[] )
{
  if( argc == 2 )
    set_depth(argv[1]);
  init_board();
  play_game();
  return 0;
}

void set_depth( char *sdepth )
{
  int ndepth = atoi( sdepth );
  if( ndepth == 0 ) 
    {
      fprintf(stderr, "オプションには自然数を指定して下さい\n");
      exit( EXIT_FAILURE );
    }
  depth = ndepth;
}


void init_board( void )
{
  srand( time( NULL ) );
  for( int i = 0 ; i < BAN_SIZE ; i++ )
    {
      for( int j = 0 ; j < BAN_SIZE; j++ )
	{
	  int n = rand();
	  if( n > ( RAND_MAX >> 1 ) )
	    board[i][j] = - (n % 9 + 1);
	  else 
	    board[i][j] = n % 9 + 1;
	}
    }
}


void play_game( void )
{
  int prev_move = 0;
  int turn = 1;
  while( true )
    {
      int move, i, j;
      if( turn % 2 )
	{
	  i = GET_I( prev_move );
	  print_board( i );
	  move = input_number( i );
	  j = GET_J( move );
	  printf( "先手 (%d, %d) %d を選びます：", i, j, board[i][j] );
	  first_value += board[i][j];
	} 
      else 
	{
	  select_last( 0, prev_move, &move );
	  i = GET_I( move );
	  j = GET_J( move );
	  printf( "後手 (%d, %d) %d を選びます：", i, j, board[i][j] );
	  last_value += board[i][j];
	}
      board[i][j] = NO_VALUE;
      prev_move = move;
      printf("先手 %3d 点 : 後手 %3d 点 \n", first_value, last_value );
      turn++;
      if( check_finish( i, j ) )
	{
	  printf("試合終了\n");
	  break;
	}
    }
}

void print_board( int line )
{
  printf("\n    ");
  for( int i = 0 ; i < BAN_SIZE ; i++ )
    printf("%3d", i );
  printf("\n");
  for( int i = 0; i < BAN_SIZE; i++ )
    {
      printf(" %c %d", ( line == i ? '[' : ' ' ), i );
      for( int j = 0; j < BAN_SIZE; j++ )
	{
	  if( board[i][j] == NO_VALUE )
	    printf( " **" );
	  else 
	    printf( "%3d", board[i][j] );
	}
      printf(" %c", ( line == i ? ']' : ' ' ) );
      printf("\n");
    }
}


int input_number( int i )
{
  int pos;
  char buf[BUF_SIZE];
  while( true )
    {
      if( fgets( buf, BUF_SIZE, stdin ) != NULL )
	{
	  if( sscanf( buf, "%d", &pos ) )
	    {
	      if( 0 <= pos && pos <= 7 )
		{
		  if( board[i][pos] == NO_VALUE )
		    {
		      printf("%d には数字がありません\n", pos );
		      continue;
		    }
		  break;
		}
	    }
	}
      printf("\n入力エラー：0 - 7 の数値を入力してください\n");
    }
  return MAKE_IJ(i, pos);
}


int select_first( int cdepth, int prev_move, int *move )
{
  if( cdepth == depth )
    return first_value - last_value;
  int pi = GET_I( prev_move );
  int value = NO_VALUE;
  for( int j = 0; j < BAN_SIZE; j++ )
    {
      if( board[pi][j] != NO_VALUE )
	{
	  int v;
	  int m;
	  int save_board = board[pi][j];
	  int save_value = first_value;
	  first_value += board[pi][j];
	  board[pi][j] = NO_VALUE;
	  if( check_finish( pi, j ) )
	    v = calc_value();
	  else 
	    v = select_last( cdepth + 1, MAKE_IJ( pi, j ), &m );
	  if( value == NO_VALUE || v > value )
	    {
	      value = v;
	      *move = MAKE_IJ( pi, j );
	    }	
	  board[pi][j] = save_board;
	  first_value = save_value;
	}
    }
  return value;
}

int select_last( int cdepth, int prev_move, int *move )
{
  if( cdepth == depth )
    return first_value - last_value;
  int pj = GET_J( prev_move );
  int value = NO_VALUE;
  for(int i = 0; i < BAN_SIZE; i++ )
    {
      if( board[i][pj] != NO_VALUE )
	{
	  int v;
	  int m;
	  int save_board = board[i][pj];
	  int save_value = last_value;
	  last_value += board[i][pj];
	  board[i][pj] = NO_VALUE;
	  if( check_finish( i, pj ) )
	    v = calc_value();
	  else 
	    v = select_first( cdepth + 1, MAKE_IJ( i, pj ), &m );
	  if( value == NO_VALUE || v < value )
	    {
	      value = v;
	      *move = MAKE_IJ( i, pj );
	    }
	  board[i][pj] = save_board;
	  last_value = save_value;
	}
    }
  return value;
}



int calc_value( void )
{
  if( first_value > last_value )
    return MAX_VALUE + first_value - last_value;
  else if( first_value < last_value )
    return MIN_VALUE + first_value - last_value;
  else 
    return 0;
}

int check_finish( int i, int j )
{
  int ci = 0, cj = 0;
  for( int k = 0; k < BAN_SIZE; k++ )
    {
      if( board[i][k] != NO_VALUE ) ci += 1;
      if( board[k][j] != NO_VALUE ) cj += 1;
    }
  if( ci == 0 || cj == 0 ) return true;
  return false;
}
