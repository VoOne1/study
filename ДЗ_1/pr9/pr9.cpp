#include "stdafx.h"
class Test {
public:
    Test() {
        std::cout << "Construct" << std::endl;
    }
    ~Test() {
        std::cout << "Destruct" << std::endl;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
    std::vector <Test*> v(10);
    for (int i = 0; i < v.size(); i++) {
        v[i] = new Test();
    }

    for (int i = 0; i < v.size(); i++) {
        delete v[i]; v[i] = 0;
    }
    return 0;
}

