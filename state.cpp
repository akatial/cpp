#include <iostream>

using namespace std;

enum state
{
  idle, 
  attack,
  escape,
  scout,
  build,
  train,
};

int main(void)
{
  enum state s;
  s = idle;

  for (int i = 0; i < 3; i++)
  {
    cout << s << endl;
    switch (s)
    {
    case idle:
      s = scout;
      break;
    case scout:
      s = attack;
      break;
    case attack:
      s = escape;
      break;
    case escape:
      s = train;
      break;
    case train:
      s = build;
      break;
    case build:
      s = idle;
      break;
    default:
      break;
    }
  }

  return 0;
}
