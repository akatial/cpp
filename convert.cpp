#include <iostream>

#define N 1024

using namespace std;

int main(void)
{
	for(int num = 1 ; num <= 10 ; num++ )
	{
		int id = 0, r = 0, num2;
		int b[N] = {};
	
		num2 = num;
		while( num2 > 0 )
		{
			r = num2 % 2;
			b[id++] = r;
			num2 /= 2;
		}

		for( int i = id - 1 ; i >= 0 ; i-- )
		{
			cout << b[i];
		}
		cout << endl;
	}
	return 0;
}
