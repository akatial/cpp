#include <iostream>
#include <vector>

typedef unsigned long long int ull;

ull target_number;
std::vector<ull> res;

void solve()
{
  ull prime_factor = 2;
  while ( target_number >= prime_factor ) 
    {
      if ( target_number % prime_factor == 0 )
	{
	  res.push_back(prime_factor);
	  target_number /= prime_factor;
	}
      else 
	prime_factor = prime_factor + 1;
    }
}

int main() 
{
  std::cin >> target_number;

  solve();

  for ( auto pf : res )
    std::cout << pf << " ";
  std::cout << std::endl;

  return 0;
}
