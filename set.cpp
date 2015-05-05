#include <iostream>
#include <set>
using namespace std;
int main()
{
  multiset<int> s;
  s.insert(1);
  s.insert(1);
  s.insert(2);
  for( int t : s ) cout << t << endl;
	
  return 0;
}
