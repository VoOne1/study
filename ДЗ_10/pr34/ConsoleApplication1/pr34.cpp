#include "stdafx.h"

//bool firstUpper(std::wstring& word) 
//{
//	std::locale loc2("en_US.UTF8");
//	return word.size() && std::isupper(word[0], loc2); 
//}

struct Leaks {
	~Leaks() { _CrtDumpMemoryLeaks(); }
}_l;


void readFile(DB& db1)
{
	using  std::locale;

	const locale utf8_locale = locale(locale(), new std::codecvt_utf8<wchar_t>());


	std::wifstream infile(L"text.txt");      // создать объект класса wifstream
	infile.imbue(utf8_locale);               // связываем наш поток с нужной локалью

	std::wstring tmp;
	int tr = 0;

	while (infile >> tmp)
	{
		firstUpper(tmp) == 1 ? db1.push(new Reshetov(tmp)) : db1.push(new Vladimir(tmp));
	}

	infile.clear();
}

void writeFile(DB& db2)
{
	using  std::locale;
	// создаем константу, содержащую локаль с нужным фасетом для
	// преобразования символов при сохранении в файл в кодировке UTF-8
	const locale utf8_locale = locale(locale(), new std::codecvt_utf8<wchar_t>());
	

	std::wofstream outfile(L"text1.txt"); // создать объект класса wofstream
	outfile.imbue(utf8_locale);               // связываем наш поток с нужной локалью

	db2.print(outfile);
	outfile.flush();
	outfile.clear();
	
}



int main()
{
	DB<Reshetov> db1;
	DB<Reshetov> db2;

	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);


	for (int i = 0; i < 8; i++)
	{
		i % 2 == 0 ? db1.add(new Reshetov) : db1.add(new Vladimir);
	}
	db2 = db1;

	db2.erase();

	std::wcout << db2;
	
	return 0;
}

