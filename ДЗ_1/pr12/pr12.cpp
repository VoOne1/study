#include "stdafx.h"
#include "windows.h"

// вывод всех чисел из файла в одну строку
class Task{
	std::vector<int> v;
public:
	Task() {};
	void OpenFile(const char* name);
	void Print();
};

void Task::OpenFile(const char* name) {
	std::ifstream ifile;
	ifile.open(name);
	int a;
	for (; ; ) {
		ifile >> a;
		if (ifile.eof())break;
		v.push_back(a);
	}
}

void Task::Print() {
	for (int i = 0; i < v.size(); i++) {
		std::cout << v.at(i);
		Sleep(200);
		std::cout<< '\r';
	}
}

int _tmain(int argc, _TCHAR* argv[]){
	Task t;
	t.OpenFile("myfile.txt");
	t.Print();

	return 0;
}

