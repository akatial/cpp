#include <iostream>
#include <cmath>

using namespace std;

void spiral_search( int x, int y, int maxLength )
{
	const int dirs[ 4 ][ 2 ] = { { 0, 1 }, { -1, 0 }, { 0, -1 }, { 1, 0 } };
	int centerX  = x;
	int centerY  = y;
	int idir     = 0;
	int iside    = 0; 

	for( ;; ) 
	{
		int length = iside / 2 + 1;
		int nextPointX = x + length * dirs[ idir % 4 ][ 0 ];
		int nextPointY = y + length * dirs[ idir % 4 ][ 1 ];
		
		while( x != nextPointX || y != nextPointY ) 
		{
		  int xdist  = abs( centerX - x );
		  int ydist  = abs( centerY - y );
		  if( maxLength < xdist && maxLength < ydist ) 
		    goto escape;
		  x += dirs[ idir % 4 ][ 0 ];
		  y += dirs[ idir % 4 ][ 1 ];
		}
		idir  += 1;
		iside += 1;
		cout << "(" << nextPointX << ", " << nextPointY << ")" << endl;
	}
escape:
	return ;
}

int main(int argc, char **argv)
{
  int x, y, limit;
  cin >> x >> y >> limit; 
  spiral_search(x, y, limit);
  return 0;
}
