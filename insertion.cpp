#include <iostream>
#include <ctime>
#include <cstdlib>

#define N 10

using namespace std;

int main(int argc, char **argv)
{
	srand((unsigned int)time(NULL));

	int array[N];

	for ( int i = 0 ; i < N ; i++ )
	{
		array[i] = rand() % 100 + 1;
		cout << array[i] << endl;
	}

	cout << endl;

	for ( int i = 1 ; i < N ; i++ )
	{
		int tmp = array[i];
		int j;
		for ( j = i ; j > 0 && array[j-1] > tmp ; j-- )
		{
			array[j] = array[j-1];
		} 
		array[j] = tmp;
	}

	for ( int i = 0 ; i < N ; i++ )
	{
		cout << array[i] << endl;
	}

	return 0;
}
