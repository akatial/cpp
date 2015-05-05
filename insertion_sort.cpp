#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(void)
{
  const int M = 100;
  int data[M];

  srand((unsigned)time(NULL));

  for(int i = 0; i < M; i++){
    data[i] = rand() % 100 + 1;
    //cout << data[i] << endl;
  }

  for(int i = 1; i < M; i++){
    int tmp = data[i];
    if(data[i-1] > tmp){
      int j = i;
      do{
	data[j] = data[j-1];
	j--;
      }while(j > 0 && data[j-1] > tmp);
      data[j] = tmp;
    }
  }

  for(int i = 0; i < M; i++)
    cout << data[i] << endl;
}
