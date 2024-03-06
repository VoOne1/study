#include "stdafx.h"

class Base {
protected:
	std::string s;
public:
	Base() { s = "Base"; }
	virtual ~Base(){}
	std::string get() { return s; }
};

class Child1 : public Base {
public:
	Child1() { s = "child1"; }
};

class Child2 : public Base {
public:
	Child2() { s = "child2"; }
};

int _tmain(int arrgc, _TCHAR* argv[])
{
	Base* b = new Base();
	std::cout << b->get() << std::endl;
	delete b; b = nullptr;

	b = new Child1();
	std::cout << b->get() << std::endl;
	delete b; b = nullptr;

	b = new Child2();
	std::cout << b->get() << std::endl;
	delete b; b = nullptr;
	return 0;
}