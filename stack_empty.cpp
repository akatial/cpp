// stack::empty
#include <iostream>
#include <stack>
using namespace std;

int main ()
{
  stack<int> mystack;
  int sum (0);

  for (int i=1;i<=10;i++) mystack.push(i);

  while (!mystack.empty())
  {
	  //sum += mystack.top();
	  cout << mystack.top() << endl;
	  mystack.pop();
  }

  cout << "total: " << sum << endl;
  
  return 0;
}
