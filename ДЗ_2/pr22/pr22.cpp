#include "stdafx.h"

class Base 
{
	friend std::string func_get(Base* b);
protected:
	std::string s;
public:
	Base() { s = "Base"; }
	virtual ~Base(){}
	std::string get() { return s; }
};

class Child1 : public Base 
{
public:
	Child1() { s = "child1"; }
};

std::string func_get(Base* b)
{
	return b->s;
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<Base*> v;
	for (int i = 0; i < 10; i++)
	{
		bool ok = i % 3;
		if (!(i % 2))
			v.push_back(new Base);
		else
			v.push_back(new Child1);
	}

	for (int i = 0; i < v.size(); i++)
		std::cout << func_get(v[i]) << std::endl;
	for (int i = 0; i < v.size(); i++)
		delete v[i];
	return 0;
}