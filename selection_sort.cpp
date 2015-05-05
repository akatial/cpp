#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

const int N = 100;

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

  int data[N];

  for(int i = 0; i < N; i++){
    data[i] = rand() % 100 + 1;
    cout << data[i] << endl;
  }

  int min;
  for(int i = 0; i < N-1; i++){
    min = i;
    for(int j = i + 1; j < N; j++){
      if(data[min] > data[j]) min = j;
    }
    swap(&data[i], &data[min]);
    /*int tmp;
    tmp = data[i];
    data[i] = data[min];
    data[min] = tmp;*/
  }
  cout << "----------------------------------------------------------" << endl;


  for(int i = 0; i < N; i++)
    cout << data[i] << endl;

  return 0;

}

