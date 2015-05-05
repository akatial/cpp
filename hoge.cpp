#include <iostream>

using namespace std;

int main(void)
{
  int cubic_num[16];
  for( int i = 1 ; i <= 15 ; i ++ )
    {
      cubic_num[i] = i * i * i;
    }
  for( int i = 1 ; i <= 15 ; i++ )
    {
      for( int j = i + 1 ; j <= 15 ; j++ )
	{
	  if( cubic_num[i] + cubic_num[j] == 1729 )
	    {
	      cout << i << " " << j << endl;
	    }
	}
    }
  return 0;
}
