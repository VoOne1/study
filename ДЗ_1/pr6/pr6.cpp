#include "stdafx.h"

int _tmain(int arg, _TCHAR* argv[])
{
	std::ifstream ifile;
	ifile.open("myfile.txt");
	int a;
	std::vector <int> v;
	for (; ; ) {
		ifile >> a;
		if (ifile.eof()) break;
		v.push_back(a);
	}
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << std::endl;
	}
	return 0;
}