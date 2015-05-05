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
		int min_id = i;
		for ( int j = i + 1 ; j < N ; j++ )
		{
			if ( array[j] < array[min_id] )
			{
				min_id = j;
			}
		}
		swap(array[i], array[min_id]);
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
