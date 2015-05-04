// C Library
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

// Containers
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

// Input/Output Stream Library
#include <iostream> // The class relies on a single streambuf object for both the input and output operations.
#include <fstream> // Input/output stream class to operate on files.
#include <sstream> // 

// Miscellaneous headers
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

#define FOR(X,Y,Z) for((X)=(Y);(X)<(Z);(X)=(X)+1)
typedef unsigned long long int ulli;
const ulli INF = 10000000;

/*
  const int di[4] = {-1, 0, 0, 1};
  const int dj[4] = {0, -1, 1, 0};
  const int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1}; 
  const int dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
*/

int main()
{
  int myints[] = {10,20,30,30,20,10,10,20};   // 8 elements
  int mycount = std::count (myints, myints+8, 10);
  std::cout << "10 appears " << mycount << " times.\n";

  /*  
  std::set<int> nums;  // 空のset

  // 要素を追加する
  nums.insert( 200 );
  nums.insert( 500 );
  nums.insert( 100 );
  nums.insert( 400 );
  nums.insert( 300 );

  // 要素を出力する
  for ( auto &it : nums )
    std::cout << it << std::endl;

  // 要素数を出力する
  std::cout << "要素数：" << (unsigned int)nums.size() << std::endl;

  // 要素の全削除
  nums.clear();

  // 全削除されているか確認
  if( nums.empty() )
    {
      std::cout << "空です" << std::endl;
    }  
  */

  /*
    std::map<int, std::string> names;  // キーがint、値がchar*のmap

    // 要素を追加する
    names.insert( std::pair<int, std::string>( 10, "aaa"));
    names.insert( std::make_pair( 30, "ccc" ) );
    names.insert( std::map<int, std::string>::value_type( 50, "eee" ) );
    names.insert( std::map<int, std::string>::value_type( 40, "ddd" ) );
    names.insert( std::map<int, std::string>::value_type( 20, "bbb" ) );

    // 要素を出力する
    for( auto it : names )
    std::cout << it.first << ":" << it.second << std::endl;

    // 要素数を出力する
    std::cout << "要素数：" << (unsigned int)names.size() << std::endl;
  */

  /*
    std::deque<int> d(1, 0);
    int i;
    FOR(i,0,99)
    {
    d.push_back(i+1);
    d.push_front(i+1);
    }

    sort(d.begin(), d.end(), std::greater<int>());
    for ( auto tmp : d )
    std::cout << tmp << std::endl;
    std::cout << d.size() << std::endl;
    std::cout << d.front() << " " << d.back() << std::endl;
  */
  return 0;
}
