#include <iostream>
#include <string>
using namespace std;

class Cat
{
private:
  string name;
public:
  Cat(string s){
    name = s;
  }
public:
  void meow(){
    cout << "にゃあ。ぼくは" << name << "だよ。" << endl;
  }
};

int main()
{
  //Cat dora("おまんこ");
  string s;
  cout << "猫が生まれました。命名していいよ♪" << endl;
  cin >> s;
  Cat dora(s);
  cout << "猫が鳴くよぉ～" << endl;
  dora.meow();

}
