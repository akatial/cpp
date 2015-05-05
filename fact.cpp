#include <cstdio>

int fact(int n)
{
  if(n == 0) return 1;
  return n * fact(n-1);
}

int main(void)
{
  int n;
  puts("input positive integer");//変換仕様がないときはputsで、あるときはprintfで、
  //ファイルに出力するときは、fprintfで
  scanf("%d", &n);
  printf("fact(%d) = %d\n", n, fact(n));
}
