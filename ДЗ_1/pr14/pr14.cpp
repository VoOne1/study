#include "stdafx.h"
#include <locale.h>

// проверка наличия числа в файле

class Search {
	std::vector<int> v;
public:
	Search(){}
	void OpenFile(const char* name);
	void FindNum();
 };

void Search::OpenFile(const char* name) {
	std::ifstream ifile;
	ifile.open(name);
	int a;
	for (; ; ) {
		ifile >> a;
		if (ifile.eof()) break;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
}
void Search::FindNum() {
	int num = 0;
	std::cout << "Введите число для поиска в файле" << std::endl;
	std::cin >> num;
	bool found = std::binary_search(v.begin(), v.end(), num);
	found ? std::cout << num << " Есть в файле" : std::cout << num << " Отсутствует в файле";
}

int _tmain(int argc, _TCHAR* argv[]) {
	setlocale(LC_ALL, "Russian");
	Search s;
	s.OpenFile("myfile.txt");
	s.FindNum();

	return 0;
}
