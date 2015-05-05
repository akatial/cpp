
#include <algorithm>
#include <iostream>
#include <list>

int main()
{
	using namespace std;

	list<int> nums;
	int i;

	for( i = 0; i < 10; ++i )
	{
		nums.push_back( i );
	}

	// 全要素を1000に変更する
	fill( nums.begin(), nums.end(), 1000 );

	// 要素を出力してみる
	/*
	list<int>::iterator it = nums.begin();
	while( it != nums.end() )
	{
		cout << *it << endl;  // どの要素も1000が出力される
		++it;
	}
	*/
	for( int tmp : nums )
	  cout << tmp << endl;

	return 0;
}
