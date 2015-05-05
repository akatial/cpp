#include <iostream>
#include <deque>

typedef unsigned long long int ull;

int main()
{
  ull n, m;
  std::cin >> n >> m;
  std::deque<ull> d;
  ull r;
  while ( n > 0 )
    {
      r = n % m;
      d.push_front(r);
      n /= m;
    }
  for ( auto t : d )
    std::cout << t;
  std::cout << std::endl;

  return 0;
}
