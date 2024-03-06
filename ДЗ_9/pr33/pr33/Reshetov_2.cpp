#pragma once
#include "stdafx.h"


void Reshetov_2::copy(class DB& obj, std::list<Reshetov*>& db, std::list<Reshetov*>::iterator& it) { obj.push(new Reshetov_2(*this)); it++; }
