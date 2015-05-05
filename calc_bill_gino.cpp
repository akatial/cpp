#include <iostream>
#include <vector>

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))

const int N = 4;
const int price_review[N] = {10000, 8000, 4000, 2000};
const int price_create[N] = {40000, 35000, 28000, 21000};

using namespace std;

int main()
{
  vector<int> num_review(N);
  vector<int> num_create(N);
  int transportation_expenses, transportation_num;
  FOR(i,0,N) cin >> num_review[i];
  FOR(i,0,N) cin >> num_create[i];
  cin >> transportation_expenses >> transportation_num;
  int amount = 0;
  FOR(i,0,N) amount += price_review[i] * num_review[i];
  FOR(i,0,N) amount += price_create[i] * num_create[i];
  double tax = 0.0;
  tax = (amount * 0.1021);
  amount -= static_cast<int>(tax);
  amount += (transportation_expenses * transportation_num);
  cout << amount << endl;
  return 0;
}
