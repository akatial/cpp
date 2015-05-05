#include <cstdio>

const int MAX = 10;
int n, k, a[MAX];

bool dfs(int i, int sum)
{
  if(i == n) return sum == k;

  if(dfs(i+1, sum)) return true;
  if(dfs(i+1, sum+a[i])) return true;

  return false;
}

int main(void)
{
  FILE *fp;

  fp = fopen("data.in", "r");

  if(fp == NULL){
    puts("file open error");
    return 1;
  }

  fscanf(fp, "%d %d", &n, &k);
  for(int i = 0; i < n; i++)
    fscanf(fp, "%d", &a[i]);

  if(dfs(0, 0)) puts("Yes");
  else puts("No");

}
