#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int M = 100;


void swap(int *x, int *y)
{
  int tmp;

  tmp = *x;
  *x = *y;
  *y = tmp;
}

int main(void)
{
  srand((unsigned)time(NULL));

  int data[M];
  for(int i = 0; i < M; i++){
    data[i] = rand() % 100 + 1;
    //cout << data[i] << endl;
  }

  for(int i = 0; i < M-2; i++)
    for(int j = 1; j < M-i; j++)
      if(data[j] < data[j-1]) swap(&data[j], &data[j-1]);
  
  for(int i = 0; i < M; i++)
    cout << data[i] << endl;

  return 0;
}
