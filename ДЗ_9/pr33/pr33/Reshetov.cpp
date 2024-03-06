#include "stdafx.h"

 Reshetov::Reshetov(const Reshetov& obj) : data(new std::string(*(obj.data)))
{}
