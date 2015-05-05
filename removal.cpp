#include <iostream>
#include <limits>
#include <cmath>
#include <cstring>

const int N = 1000000;

double dx[4] = {0, 0.00001, 0, -0.00001};
double dy[4] = {-0.00001, 0, 0.00001, 0};

double calculate_distance(double x1, double y1, double x2, double y2)
{
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main(void)
{
  double ax[3], ay[3];
  std::cin >> ax[0] >> ay[0] >> ax[1] >> ay[1] >> ax[2] >> ay[2];
  double x = 0, y = 0;
  double d[4];
  double min_dis;
  int min_dir;
  for( int k = 0 ; k < N ; k++ )
    {
      min_dis = std::numeric_limits<double>::max();
      for( int i = 0 ; i < 4 ; i++ )
	{
	  d[i] = 0;
	}
      for( int i = 0 ; i < 4 ; i++ )
	{
	  double nx = x + dx[i];
	  double ny = y + dy[i];
	  for( int j = 0 ; j < 3 ; j++ )
	    {
	      d[i] += calculate_distance(nx, ny, ax[j], ay[j]);
	    }
	}
      for( int i = 0 ; i < 4 ; i++ )
	{
	  if( d[i] < min_dis )
	    {
	      min_dis = d[i];
	      min_dir = i;
	    }
	}
      x += dx[min_dir], y += dy[min_dir];
      std::cout << x << " " << y << std::endl;
    }
  return 0;
}
