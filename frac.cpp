#include <iostream>

struct fraction
{
  int numerator;
  int denominator;
};

int calc_gcd(int a, int b)
{
  int c;
  
  if ( a < b )
    std::swap(a, b);

  while ( (c = a % b) != 0 )
    {
      a = b;
      b = c;
    }

  return b;
}

int main()
{
  struct fraction f;
  std::cin >> f.numerator >> f.denominator;
  int gcd;
  gcd = calc_gcd(f.numerator, f.denominator);
  std::cout << f.numerator / gcd << " " << f.denominator / gcd << std::endl;
  return 0;
}
