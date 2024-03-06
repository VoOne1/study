#include "stdafx.h"


struct Leaks {
	~Leaks() { _CrtDumpMemoryLeaks(); }
}_l;



int main()
{
	DB<Reshetov*> db1;
	DB<Reshetov*> db2;

	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);


	for (int i = 0; i < 8; i++)
	{
		i % 2 == 0 ? db1.add(new Reshetov()) : db1.add(new Vladimir());
	}
	db2 = db1;

	db2.erase();
	
	std::wcout << db2;

	return 0;
}

