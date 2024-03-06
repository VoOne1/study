#include "stdafx.h"

class Base 
{
public:
	Base() 
	{
		std::cout << "Construct Base" << std::endl;
	}
	virtual ~Base() 
	{
		std::cout << "Destruct Base" << std::endl;
	}
};

class Child :public Base 
{
public:
	Child() 
	{
		std::cout << "Construct Child" << std::endl;
	}
	~Child() 
	{
		std::cout << "Destruct Child" << std::endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<Base*>v(2);
	v[0] = new Base();
	v[1] = new Child();
	for (int i = 0; i < v.size(); i++) 
	{
		delete v[i]; v[i] = 0;
	}
	return 0;
}

