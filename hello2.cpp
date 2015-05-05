#include <iostream>
#include <string>
using namespace std;

int main()
{
  string name;
  int old;
  
  cout << "こんにちわ。わたしはコンピュータ。" << endl;
  cout << "あなたの名前を入力してください。" << endl;
  cin >> name;
  cout << name << "さん、よろしく。" << endl;

  cout << "ところで、" << name << "さん。失礼ですがお年はいくつですか？" << endl;
  cout << "(入力はかならず、半角の数字でお願いします。)" << endl;
  cin >> old;      //年齢（整数）の入力
  
  cout << "なるほど。" << old << "歳ですか。" << endl;
  cout << "私はもうすぐ2歳のマシンです。"<<endl;
}
