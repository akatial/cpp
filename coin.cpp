#include <cstdio>

int min(int x, int y)
{
  if(x < y) return x;
  else return y;
}

int main(void)
{
  FILE *fp;

  fp = fopen("coin.in", "r");

  if(fp == NULL)
    puts("file open error");
  
  int V[6] = {1, 5, 10, 50, 100, 500};
  int num[6] = {0};
  int pay = 0;
 
  fscanf(fp, "%d", &pay);
  for(int i = 0; i < 6; i++)
    fscanf(fp, "%d", &num[i]);

  fclose(fp);

  int ans = 0;
  for(int i = 5; i >=0; i--){
    int k = min(pay/V[i], num[i]);
    pay -= k * V[i];
    ans += k;
  }
  printf("%d\n", ans);
  
  return 0;
}
