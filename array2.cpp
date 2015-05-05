#include <iostream>
#include <array>
using namespace std;
int main()
{
  array<int,10> num = {0,1,2,3,4,5,6,7,8,9};
  for ( auto it = num.begin() ; it != num.end() ; ++it )
	cout << *it << endl;
  cout << num.size() << endl;
}
