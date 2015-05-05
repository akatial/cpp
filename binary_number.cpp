#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <iomanip>

//#define N 65536 //2^16
#define N 16

using namespace std;

int main( int argc, char **argv )
{
	stack<int> s;
	int count2 = 0;
	string pattern[N];
	bool is_term[N];
	for( int k = 0 ; k < N ; k++ )
	{
		int i = k;
		int r = 0;
		while( i != 0 )
		{
			r = i % 2;
			s.push(r);
			i /= 2;
		}
		while( !s.empty() )
		{
			pattern[k] += (char)(s.top() + '0');
			s.pop();
		}		
		reverse(pattern[k].begin(), pattern[k].end());
		while( pattern[k].size() < 16 )
		{
			pattern[k] += '0';
		}
		reverse(pattern[k].begin(), pattern[k].end());
		int count = 0;
		for( int i = 0 ; i < pattern[k].size() ; i++ )
		{
			if( pattern[k][i] == '1' ) 
				count++;
		}
		if( count % 2 == 1 )
		{
			cout << setw(2) << k;
			cout << ":" << "o:" << pattern[k] << endl;
			//count2++;
			is_term[k] = true;
		}
		else
		{
			cout << setw(2) << k;
			cout << ":" << "x:" << pattern[k] << endl;
			is_term[k] = false;
		}
	}
	cout << endl;
	int hamming_distance[N][N] = {};
	for( int i = 0 ; i < N ; i++ )
	{
		if( !is_term[i] ) 
			continue;
		for( int j = i + 1 ; j < N ; j++)
		{
			if( !is_term[j] ) continue;
			int d = 0;
			for( int k = 0 ; k < 16 ; k++)
			{
				if( pattern[i][k] != pattern[j][k] )
					d++;
			}
			hamming_distance[i][j] = d;
			cout << i << ":" << j << ":" << d << endl;
		}
		cout << endl;
	}
	//cout << count2 << endl;

	bool first = true;
	for( int i = 0 ; i < N ; i++ )
	{
		if( !is_term[i] ) 
			continue;
		if( first )
			first = !first;
		else
			cout << "v" << endl;
		cout << "(";
		for( int j = 0 ; j < 16 ; j++ )
		{
			if( pattern[i][j] == '1' )
				cout << "X" << j;
			else
				cout << "~X" << j;
			if( j < 15)
				cout << "^";
		}
		cout << ")";
		
	}
	cout << endl;
	return 0;
}

