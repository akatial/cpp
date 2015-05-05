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

	// ６を探す
	list<int>::iterator pos;
	pos = find( nums.begin(), nums.end(), 6 );
	if( pos == nums.end() )
	{
		cout << "見つかりませんでした" << endl;
	}
	else
	{
		cout << "見つかりました" << endl;
	}

	return 0;
}
