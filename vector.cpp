#include <iostream>
#include <vector>
#define N 10
using namespace std;

int main()
{
	vector<int> v(N, 1);
	cout << v.capacity();
	for( int i = 0 ; i < N ; i++ )
	{
		cout << v[i] << endl;
	}
	v.clear();
	for( int i = 0 ; i < N ; i++ )
	{
		cout << v[i] << endl;
	}

	return 0;  
}
