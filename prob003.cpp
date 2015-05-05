#include <cstdio>

const int MAX_N = 1000000;

int max(int x, int y)
{
  if(x > y) return x;
  else return y;
}

int min(int x, int y)
{
  if(x < y) return x;
  else return y;
}


int main(void)
{
  int L, n;
  int X[MAX_N];

  FILE *fp;

  if((fp = fopen("prob003.in", "r")) == NULL){
    printf("file open error");
    return 1;
  }

  fscanf(fp, "%d %d", &L, &n);
  for(int i = 0; i < n; i++)
    fscanf(fp, "%d", &X[i]);

  int minT = 0;
  for(int i = 0; i < n; i++){
    minT = max(minT, min(X[i], L - X[i]));
  }

  int maxT = 0;
  for(int i = 0; i < n; i++){
    maxT = max(maxT, max(X[i], L - X[i]));
  }

  printf("min:%d max:%d \n", minT, maxT);
  
}
