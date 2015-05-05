#include <iostream>
#include <algorithm>

int main()
{
  int N;
  std::cin >> N;
  bool *is_prime = new bool[N+1];
  std::fill_n(is_prime, N+1, true);
  for ( int i = 2 ; i * i <= N ; i++ )
    {
      if ( is_prime[i] )
        {
          for ( int j = 2 ; i * j <= N ; j++ )
            {
              is_prime[i*j] = false;
            }
        }
    }
  for ( int i = 2 ; i <= N ; i++ )
    {
      if ( is_prime[i] )
        std::cout << i << " ";
    }
  std::cout << std::endl;

  delete[] is_prime;
  return 0;
}
