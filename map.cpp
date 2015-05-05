#include <iostream>
#include <map>
using namespace std;
int main()
{
  multimap<int, int> m;
  m.insert(make_pair(3,5));
  m.insert(make_pair(3,4));
  m.insert(make_pair(1,2));
  for( pair<int, int> p : m )
	cout << p.first << " " << p.second << endl;
  return 0;
}
