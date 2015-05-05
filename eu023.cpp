#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
  int i, j, j1, j2, k=1, result=0, sum1=0, sum2=0;
  int sum[28123]={0}, type[28123]={0}, count[3]={0};
  vector<int> abu;

   for(i=1; i<=28123; i++){
    for(j=1; j<i; j++){
      if(!(i % j)){
	sum[i] += j;
      }
    }
    cout << i << " " << sum[i] << endl;
    
    /*
    if(i > sum[i]){
      //count[0]++;
      type[k] = 0;
      k++;
      //cout << "deficient" << endl; 
    }
    if(i == sum[i]){
      //count[1]++;
      type[k] = 1;
      k++;
      //cout << "perfect" << endl;
    }
    if(i < sum[i]){
      //count[2]++;
      type[k] = 2;
      k++;
      //cout << i << " " << sum[i] << " " <<  "abundant" << endl;
    }
    */
   }
   /*
   cout << count[0] << endl;
   cout << count[1] << endl;
   cout << count[2] << endl;
   */
   
   /*
  for(i=1; i<=28123; i++){
    sum2 += i;
    for(j1=1; j1<=28123; j1++){
      for(j2=j1; j2<=28123; j2++){
	if(type[j1] == 2 && type[j2] == 2 && i == j1 + j2)
	  sum1 += i;
      }
    }
  }

  result = sum2 - sum1;

  cout << result << endl;
   */

  return 0;
}





