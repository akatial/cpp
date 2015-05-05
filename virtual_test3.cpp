#include <iostream>
using namespace std;

class Parent
{
public:
  void func(void)
  {
    cout << "基底クラスのメソッドです" << endl;
  }
};

class Child : public Parent
{
public:
  //オーバーライドしたメソッド
  void func(void)
  {
    cout << "派生クラスのメソッドです" << endl;
  }
};

int main(int argc, char** argv)
{
  Parent *p_parent;
  Child i_child;
  p_parent = &i_child;
  i_child.func();        //オーバーライドしたメソッドを呼び出す
  i_child.Parent::func();//基底クラスのメソッドを呼び出す
  p_parent->func();      //派生クラスのオブジェクトを基底クラスのポインタに代入したメソッドを呼び出す
  return(0);
}
