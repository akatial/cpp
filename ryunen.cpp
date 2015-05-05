#include <iostream>

using namespace std;

int main(void)
{
  int enrolled = 100;
  int first = 0;
  int second = 0;
  int third = 0;
  int fourth = 0;
  int graduate = 0;

  //int hoge = 2.7;
  //cout << hoge << endl;

  int i;
  /*for (i = 0; i < 10; i++)
  {
    graduate = fourth * 0.1;
    fourth = fourth * 0.9 + third * 0.1;
    third = third * 0.9 + second * 0.1;
    second = second * 0.9 + first * 0.1;
    first = first * 0.9 + enrolled;
    cout << first << " " << second << " " << third << " " << fourth << " " << \
      graduate << endl;
  }*/ 

  /*for (i = 0; i < 10; i++)
  {
    graduate = fourth * 0.1;
    fourth = (fourth - fourth * 0.1) + third * 0.1;
    third = (third - third * 0.1) + second * 0.1;
    second = (second - second * 0.1) + first * 0.1;
    first = (first - first * 0.1) + enrolled;
    cout << first << " " << second << " " << third << " " << fourth << " " << \
      graduate << endl;
      }*/

  for (i = 0; i < 10; i++)
  {
    graduate = (fourth - fourth * 0.9);
    fourth = (third - third * 0.9) + fourth * 0.1;
    third = (second - second * 0.9) + third * 0.1;
    second = (first - first * 0.9) + second * 0.1;
    first = enrolled + first * 0.9;
    cout << first << " " << second << " " << third << " " << fourth << " " << graduate << endl;
  }


  return 0;
}
