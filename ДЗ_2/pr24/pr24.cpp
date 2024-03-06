#include "stdafx.h"

template<class T>

class Base {
public:
	Base(T a) { p = a; }
	void print() { std::cout << p << std::endl; }
private:
	T p;
};

int _tmain(int argc, _TCHAR* argv[])
{
	//Base b;
	Base <int> bi(22);
	Base <double> bd(22.84);
	Base <std::string> bs("test");
	bi.print();
	bd.print();
	bs.print();
	return 0;
}