#include "stdafx.h"
std::ifstream ifile;
int main() {
	ifile.open("myfile.txt");
	int a;
	std::vector <int> v;
	for (; ; ) {
		ifile >> a;
		if (ifile.eof()) break;
		v.push_back(a);
	}

	sort(v.begin(), v.end());
	//sort(v.rbegin(), v.rend());

	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << std::endl;
	}
	return 0;
}

