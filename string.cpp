#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;

const int N = 5;

int main(void)
{
  string *strings = new string[N];
  strings[0].assign(N, '#');
  for( int i = 1 ; i <= 3 ; i++ )
    {
      cin >> strings[i];
      strings[i].insert(0, "#");
      strings[i].append("#");
	
	//cout << strings[i] << endl;
    } 
  strings[N-1].assign(N, '#');
  for( int i = 0 ; i < N ; i++ )
    {
      cout << strings[i] << endl;
    }
  delete[] strings;
  /* strcmp
   ポインタを使用するときはメモリ管理に気をつけよう。
　つまり、使う前はmallocを、使った後はfreeを忘れずにね。

  char *str1;
  char *str2;

  str1 = (char*)malloc(N);
  str2 = (char*)malloc(N);

  cout << "input string1" << endl;
  cin >> str1;

  cout << "input string2" << endl;
  cin >> str2;

  bool f = true;
  while(*str1 && *str2){
    if(*str1 != *str2) {
      puts("not equal");
      return 0;
    }
    ++str1;
    ++str2;
  }
  puts("just equal");

  free(str1);
  free(str2);

  return 0;

  */

  /* strlen
  char string[N] = {0};
  cout << "input string whose length will be counted" << endl;
  cin >> string;

  int length = 0;
  int i = 0;
  while(string[i] != '\0'){
    length++;
    i++;
  }

  cout << "String's length is " << length << "." << endl; 
  */


  /* strcat
  char a[N] = {0};
  char b[N] = {0};

  cout << "input first string" << endl;
  cin >> a;

  cout << "input second string" << endl;
  cin >> b;

  int i = 0;
  while(a[i] != '\0')
    i++;

  int j = 0;
  while(b[j] != '\0'){
    a[i] = b[j];
    i++;
    j++;
  }

  cout << "connected string" << endl;
  cout << a << endl;
  */

  /* strcpy
  char old_str[N] = {0};
  cout << "input string" << endl;
  cin >> old_str;

  char new_str[N] = {0};
  int i = 0;
  while(old_str[i] != '\0'){
    new_str[i] = old_str[i];
    i++;
  }

  cout << "output string" << endl;
  cout << new_str << endl;
  */
}
