#include <vector>
#include <iostream>
using namespace std;

int main()
{
  
  
  vector<int> array1;  // int型の動的配列
  vector<int> array2;  // int型の動的配列
  int i;
  
  for( i = 0; i < 10; ++i )
    {
      array1.push_back( i );
      array2.push_back( 9 - i );
    }
  
  if( array1 == array2 )  // ==演算子で比較
    {
      cout << "一致しました" << endl;
    }
  
  array2.clear();                 // clear()で全ての要素を削除する
  cout << array1.size() << endl;  // size()で要素数取得
  if( array2.empty() )            // empty()で空かどうか調べる
    {
      cout << "array2は空です" << endl;
    }
  
  for( i = 0; i < 10; ++i )
    {
      array1.pop_back();          // pop_back()で末尾の要素削除
    }
  
  return 0;
}


/*
 学んだことをコメントとしてソースコードに残すのはいいかもしれない。
 vector<型>　array;
要素の追加　array.push_back(データ);
要素の削除　array.pop_back(データ);
要素の全削除　arrray.clear
要素のサイズ　array.size()
要素が空かどうか　array.empty()
 */
