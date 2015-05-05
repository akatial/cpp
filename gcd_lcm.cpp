#include <iostream>

int gcd2(int a, int b)
{
  int c;
  int cnt = 0;

  while ( a % b )
    {
      cnt++;
      c = a % b;
      a = b;
      b = c;
    }

  std::cout << "cnt2:" << cnt << " ";
  
  return b;
}

int gcd1(int a, int b)
{

  int cnt = 0;

  if ( a < b )
    std::swap(a, b);

  while ( a > 0 )
    {
      cnt++;
      if ( a < b )
		std::swap(a, b);
      a -= b;      
    }

  std::cout << "cnt1:" << cnt << " ";

  return b;
}

int main()
{
  int a, b;
  int gcd/*, lcm*/;

  std::cin >> a >> b;

  gcd = gcd1(a, b);
  //lcm = (a*b)/gcd;  
  std::cout << "gcd:" << gcd /*<< " " << "lcm:" << lcm*/ << std::endl;

  gcd = gcd2(a, b);
  //lcm = (a*b)/gcd;  
  std::cout << "gcd:" << gcd /*<< " " << "lcm:" << lcm*/ << std::endl;

  return 0;
}
