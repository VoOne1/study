#include "stdafx.h"

class Base
{
	int* i;
	double d;
public:
	Base() :i(new int), d(22.33) { *i = 0; }
	virtual ~Base() { delete i; i = 0; }

	int get() { return *i;}
	double get()const { return d;}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Base b;
	const Base bc;
	std::cout << b.get() << std::endl;
	std::cout << bc.get() << std::endl;
	return 0;
}