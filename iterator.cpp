#include <vector>
#include <iostream>
using namespace std;

int main()
{


	vector<int> array;   // int型の動的配列
	int i;

	for( i = 0; i < 10; ++i )
	{
		array.push_back( i );
	}

	vector<int>::iterator it = array.begin();  // イテレータのインスタンス化
	while( it != array.end() )  // 末尾要素まで
	{
		cout << *it << endl;  // *演算子で間接参照
		++it;                 // イテレータを１つ進める
	}

	return 0;
}

/*
  iteratorはコンテナ専用のポインタみたいなもん。
  array.begin()により先頭アドレスを返す。
  array.end()は末尾の次のアドレスを返す。
  親クラス::子クラス

 */
