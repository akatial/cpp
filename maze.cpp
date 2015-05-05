#include <cstdio>
#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

const int INF = 1000000;
const int MAX_N = 1000;
const int MAX_M = 1000;

typedef pair<int, int> P;
char maze[MAX_N][MAX_M];
int d[MAX_N][MAX_M];
int N, M, sx, sy, gx, gy;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(void)
{
  queue<P> que;

  for( int i = 0 ; i < N ; i++ )
    for( int j = 0 ; j < M ; j++ )
	d[i][j] = INF;


  que.push(P(sx, sy));
  d[sx][sy] = 0;

  while( que.size() )
  {
    P p = que.front(); que.pop();
    int x = p.first;
    int y = p.second;
    if( x == gx && y == gy ) break;

    for( int i = 0 ; i < 4 ; i++ )
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if( nx >= 0 && nx < N && ny >= 0 && ny < M && maze[nx][ny] != '#' && d[nx][ny] == INF) 
      {
	que.push(P(nx, ny));
	d[nx][ny] = d[x][y] + 1;
      }
    }
  }

  return d[gx][gy]; 
}

int main(void)
{
  //open file
  FILE *fp;

  fp = fopen("maze.in", "r");

  if( fp == NULL )
    return 1;

  //input data
  fscanf(fp, "%d %d %d %d %d %d", &N, &M, &sx, &sy, &gx, &gy); 
  for( int x = 0 ; x < N ; x++ )
    fscanf(fp, "%s", maze[x]);

  //printf("%d\n", bfs());
  bfs();
  
  fp = fopen("maze.out", "w");

  if( fp == NULL )
    return 1;

  for( int x = 0 ; x < N ; x++ )
  {
    for( int y = 0 ; y < M ; y++ )
    {
      if( d[x][y] != INF )
	fprintf(fp, "%3d ", d[x][y]);
      else
	fprintf(fp, "%3c ", 'N');
    }
    fprintf(fp, "\n");
  }
 
  return 0;
}
