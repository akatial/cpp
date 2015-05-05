#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int M, N;

string backtrack(int memo[M+1][N+1], string str1, string str2, int i, int j)
{
	if( i == 0 | j == 0 )
	{
		return "";
	} 
	else if( str1[i] == str2[j] )
	{
		return backtrack(memo, str1, str2, i-1, j-1) + str1[i];
	}
	else
	{
		if( memo[i][j-1] > memo[i-1][j] )
		{
			return backtrack(memo, str1, str2, i, j-1);
		}
		else
		{
			return backtrack(memo, str1, str2, i-1, j);
		}
	}
}

void get_lcs_len(string str1, string str2)
{
	M = str1.size();
	N = str2.size();
	int **memo;
	memo = new int *[M+1];
	for( int i = 0 ; i < M+1 ; i++ )
	{
		memo[i] = new int[N+1];
	}
	memset(memo, 0, sizeof(memo));
	for( int i = 0 ; i < M ; i++ )
	{
		for( int j = 0 ; j < N ; j++ )
		{
			if( str1[i] == str2[j] )
			{
				memo[i+1][j+1] = memo[i][j] + 1;
			}
			else
			{
				memo[i+1][j+1] = max(memo[i+1][j], memo[i][j+1]);
			}
		}
	}
	cout << memo[M][N] << endl;
	cout << backtrack(memo, str1, str2, M - 1, N - 1) << endl;
	for( int i = 0 ; i < N+1 ; i++ )
	{
		delete[] memo[i];
	}
	delete[] memo;
}

int main()
{
	string str1, str2;
	while( cin >> str1 >> str2 )
	{
		get_lcs_len(str1, str2);
	}
	return 0;
}
