#include <iostream>

#define N 11

void out0(int n)
{
  for(int i=0;i<n;i=i+1)
    std::cout<<0;
}

void out1(int n)
{
  for(int i=0;i<n;i=i+1)
    std::cout<<1;
}

int main(void)
{
  for(int i=1;i<(N-3)/2+1;i=i+1)
    out1(i),out0(N-i*2),out1(i),std::cout<<std::endl;
  out1((N-1)/2);out0(1);out1((N-1)/2);std::cout<<std::endl;
  for(int i=(N-3)/2;i>0;i=i-1)
    out1(i),out0(N-i*2),out1(i),std::cout<<std::endl;
  return 0;
}

/*

10000000001
11000000011
11100000111
11110001111
11111011111
11110001111
11100000111
11000000011
10000000001

10001
11011
10001

 */
