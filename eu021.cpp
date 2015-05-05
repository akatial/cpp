#include <iostream>
using namespace std;

int 
main(void)
{
  int num,div,result=0;
  int sum[10000]={0};
  int i,j;

  for(num=1; num<10000; num++){
    for(div=1; div<num; div++){
      if(num % div == 0)
	sum[num] += div;
    }
    //cout << num <<" " << sum[num] << endl;
  }
  
  for(i=1; i<10000; i++)
    for(j=i+1; j<10000; j++)
      if(sum[i] == j && sum[j] == i){
	//cout << sum[i] << " " << sum[j] << endl;
	result += sum[i] + sum[j];
      }
  cout << result << endl;
}
