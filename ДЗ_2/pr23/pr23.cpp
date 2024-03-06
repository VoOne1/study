#include "stdafx.h"

class Base {
public:
	virtual void func1() = 0;
	virtual void func2() = 0;
	virtual void func3() = 0;
	virtual void print() = 0;
};

class Child1 : public Base {
	std::string s;
public:
	Child1() { s = " child1 "; }
	void func1() { s += "func1 "; }
	void func2() { s += "func2 "; }
	void func3() { s += "func3 "; }
	void print() { std::cout << s << std::endl; }
};

int _tmain(int argc, _TCHAR* argv[])
{
	//Base b
	Child1 c;
	c.func1();
	c.func3();
	c.print();
	return 0;
}