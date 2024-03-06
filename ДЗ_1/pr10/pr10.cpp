#include "stdafx.h"

void func() {
    std::ifstream ifile;
    ifile.open("myfile.txt");
    int a;
    std::set<int> st;
    for (; ; ) {
        ifile >> a;
        if (ifile.eof()) break;
        st.insert (a);
    }
    std::set<int>::iterator it = st.begin();
    for (; it != st.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    func();
    return 0;
}
