#include <iostream>
#include <cstring>

using namespace std;

char* MemSet(char *str, int c, size_t num)
{
    unsigned char *ptr = (unsigned char *)str;
    const unsigned char ch = c;
 
    while(num--)
        *ptr++ = ch;
 
    return str;
}

int main(int argc, char **argv)
{
	char region[10];
	MemSet(region, 0, strlen(region));
	for ( int i = 0 ; i < 10 ; i++ )
	{
		cout << region[i] << endl;
	}

	return 0;
}
