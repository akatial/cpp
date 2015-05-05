#include <iostream>
#include <cmath>

#define N 10

int main(void)
{
    for( int i = 2 ; i <= N ; i++ )
    {
        std::cout << "n:" << i << " " << 1L - (pow(2,i) - 2) / pow(3, i-1) << std::endl; 
    } 
    return 0;
}
