#include <cstdio>
#include <limits.h>

const int MAX_I = 1000000;

int max(int x, int y)
{
  if(x > y) return x;
  else return y;
}

int main(void)
{
  FILE *fp;

  if((fp = fopen("prob002.in","r")) == NULL){
    fprintf(stdout, "file open error");
    return 1;
  }
  
  int n, k[MAX_I];
  
  fscanf(fp, "%d", &n);
  for(int i = 0; i < n; i++)
    fscanf(fp, "%d", &k[i]);

  fclose(fp);

  bool f = false;
  int ans = 0;
  int max_side = INT_MIN;
  int rest_side = 0;
  int len = 0;

  for(int a = 0; a < n; a++){
    for(int b = a+1; b < n; b++){
      for(int c = b+1; c < n; c++){
	max_side = max(k[a], max(k[b], k[c]));
	len = k[a] + k[b] + k[c];
	rest_side = len - max_side;
	if(max_side < rest_side && len > ans){
	  f = true;
	  ans = len;
	}		  
      }
    }
  }
  
  printf("%d\n", ans);

  return 0;
}
