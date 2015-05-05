#include <iostream>

using namespace std;

class figure
{
private:
public:
	double width;
	double height;
};


class rectangle : public figure
{
private:
public:
	rectangle(double w, double h);
	double area();
};

rectangle::rectangle(double w, double h)
{
	width = w;
	height = h;
}

double rectangle::area()
{
	return width * height ;
}

class isosceles : public figure
{
private:
public:
	isosceles(double w, double h);
	double area();
};

isosceles::isosceles(double w, double h)
{
	width = w;
	height = h;
}

double isosceles::area()
{
	return width * height / 2 ;
}

int main()
{
	rectangle rec(4, 5);
	isosceles iso(4, 5);
	cout << rec.area() << endl;
	cout << iso.area() << endl;
	return 0;
}
