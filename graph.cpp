#include <iostream>
#include <cstdlib>
#include <ctime>

const int V = 5;

using namespace std;

int d[V][V];

int main(void)
{
  srand((unsigned int)time(NULL));
  for( int i = 0 ; i < V ; i++ )
    {
      for( int j = i ; j < V ; j++ )
	{
	  if( i == j )
	    d[i][j] = 0;
	  else
	    d[i][j] = d[j][i] = rand() % 100 + 1; 
	}
    }

  for( int i = 0 ; i < V ; i++ )
    {
      for( int j = 0 ; j < V ; j++ )
	{
	  cout << d[i][j] << " ";
	}
      cout << endl;
    }
  cout << endl;


  for( int k = 0 ; k < V ; k++ )
    {
      for( int i = 0 ; i < V ; i++ )
	{
	  for( int j = 0 ; j < V ; j++ )
	    {
	      d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	    }
	}
    }

  for( int i = 0 ; i < V ; i++ )
    {
      for( int j = 0 ; j < V ; j++ )
	{
	  cout << d[i][j] << " ";
	}
      cout << endl;
    }
  cout << endl;

  return 0;
}
