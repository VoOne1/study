#include "stdafx.h"
//вывод названий цифр через std::map

class Map {
	std::vector<int> v;
    std::map< int, std::string > dictionary;
public:
	Map() {};
	void OpenFile(const char* name);
	void SetMap();
	void Print();
};

void Map::OpenFile(const char* name) {
	std::ifstream ifile;
	ifile.open(name);
	int a;
	for (; ; ) {
		ifile >> a;
		if (ifile.eof())break;
		v.push_back(a);
	}
}

void Map::SetMap() {
	dictionary[0] = "zero";
	dictionary[1] = "one";
	dictionary[2] = "two";
	dictionary[3] = "three";
	dictionary[4] = "four";
	dictionary[5] = "five";
	dictionary[6] = "six";
	dictionary[7] = "seven";
	dictionary[8] = "eight";
	dictionary[9] = "nine";
}
void Map::Print() {
	for (int i = 0; i < v.size(); i++) {
		std::cout << v.at(i) << '\t' << dictionary[v.at(i)] << std::endl;
	}
}


int _tmain(int argc, _TCHAR* argv[]) {
	Map t;
	t.OpenFile("myfile.txt");
	t.SetMap();
	t.Print();

	return 0;
}

