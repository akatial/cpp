#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main(void)
{
  srand((unsigned int)time(NULL));
  for(;;)
    {
      cout << hex << rand();
    }
  return 0;
}
