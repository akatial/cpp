#include <iostream>
#include <vector>

std::vector<int> solve( int a, int b )
{
  bool is_prime;
  std::vector<int> res;
  if ( a == 2 ) 
    res.push_back(2);
  for ( int i = a ; i <= b ; i++ )
    {
      if ( i % 2 == 0 ) 
	continue;
      is_prime = true;
      for ( int j = 3 ; j * j <= i ; j += 2 )
	if ( i % j == 0 )
	  {
	    is_prime = false; 
	    break;
	  }
      if ( is_prime )
	res.push_back(i);
    }
  return res;
}

int main()
{
  int a, b;
  std::cin >> a >> b;
  std::vector<int> res;
  res = solve(a, b);
  for ( int t : res )
    std::cout << t << " ";
  std::cout << std::endl;
  return 0;
}
