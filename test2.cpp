#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	ifstream ifs( "test.txt" );
	string str;

	ifs >> str;
	cout << str << endl;

	return 0;
}
