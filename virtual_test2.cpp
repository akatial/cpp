#include <iostream>
using namespace std;

class Chobits {
public:
	virtual void paint() { cout << "Chobits\n"; }
} obj1 ;

class Di_Gi_Gharat : public Chobits {
public:
	void paint() { cout << "Di Gi Gharat\n"; }
} obj2 ;

int main() {
	Chobits *po;
	unsigned char ch;

	cout << "ちぃ？ y/n >";
	cin >> ch;

	if (ch == 'y') po = &obj1;
	else po = &obj2;

	po->paint();
	return 0;
}
