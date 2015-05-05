#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <ctime>

///////////////////////////////////////////////////

#define SIZE  8
#define FIRST 0
#define LAST  1
#define	RSIZE 256  

#define NO_LINE (-1)
#define NO_VALUE  10000

#define MAX_VALUE 1000
#define MIN_VALUE (-1000)

#define N 624
#define M 397

#define MATRIX_A 0x9908b0dfUL
#define UPPER_MASK 0x80000000UL 
#define LOWER_MASK 0x7fffffffUL 

#define MAX_LIMIT (MAX_VALUE + 1000)
#define MIN_LIMIT (MIN_VALUE - 1000)

#define RAND_MAX_NUM (1 << 31)

#define GET_X( C )      ((C) >> 8)
#define GET_Y( C )      ((C) & 0xff)
#define MAKE_XY( X, Y ) (((X) << 8) + (Y))

///////////////////////////////////////////////////

int board[SIZE][SIZE];    
unsigned long mt[N]; 

int first_value = 0;
int last_value = 0;
int depth = 5;         
int mti = N + 1; 
int count = 0; 

///////////////////////////////////////////////////

void init_genrand(unsigned long s);
void init_by_array(unsigned long init_key[], int key_length);
unsigned long genrand_int32(void);
void print_board( void );
int finish_value( void );
int check_finish( int x, int y );
int select_last( int cdepth, int prev_move, int limit, int *move );
int select_first( int cdepth, int prev_move, int limit, int *move );
void play( void );
void init_board( void );
void set_depth( int num, char *param );

///////////////////////////////////////////////////

void init_genrand(unsigned long s)
{
  mt[0] = s & 0xffffffffUL;
  for( mti = 1 ; mti < N ; mti++ ) 
    {
      mt[mti] = (1812433253UL * (mt[mti-1] ^ (mt[mti-1] >> 30)) + mti); 
      mt[mti] &= 0xffffffffUL;
    }
}

void init_by_array(unsigned long init_key[], int key_length)
{
  int i, j, k;
  init_genrand(19650218UL);
  i=1; j=0;
  k = (N>key_length ? N : key_length);
  for (; k; k--) {
    mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1664525UL))
      + init_key[j] + j; 
    mt[i] &= 0xffffffffUL;
    i++; j++;
    if (i>=N) { mt[0] = mt[N-1]; i=1; }
    if (j>=key_length) j=0;
  }
  for (k=N-1; k; k--) {
    mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1566083941UL))
      - i;
    mt[i] &= 0xffffffffUL; 
    i++;
    if (i>=N) { mt[0] = mt[N-1]; i=1; }
  }

  mt[0] = 0x80000000UL; 
}


unsigned long genrand_int32(void)
{
  unsigned long y;
  static unsigned long mag01[2]={0x0UL, MATRIX_A};

  if (mti >= N) {
    int kk;

    if (mti == N+1)
      init_genrand(5489UL); 

    for (kk=0;kk<N-M;kk++) {
      y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
      mt[kk] = mt[kk+M] ^ (y >> 1) ^ mag01[y & 0x1UL];
    }
    for (;kk<N-1;kk++) {
      y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
      mt[kk] = mt[kk+(M-N)] ^ (y >> 1) ^ mag01[y & 0x1UL];
    }
    y = (mt[N-1]&UPPER_MASK)|(mt[0]&LOWER_MASK);
    mt[N-1] = mt[M-1] ^ (y >> 1) ^ mag01[y & 0x1UL];

    mti = 0;
  }
  
  y = mt[mti++];

  y ^= (y >> 11);
  y ^= (y << 7) & 0x9d2c5680UL;
  y ^= (y << 15) & 0xefc60000UL;
  y ^= (y >> 18);

  return y;
}

void print_board( void )
{
  int x, y;
  printf("\n   ");
  for( x = 0; x < SIZE; x++ )
    {
      printf("%3d", x );
    }
  printf("\n");
  for( y = 0; y < SIZE; y++ )
    {
      for( x = 0; x < SIZE; x++ )
	{
	  if( x == 0 ) printf("%3d", y);
	  if( board[x][y] == NO_VALUE )
	    {
	      printf( " **" );
	    } 
	  else 
	    {
	      printf( "%3d", board[x][y] );
	    }
	}
      printf("\n");
    }
}


int finish_value( void )
{
  if( first_value > last_value )
    return MAX_VALUE + first_value - last_value;
  else if( first_value < last_value )
    return MIN_VALUE + first_value - last_value;
  else 
    return 0;
}

int check_finish( int x, int y )
{
  int xf = 0, yf = 0;
  for(int i = 0; i < SIZE; i++ )
    {
      if( board[x][i] != NO_VALUE ) xf = 1;
      if( board[i][y] != NO_VALUE ) yf = 1;
    }
  if( xf == 0 || yf == 0 ) return true;
  return false;
}

int select_last( int cdepth, int prev_move, int limit, int *move )
{
  if( cdepth == depth )
    return first_value - last_value;
  int px = GET_X( prev_move );
  int value = MAX_LIMIT;
  for(int y = 0; y < SIZE; y++ )
    {
      if( board[px][y] != NO_VALUE )
	{
	  int v;
	  int m;
	  int save_board = board[px][y];
	  int save_value = last_value;
	  last_value += board[px][y];
	  board[px][y] = NO_VALUE;
	  count++;
	  if( check_finish( px, y ) )
	    v = finish_value();
	  else 
	    v = select_first( cdepth + 1, MAKE_XY( px, y ), value, &m );
	  board[px][y] = save_board;
	  last_value = save_value;
	  if( v < value )
	    {
	      value = v;
	      *move = MAKE_XY( px, y );
	    }
	  if( value < limit ) break;
	}
    }
  return value;
}

int select_first( int cdepth, int prev_move, int limit, int *move )
{
  if( cdepth == depth )
    return first_value - last_value;
  int py = GET_Y( prev_move );
  int value = MIN_LIMIT;
  for(int x = 0; x < SIZE; x++ )
    {
      if( board[x][py] != NO_VALUE )
	{
	  int v;
	  int m;
	  int save_board = board[x][py];
	  int save_value = first_value;
	  first_value += board[x][py];
	  board[x][py] = NO_VALUE;
	  count++;
	  if( check_finish( x, py ) )
	    v = finish_value();
	  else 
	    v = select_last( cdepth + 1, MAKE_XY( x, py ), value, &m );
	  board[x][py] = save_board;
	  first_value = save_value;
	  if( v > value )
	    {
	      value = v;
	      *move = MAKE_XY( x, py );
	    }
	  if( value > limit ) break;
	}
    }
  return value;
}


void play( void )
{
  int prev_move = 0;
  int turn = 1;
  while(true)
    {
      int move, x, y;
      if( turn & 0x01 )
	{
	  select_first( 0, prev_move, MAX_LIMIT, &move );
	  x = GET_X( move );
	  y = GET_Y( move );
	  print_board();
	  printf( "先手 (%d,%d) %d を選びます：", x, y, board[x][y] );
	  first_value += board[x][y];
	} 
      else 
	{
	  select_last( 0, prev_move, MIN_LIMIT, &move );
	  x = GET_X( move );
	  y = GET_Y( move );
	  print_board();
	  printf( "後手 (%d,%d) %d を選びます：", x, y, board[x][y] );
	  last_value += board[x][y];
	}
      board[x][y] = NO_VALUE;
      prev_move = move;
      printf("先手 %3d 点 : 後手 %3d 点 \n", first_value, last_value );
      turn++;
      if( check_finish( x, y ) )
	{
	  printf("試合終了\n");
	  break;
	}
    }
}


void set_depth(int num, char *param )
{
  if( num > 2 ) 
    {
      fprintf(stderr, "使い方 ./実行ファイル名 読みの深さ\n");
      exit( EXIT_FAILURE );
    }
  int lv = atoi( param );
  if( lv < 1 || lv > 10 )
    {
      fprintf( stderr, "読みの深さは 1 - 10 を指定してください\n" );
      exit( EXIT_FAILURE );
    }
  depth = lv;
}

void init_board( void )
{
  for( int x = 0 ; x < SIZE ; x++ )
    {
      for( int y = 0 ; y < SIZE ; y++ )
	{
	  int n = genrand_int32();
	  if( n % 2 )
	    {
	      board[x][y] = - (n % 9 + 1);
	    } 
	  else 
	    {
	      board[x][y] = n % 9 + 1;
	    }
	}
    }
}

int main( int argc, char **argv )
{
  init_genrand( (unsigned)time( NULL ) );
  init_board();
  if( argc > 1 )
    set_depth(argc, argv[1]);
  play();
  printf("局面数 %d\n", count );
  return 0;
}
