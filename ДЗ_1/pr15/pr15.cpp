// перевод чисел из файла в восьмеричную/шестнадцатеричную системы счисления

#include "stdafx.h"
#include <locale.h>

class AnotherSystem {
	std::vector <int> v;
public:
	AnotherSystem() {};
	void OpenFile(const char* name);
	void print(int num);
	void Execute();
};
	
void AnotherSystem::OpenFile(const char* name) {
	std::ifstream ifile;
	ifile.open(name);
	int a = 0;
	for (; ; ) {
		ifile >> a;
		if (ifile.eof()) break;
		v.push_back(a);
	}
}

void AnotherSystem::print(int num) {
	for (int i = 0; i < v.size(); i++) {
		if (num == 8)
			std::cout << std::oct << v.at(i) << std::endl;
		else if (num == 16) std::cout << std::hex << v.at(i) << std::endl;
	}
}

void AnotherSystem::Execute() {
	for (; ; ){
		int num;
		std::cout << "Введите 8 или 16 для перевода в соответствующую систему счисления. Для остановки введите 0" << std::endl;
		std::cin >> num;
		if (num == 0) return;
		if (num != 8 && num != 16) {
			std::cout << "Ошибка системы счисления"<< std::endl;
		}
		print(num);
	}
}

int _tmain(int argc, _TCHAR* argv[]) {
	setlocale(LC_ALL, "Russian");
	AnotherSystem s;
	s.OpenFile("myfile.txt");
	s.Execute();

	return 0;
}