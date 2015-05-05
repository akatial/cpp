#include <iostream>
int main()
{
  using std::cout;
  //using std::ends;
  int ends = 3;
  cout << "test" << ends;
}

/*
#include <iostream>
using namespace std;
int main()
{
  int ends = 3;
 cout << "test" << ends;
}
*/

/*
#include <iostream>

namespace sample
{
  int num;    // sample::num
}

int main()
{
  int num;    // 単なるnum
	
  num = 123;          // 単なるnumに代入
  sample::num = 300;  // sample::numに代入
	
  std::cout << num << std::endl;
  std::cout << sample::num << std::endl;

  return 0;
}
*/


