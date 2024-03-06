#include "stdafx.h"
void Uppercase::copyUpper(class DB& db)
{
	db.push (new Uppercase(*this));
}