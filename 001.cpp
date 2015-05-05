#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;
int main( int argc, char **argv )
{
  int *a;
  a = (int*)malloc(10*sizeof(int));
  for ( int i = 0 ; i < 10 ; ++i )
	{
	  a[i] = i;
	  cout << i << endl;
	}
  free(a);
  char *b = (char*)"opaidaisuki";
  printf("%s\n",b);
  string c = "mankodaisuki";
  cout << c << endl;
  
  return EXIT_SUCCESS;
}
