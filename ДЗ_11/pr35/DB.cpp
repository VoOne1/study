#include"stdafx.h"
void DB::push(Word* w)
{
	v->push_back(w);
}
void DB::print(std::wofstream& outfile)
{
    std::vector<Word*>::iterator it = v->begin();
    for (; it != v->end(); ++it)
    {
        outfile << *(*it) << std::endl;
    }
    std::wcout << "Data wrote to file text1.txt" << std::endl;

}

