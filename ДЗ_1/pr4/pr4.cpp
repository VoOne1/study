#include "stdafx.h"

int _tmain(int arg, _TCHAR* argv[])
{
	std::ofstream of;
	of.open("myfile.txt");
	for (int i = 0; i < 10; i++) {
		of << i << std::endl;
	}
	return 0;
}