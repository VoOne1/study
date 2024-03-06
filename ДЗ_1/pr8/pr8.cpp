#include "stdafx.h"

class Reader {
	std::vector<int> m_v;
public:
	Reader (){}
	void read(const char* name);
	void print();
};

void Reader::read(const char* name) {
	std::ifstream ifile;
	ifile.open(name);
	int a;
	for (; ; ) {
		ifile >> a;
		if (ifile.eof())break;
		m_v.push_back(a);
	}
}

void Reader::print() {
	for (int i = 0; i < m_v.size(); i++) {
		std::cout << m_v[i] << std::endl;
	}
}

int _tmain(int argc, _TCHAR* argv[]) {
	Reader r;
	r.read("myfile.txt");
	r.print();
	getchar();   
	return 0;
}

