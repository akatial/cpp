#include <vector>
#include <iostream>

int main()
{
	using namespace std;

	vector<int> array;   // int型の動的配列
	int i;

	for( i = 0; i < 10; ++i )
	{
		array.push_back( i );
	}

	vector<int>::iterator it = array.begin();
	//++it;
	//it = array.erase( it );      // itの位置の要素を削除
	array.insert( it, 999 );     // itの位置に999を挿入

	for( it = array.begin(); it != array.end(); ++it )
	{
		cout << *it << endl;
	}

	return 0;
}
