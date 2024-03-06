#include "stdafx.h"
#include <stdlib.h>
#include <time.h>

//Программа в случайном порядке перемешивает числа из файла

class Mix {
    std::vector<int> v;
public:
    Mix(){}
    void ReadFile(const char* name);
    void Mixer();
};
void Mix::ReadFile(const char* name) {
    std::ifstream ifile;
    ifile.open(name);
    int a;
    for (; ; ) {
        ifile >> a;
        if (ifile.eof())break;
        v.push_back(a);
    }
}

void Mix::Mixer() {
    int n = v.size();
    std::srand(time(NULL));
    for (int i = 0; i < n - 1; i++) {
        int j = (i + rand()) % (n - 1);
        std::swap(v.at(i), v.at(j));
    }
    for (int i = 0; i < n; ++i) {
        std::cout << v.at(i) << std::endl;
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    Mix m;
    m.ReadFile("myfile.txt");
    m.Mixer();
    ;
}
