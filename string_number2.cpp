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

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))

int main()
{
  double num1;
  std::string str1;
 
  // 数値型から文字列型へ
  num1 = 6.673;
  str1 = std::to_string(num1);
  std::cout << str1 << std::endl;

  int num2;
  std::string str2;

  // 文字列型から数値型へ
  str2 = "299792";
  num2 = std::stoi(str2);
  std::cout << num2 << std::endl;

  return 0;
}
