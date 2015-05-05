#include <iostream>
#include <ctime>
#include <cstdlib>

#define N 10

using namespace std;

void sort(int *array, int begin, int end);
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

	sort(array, 0, N-1);


	for ( int i = 0 ; i < N ; i++ )
	{
		cout << array[i] << endl;
	}

	return 0;
}

void sort(int *array, int begin, int end)
{
	int pivot = array[(begin + end) / 2];
	int i = begin;
	int j = end;

	while ( true )
	{
		while ( array[i] < pivot ) i++;
		while ( array[j] > pivot ) j--;

		if ( i >= j ) break;

		swap(array[i], array[j]);
		
		i++;
		j--;
	}

	if ( i - begin >= 2 )
	{
		sort(array, begin,  i - 1);
	}
	if ( end - j >= 2 )
	{
		sort(array, j + 1, end);
	}
}

void swap(int &x, int &y)
{
	x ^= y;
	y ^= x;
	x ^= y;
}
