#include<iostream>
#include<vector>

#define FOR(k,a,b) for( int (k) = (a) ; (k) <= (b) ; ++(k) )

using namespace std;

int solve( int n , vector<int> &a )
{
  vector<int> memo(n+1);
  memo[0] = 0;
  FOR(i,0,n-1) {
	memo[i+1] = 1;
	for ( int j = 0 ; j < i ; ++j ) {
	  if ( a[j] < a[i] ) {
		memo[i+1] = max(memo[i+1], memo[j]+1);
	  } 
	}
  }
  return memo[n];
}

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  FOR(i,0,n-1) cin >> a[i];
  
  int ans = solve(n, a);

  cout << ans << endl;
  
  return 0;
}
