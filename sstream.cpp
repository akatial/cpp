#include <sstream>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
  ostringstream oss;
  oss << "I want to concentrate on program!" << endl;
  cout << oss.str();

  string hoge("I like a program");
  istringstream iss(hoge);

  string hoge2;
  iss >> hoge2;
  cout << hoge2 << endl;
  return 0;
}
