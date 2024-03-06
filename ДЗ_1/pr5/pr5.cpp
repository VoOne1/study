#include"stdafx.h"

int _tmain(int arg, _TCHAR* argv[])
{
	std::ifstream ifile;
	ifile.open("myfile.txt");
	std::string s0, s1;
	for (; ; ) {
		ifile >> s0;
		if (ifile.eof())break;
		s1 += s0 += "\n";
	}
	std::cout << s1;
	return 0;
}