#include "stdafx.h"

class Shape {
public:
	virtual double Perimetr() = 0;
	Shape(){}
	virtual~Shape(){}
};

class Square:public Shape {
	double side;
public:
	Square(): side(1.00) {}
	double Perimetr() { return side * 4.0; }
	
};

class Circle :public Shape {
	double radius;
public:
	Circle() : radius(1.0) {}
	double Perimetr();
};

double Circle::Perimetr()
{
	return 2.0 * radius * 3.14;
};

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<Shape*> v(5);
	for (int i = 0; i < 3; i++)
		v.at(i) = new Circle();
	for (int i = 3; i < 5; i++)
		v.at(i) = new Square();

	for (int i = 0; i < 5; i++)
		std::cout << v.at(i)->Perimetr() << std::endl;

	for (int i = 0; i < 5; i++)
	{
		delete v.at(i);
	}
	return 0;
}