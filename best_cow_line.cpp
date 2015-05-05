#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 100;

int main(void)
{
  char str[MAX_N];
  int N;
  cout << "input string" << endl;
  cin >> str;
  N = strlen(str);

  int start = 0;
  int goal = N - 1;

  while(start <= goal)
    {
      bool left = false;
      for(int i = 0; start + i <= goal; i++)
	{
	  if(str[start + i] < str[goal - i])
	    {
	      left = true;
	      break;
	    }
	  else if(str[start + i] > str[goal - i])
	    {
	      left = false;
	      break;
	    }
	} 
      if(left) putchar(str[start++]);
      else putchar(str[goal--]);
    }

  putchar('\n');

  return 0;
}
