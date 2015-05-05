#include <cstdio>

#define SUCCESS 0
#define FAILURE 1

int main(int argc, char **argv)
{
  printf("char = %d\n", sizeof(char));
  printf("short = %d\n", sizeof(short));
  printf("int = %d\n", sizeof(int));
  printf("long = %d\n", sizeof(long));
  printf("float = %d\n", sizeof(float));
  printf("long long = %d\n", sizeof(long long));
  printf("double = %d\n", sizeof(double));
  
  printf("\"世界最強のプログラマーになるぞ。\" = %d \n", sizeof("世界最強のプログラマーになるぞ。"));
  printf("\"あ\" = %d\n", sizeof("あ"));
  printf("\"I will be a great programmer.\" = %d \n", sizeof("I will be a great programmer."));
  printf("\"a\" = %d\n", sizeof("a"));

  return SUCCESS;
}
