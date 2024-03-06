#include "stdafx.h"
void Reshetov::copy(class DB& db)
{
	db.push (new Reshetov(*this));
}