#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#define LEN 4

using namespace std;

int main(void)
{
  srand((unsigned)time(NULL));

  int target[LEN] = {0};

  cout << "target:" ;
  for(int i = 0; i < LEN; i++){
    target[i] = rand() % 10;
    for(int j = 0; j < i; j++){
      while(target[i] == target[j]){
	target[i] = rand() % 10; 
      }
    }
    cout << target[i];
  }
  for(int i = 0; i < 30; i++) cout << endl;
  
  int guess[LEN] = {0};
  int tmp = 0;
  
  while(true){
    cout << "予測する数値を" << LEN << "桁で入力してください" << endl;
    cin >> tmp;
    
    for(int i = 0; i < LEN; i++){
      guess[i] = tmp / (int)pow(10, LEN - i - 1);
      tmp %= (int)pow(10, LEN - i - 1); 
    }
    
    int strike = 0;
    int ball = 0;
    
    for(int i = 0; i < LEN; i++){
      for(int j = 0; j < LEN; j++){
	if(target[i] == guess[j] && i == j){ strike++; break;} 
	if(target[i] == guess[j] && i != j){ ball++; break;}
      }
    }

    if(strike == LEN){
      cout << "おめでとう！君は全ての数を当てるのに成功したよ！" << endl;
      break;
    } 
    if(ball == LEN){
      cout << "おめでとう！これでターゲットで使用されている数字はわかったね!" << endl;
    }
    
    cout << "S:" << strike << " B:" << ball << endl;
    
  }

  return 0;
}
