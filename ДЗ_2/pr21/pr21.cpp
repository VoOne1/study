#include "stdafx.h"

class Base {
protected:
	std::string s;
public:
	Base() { s = "Base"; }
	virtual ~Base() { }
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

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<Base*> v;
	for(int i =0; i < 10; i++)
	{
		if (!(i % 3))
			v.push_back(new Base);
		else
			if (!((i % 3) - 1))
				v.push_back(new Child1);
			else
				v.push_back(new Child2);
	}

	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i]->get() << std::endl;
	}
	for (int i = 0; i < v.size(); i++) {
			delete v[i];  
	}
	return 0;
}