#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

#define NUM_SIZE 4
#define PATTERN_SIZE 16
#define NUM_TRIAL 65535 //2^16 - 1 
#define Red 1
//#define Blue 2
//#define Yellow 3


using namespace std;

class AllOver
{
private:
	bool board[NUM_SIZE][NUM_SIZE];
	bool tmp[NUM_SIZE][NUM_SIZE];
public:
	AllOver();
	~AllOver();
	void set_board();
	void solve();
	string convert(int i);
	void change(int posx, int posy);
	bool judge();
	void display(string pattern);
};

AllOver::AllOver()
{
	for( int i = 0 ; i < NUM_SIZE ; i++ )
	{
		for( int j = 0 ; j < NUM_SIZE ; j++ )
		{
			board[i][j] = false;
			tmp[i][j] = false;
		}
	}
}

AllOver::~AllOver()
{
}

void AllOver::set_board()
{
	string sdata;
	char cdata;
	for( int i = 0 ; i < NUM_SIZE ; i++ )
	{
		cin >> sdata;
		for( int j = 0 ; j < NUM_SIZE ; j++ )
		{
			cdata = sdata[j];
			if( cdata == '1' ) board[i][j] = true;
			else board[i][j] = false;
		}
	}
	cout << endl;
}

void AllOver::solve()
{
	for( int i = 0 ; i < NUM_SIZE ; i++ )
	{
		for( int j = 0 ; j < NUM_SIZE ; j++ )
		{
			tmp[i][j] = board[i][j];
		}
	}
	for( int i = 1 ; i <= NUM_TRIAL ; i++ )
	{
		string pattern = convert(i);
		for( int j = 0 ; j < PATTERN_SIZE ; j++ )
		{
			if( pattern[j] == '1' ) 
				change(j / NUM_SIZE, j % NUM_SIZE);
		}
		if(judge()) 
		{
			display(pattern);
		}
		for( int i = 0 ; i < NUM_SIZE ; i++ )
		{
			for( int j = 0 ; j < NUM_SIZE ; j++ )
			{
				tmp[i][j] = board[i][j];
			}
		}
	}
}

string AllOver::convert(int i)
{
	stack<int> s;
	int r;
	string pattern;
	while( i != 0 )
	{
		r = i % 2;
		s.push(r);
		i /= 2;
	}
	while( !s.empty() )
	{
		pattern += (char)(s.top() + '0');
		s.pop();
	}
	reverse(pattern.begin(), pattern.end());
	while( pattern.size() < 16 )
	{
		pattern += '0';
	}
	reverse(pattern.begin(), pattern.end());
	return pattern;
}

//Red All Over
#if Red
void AllOver::change(int posx, int posy)
{
	int dx[13] = {0, 0, 0, 0, 3, 2, 1, -3, -2, -1, 0, 0, 0};
	int dy[13] = {0, -3, -2, -1, 0, 0, 0, 0, 0, 0, 3, 2, 1};
  
	for( int i = 0 ; i < 13 ; i++ )
	{
		if( 0 <= posx + dx[i] && posx + dx[i] <= 3 && 0 <= posy + dy[i] && posy + dy[i] <= 3 )
			tmp[posx+dx[i]][posy+dy[i]] = !tmp[posx+dx[i]][posy+dy[i]];
	}
}
#endif

//Blue All Over
#if Blue
void AllOver::change(int posx, int posy)
{
	int dx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
	int dy[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
  
	for( int i = 0 ; i < 9 ; i++ )
	{
		if( 0 <= posx + dx[i] && posx + dx[i] <= 3 && 0 <= posy + dy[i] && posy + dy[i] <= 3 )
			tmp[posx+dx[i]][posy+dy[i]] = !tmp[posx+dx[i]][posy+dy[i]];
	}
}
#endif


//Yellow All Over
#if Yellow
void AllOver::change(int posx, int posy)
{
	int dx[4] = {-1, 1, -1, 1};
	int dy[4] = {-1, -1, 1, 1};
	
	for( int i = 0 ; i < 4 ; i++ )
	{
		if( 0 <= posx + dx[i] && posx + dx[i] <= 3 && 0 <= posy + dy[i] && posy + dy[i] <= 3 )
			tmp[posx+dx[i]][posy+dy[i]] = !tmp[posx+dx[i]][posy+dy[i]];
	}	
}
#endif

bool AllOver::judge()
{
	for( int i = 0 ; i < NUM_SIZE ; i++ )
	{
		for( int j = 0 ; j < NUM_SIZE ; j++ )
		{
			if(!tmp[i][j]) return false;
		}
	}
	return true;
}

void AllOver::display(string pattern)
{	
	for( int j = 0 ; j < PATTERN_SIZE ; j++ )
	{
		cout << pattern[j];
		if( j % NUM_SIZE == 3 ) cout << endl;
	}
	cout << endl;
}

int main(int argc, char **argv)
{
	AllOver ob;
	ob.set_board();
	ob.solve();
	return 0;
} 
