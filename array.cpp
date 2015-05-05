#include <iostream>

#define N 50

using namespace std;

void show_data(int array[N])
{
  int i;
  for( i = 0 ; i < N ; i++ )
    {
      cout << array[i] << " ";
    }
  cout << endl;
}

void set_data(int array[N])
{
  int i;
  for( i = 0 ; i < N ; i++ )
    {
      array[i] = i;
    }
}

int main(void)
{
  int array[N];
  set_data(array);
  show_data(array);
  return 0;
}
