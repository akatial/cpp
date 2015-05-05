#include <iostream>
#include <ctime>

using namespace std;

class timer
{
private:
	clock_t start;
public:
	timer();
	~timer();
};

timer::timer()
{
	start = clock();
}

timer::~timer()
{
	clock_t end;
	end = clock();
	cout << (end - start) / CLOCKS_PER_SEC << endl;
}

int main()
{
	timer ob;
	char hoge;
	cout << "Input something!" << endl;
	cin >> hoge;
	return 0;
}
