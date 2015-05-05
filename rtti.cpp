#include <iostream>
#include <typeinfo>
using namespace std;

class BaseClass
{
	virtual void f() {};
};

class Derived1 : public BaseClass
{
};

class Derived2 : public BaseClass
{
};

int main()
{
	int i;
	BaseClass *p, obb;
	Derived1 ob1;
	Derived2 ob2;
	
	cout << typeid(i).name() << endl;

	p = &obb;
	cout << typeid(*p).name() << endl;

	p = &ob1;
	cout << typeid(*p).name() << endl;
	
	p = &ob2;
	cout << typeid(*p).name() << endl;
	
	return 0;
}
