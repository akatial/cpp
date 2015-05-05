#include <cstdio>

const int MAX_N = 100;
const int MAX_M = 100;

int N, M;
char field[MAX_N][MAX_M];

void dfs(int x, int y)
{
  field[x][y] = '.';
  
  for(int dx = -1; dx <= 1; dx++){
    for(int dy = -1; dy <= 1; dy++){
      if(dx == 0 && dy == 0) continue;
      int nx = x + dx, ny = y + dy;
      if(nx < 0 && nx >= N && ny < 0 && ny >= M) continue;
      if(field[nx][ny] == 'W') dfs(nx, ny);
    }
  }
}  

int main(void)
{
  FILE *fp;

  fp = fopen("lake_count3.in", "r");
  fscanf(fp, "%d %d", &N, &M);
  for(int i = 0; i < N; i++){
      fscanf(fp,"%s", field[i]);
      printf("%s\n", field[i]);
  }
  
  int ans = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(field[i][j] == 'W'){
	dfs(i, j);
	ans++;
      }
    }
  }

  printf("answer:%d\n", ans);
  
  return 0;
  
}
