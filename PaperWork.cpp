//PaperWork.cpp

#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char **argv)
{
  vector<int> v;
  int n, a, k = 0, p = 0, i;

  cin >> n;
  for (i = 1; i <= n; i++)
  {
      cin >> a;
      if (a < 0 && k > 1) v.push_back(p), p = k = 0;
      p++;
      if (a < 0) k++;
  }
  if (p) v.push_back(p);
  cout << v.size() << endl;
  for (i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl;
  return 0;
}
