#include <algorithm>
#include <vector>
#include <iostream>


int main()
{
	using namespace std;

	vector<int> nums;
	int i;

	for( i = 0; i < 10; ++i )
	{
		nums.push_back( i );
	}

	reverse( nums.begin(), nums.end() );  // 逆の順番に並べ替える

	for( i = 0; i < 10; ++i )
	{
		cout << nums[i] << endl;
	}

	return 0;
}
