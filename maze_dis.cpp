#include <iostream>
#include <string>
#include <queue>

typedef std::pair<int, int> P;
const int MAX_N = 100;
const int MAX_M = 100;
const int INF = 1000000000;
const int D = 4;
int di[D] = {-1, 0, 0, 1};
int dj[D] = {0, -1, 1, 0};

int N, M;
int sx, sy;
int gx, gy;
char field[MAX_N][MAX_M+1];
int d[MAX_N][MAX_M+1];

int bfs()
{
  std::queue<P> que;
  
  for ( int i = 0 ; i < N ; i = i + 1 )
    {
      for ( int j = 0 ; j < M ; j = j + 1 )
	{
	  d[i][j] = INF;
	}
    }
  que.push(P(sx, sy));
  d[sx][sy] = 0;

  while ( que.size() )
    {
      P p = que.front(); que.pop();
      if ( p.first == gx && p.second == gy ) 
	break;
      for ( int dd = 0 ; dd < D ; dd = dd + 1 )
	{
	  int ni = p.first + di[dd];
	  int nj = p.second + dj[dd];
	  if ( 0 <= ni && ni < N && 0 <= nj && nj < M && field[ni][nj] != '#' && d[ni][nj] == INF )
	    {
	      que.push(P(ni, nj));
	      d[ni][nj] = d[p.first][p.second] + 1;
	    }
	}
    }
  return d[gx][gy];
}

int main()
{
  std::cin >> N >> M;
  std::cin >> sx >> sy >> gx >> gy;
  int i = 0;
  std::string line;
  while ( std::getline(std::cin, line) )
    {
      for ( int j = 0 ; j < M ; j = j + 1 )
	{
	  field[i][j] = line[j];
	}
      i++;
    }
  
  std::cout << bfs() << std::endl;
  return 0;
}
