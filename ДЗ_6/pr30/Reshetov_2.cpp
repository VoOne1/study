#include "stdafx.h"
void Reshetov_2::copy(std::vector<Reshetov*>& v)
{
	v.push_back(new Reshetov_2(*this));
}
void Reshetov_2::print() { std::cout << "id = " << *id << " " << "i = " << i << std::endl; }

