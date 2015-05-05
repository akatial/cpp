#include <iostream>

using namespace std;

template <typename type>
class Calc
{
private:
public:
	Calc();
	~Calc();
	type add(type x, type y);
	type sub(type x, type y);
	type mul(type x, type y);
	type div(type x, type y);
	type rem(type x, type y);
	type fact(type z);
	type pow(type x, type y);
};

template <typename type>
Calc<type>::Calc()
{
}

template <typename type>
Calc<type>::~Calc()
{
}

template <typename type> 
type Calc<type>::add(type x, type y)
{
	return x + y;
}

template <typename type>
type Calc<type>::sub(type x, type y)
{
	return x - y;
}

template <typename type>
type Calc<type>::mul(type x, type y)
{
	return x * y;
}

template <typename type>
type Calc<type>::div(type x, type y)
{
	return x / y;
}

template <typename type>
type Calc<type>::rem(type x, type y)
{
	return x % y;
}

template <typename type>
type Calc<type>::fact(type z)
{
	if( z == 1 ) return 1;
	else return z * fact(z-1);

}

template <typename type>
type Calc<type>::pow(type x, type y)
{
	int z = 1;
	for ( int i = 0 ; i < y ; i++)
	{
		z = z * x;
	}
	return z;
}

int main(int argc, char **argv)
{
	Calc<int> ob;
	int x, y;
	cin >> x >> y;
	cout << ob.add(x,y) << endl;
	cout << ob.sub(x,y) << endl;
	cout << ob.mul(x,y) << endl;
	cout << ob.div(x,y) << endl;
	cout << ob.rem(x,y) << endl;
	cout << ob.fact(x) << endl;
	cout << ob.pow(x,y) << endl;
	return 0;
}
