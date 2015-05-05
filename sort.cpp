#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

int main()
{
	// ソート対象とするコンテナを用意
	deque<int> nums;
	nums.push_back( 8 );
	nums.push_back( 5 );
	nums.push_back( 4 );
	nums.push_back( 7 );
	nums.push_back( 9 );

	deque<int>::iterator it = nums.begin();　//コンテナ<型>::iterator 変数名　= コンテナ.begin();

	//ソート前
	while( it != nums.end() )
	  {
	    cout << *it << endl;
	    ++it;
	  }

	// ソート実行
	sort( nums.begin(), nums.end() );//sort(はじめ、おわり)
	cout << endl;
	

	 it = nums.begin();

	// ソート後
	while( it != nums.end() )
	{
		cout << *it << endl;
		++it;
	}

	return 0;
}
