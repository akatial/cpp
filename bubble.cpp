//bubble.cpp
#include <iostream>
#include <ctime>
#include <cstdlib>

#define N 10

using namespace std;

void swap(int &x, int &y);

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

	for ( int i = 0 ; i < N - 1 ; i++ )
	{
		for ( int j = 1 ; j < N - i ; j++ )
		{
			if ( array[j] < array[j-1] ) swap(array[j], array[j-1]);
		}
	}
	
	for ( int i = 0 ; i < N ; i++ )
	{
		cout << array[i] << endl;
	}
	
	return 0;
}

void swap(int &x, int &y)
{
	x ^= y;
	y ^= x;
	x ^= y;
}
