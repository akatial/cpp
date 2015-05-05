#include <iostream>
using namespace std;

class Kitty {
public:
	virtual void paint() { cout << "Kitty on your lap\n"; }
} obj1 ;

class Chobits : public Kitty {
public:
	void paint() { cout << "Chobits\n"; }
} obj2 ;

class Di_Gi_Gharat : public Chobits {
public:
	void paint() { cout << "Di Gi Gharat\n"; }
} obj3 ;

int main() {
	Kitty *po1 = &obj1 , *po2 = &obj2 , *po3 = &obj3;

	po1->paint();
	po2->paint();
	po3->paint();

	return 0;
}
