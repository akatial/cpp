// Header File
//// C Library
#include <cassert> // (assert.h) C Diagnostics Library (header)
#include <cctype> // (ctype.h) Character handling functions (header)
#include <cerrno> // (errno.h) C Errors (header)
#include <cfloat> // (float.h) Characteristics of floating-point types (header)
#include <ciso646> // (iso646.h) ISO 646 Alternative operator spellings (header)
#include <climits> // (limits.h) Sizes of integral types (header)
#include <clocale> // (locale.h) C localization library (header)
#include <cmath> // (math.h) C numerics library (header)
#include <csetjmp> // (setjmp.h) Non local jumps (header)
#include <csignal> // (signal.h) C library to handle signals (header)
#include <cstdarg> // (stdarg.h) Variable arguments handling (header)
#include <cstdbool> // (stdbool.h) Boolean type (header)
#include <cstddef> // (stddef.h) C Standard definitions (header)
#include <cstdint> // (stdint.h) Integer types (header)
#include <cstdio> // (stdio.h) C library to perform Input/Output operations (header)
#include <cstdlib> // (stdlib.h) C Standard General Utilities Library (header)
#include <cstring> // (string.h) C Strings (header)
#include <ctime> // (time.h) C Time Library (header)
//#include <cuchar> // (uchar.h) Unicode characters (header)
#include <cwchar> // (wchar.h) Wide characters (header)
#include <cwctype> // (wctype.h) Wide character type (header)

//// Containers
#include <array> // Array header (header)
#include <bitset> // Bitset header (header)
#include <deque> // Deque header (header)
#include <forward_list> // Forward list (header)
#include <list> // List header (header)
#include <map> // Map header (header)
#include <queue> // Queue header (header)
#include <set> // Set header (header)
#include <stack> // Stack header (header)
#include <unordered_map> //Unordered map header (header)
#include <unordered_set> // Unordered set header (header)
#include <vector> // Vector header (header)

//// Input/Output Stream Library
#include <iostream> // The class relies on a single streambuf object for both the input and output operations.
#include <fstream> // Input/output stream class to operate on files.
#include <sstream> // 

//// Miscellaneous 
#include <algorithm> // Standard Template Library: Algorithms (library )
#include <chrono> // Time library (header)
//#include <codecvt> // Unicode conversion facets (header)
#include <complex> // Complex numbers library (header)
#include <exception> // Standard exceptions (header)
#include <functional> // Function objects (header)
#include <initializer_list> // Initializer list (header)
#include <iterator> // Iterator definitions (header)
#include <limits> // Numeric limits (header)
#include <locale> // Localization library (header)
#include <memory> //Memory elements (header)
#include <new> // Dynamic memory (header)
#include <numeric> // Generalized numeric operations (header)
#include <random> // Random (header)
#include <ratio> // Ratio header (header)
#include <regex> // Regular Expressions (header)
#include <stdexcept> // Exception classes (header)
#include <string> // Strings (header)
#include <system_error> // System errors (header)
#include <tuple> // Tuple library (header)
#include <typeinfo> // Type information (header)
#include <type_traits> //type_traits (header)
#include <utility> // Utility components (header)
#include <valarray> // Library for arrays of numeric values (header)

// Macro Function
#define FOR(data_type,k,a,b) for(data_type (k)=(a);(k)<(b);++(k))
#define ALL(c) (c).begin(),(c).end()

// Original Definition
typedef unsigned long long ull;
typedef unsigned int uint;
const int INF = 1000000007;
const int MOD = 1000000007;
const double EPS = 1e-9;

// Namespace
using namespace std;

namespace Math
{
  uint phi_func(uint); // euler's totient function
  uint Math::phi_func2(uint n) // euler's totient function
  vector<uint> int_fact(uint); // integer factorization
  uint gcd(uint, uint); // greatest common divisor
  uint lcm(uint, uint); // least common multiple
  bool is_prime(ull n); // judge prime or not
  vector<uint> divisor(uint n); // divisor 
}

// Class

class Edge
{
private:
public:
  uint src, dst;
  int weight;
  Edge(uint src, uint dst, int weight) : 
	src(src), dst(dst), weight(weight) {}
};

bool operator<(const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<int> Array;
typedef vector<Array> Matrix;

// Template Function
template <typename T>
void input(T &t){cin>>t;}

template <typename T>
void output(const T &t){cout<<t<<endl;}

template <typename T>
void inputs(T &t){uint N=t.size();FOR(uint,i,0,N)cin>>t[i];}

template <typename T>
void outputs(const T &t){uint N=t.size();FOR(uint,i,0,N)cout<<t[i]<<" ";cout<<endl;}


//// euler's totient function
uint Math::phi_func(uint n) 
{
  vector<uint> prime_factor;
  prime_factor = int_fact(n);
  uint N = prime_factor.size();
  set<double> prime;
  FOR(uint,i,0,N) {
	prime.insert(prime_factor[i]);
  }
  uint ans = n;
  for ( double p : prime ) {
	ans *= ((p - 1) / p);
  }
  return ans;
}

//// euler's totient function
uint Math::phi_func2(uint n)
{
  if ( n == 0 ) return 0;
  uint ans = n;
  for ( uint x = 2 ; x*x <= n ; ++x )
	{
	  if ( n % x == 0 )
		{
		  ans -= ans / x;
		  while ( n % x == 0 ) n /= x;
		}
	}
  if ( n > 1 ) ans -= ans / n; // case prime
  return ans;
}


//// integer factorization
vector<uint> Math::int_fact(uint n)
{
  uint N = n;
  vector<uint> res;
  for( uint i = 2 ; i*i <= N ; ++i ) {
	while ( n % i == 0 ) {
	  res.push_back(i);
	  n /= i;
	}
  }
  if ( n > 1 ) res.push_back(n);
  return res;
}

//// greatest common divisor 
uint Math::gcd(uint a, uint b)
{
  int c;

  while ( a % b ) {
	c = a % b;
	a = b;
	b = c;
  }
  return b;
}

//// least common multiple
uint Math::lcm(uint a, uint b)
{
  return a*b/gcd(a,b);
}


//// judge prime or not
bool Math::is_prime(ull n)
{
  if ( n <= 1 ) return false;
  if ( n == 2 ) return true;
  for ( ull i = 2 ; i * i <= n ; ++i ) {
	if ( n % i == 0 ) return false;
  }
  return true;
}

//// divisor
vector<uint> Math::divisor(uint n)
{
  vector<uint> res;
  for ( uint i = 1 ; i * i <= n ; ++i ) {
	if ( n % i == 0 ) { 
	  res.push_back(i); 
	  if ( i != n/i ) { res.push_back(n/i); }
	}
  }
  stable_sort(ALL(res));
  return res;
}

// Sort

// Search

// DP

// Bit Operation



/*
int main()
{
  return 0;
}
*/





