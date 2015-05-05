#include <iostream>

using namespace std;

int main(void)
{
  int hoge1 = 0x1a & 0xf0;
  int hoge2 = 0x1a & 0x0f;
  cout << hoge1 << endl;
  cout << hoge2 << endl;
  return 0;
}
