#include "stdafx.h"

bool firstUpper(std::wstring& word) 
{
	std::locale loc2("en_US.UTF8");
	return word.size() && std::isupper(word[0], loc2); 
}

struct Leaks {
	~Leaks() { _CrtDumpMemoryLeaks(); }
}_l;


void readFile(DB& db1)
{
	using  std::locale;
	// создаем константу, содержащую локаль с нужным фасетом для
	// преобразования символов при чтении из файла в кодировке UTF-8
	const locale utf8_locale = locale(locale(), new std::codecvt_utf8<wchar_t>());


	std::wifstream infile(L"text.txt");      // создать объект класса wifstream
	infile.imbue(utf8_locale);               // связываем наш поток с нужной локалью

	std::wstring tmp;
	int tr = 0;

	while (infile >> tmp)
	{
		firstUpper(tmp) == 1 ? db1.push(new Uppercase(tmp)) : db1.push(new Lowercase(tmp));
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
	DB* db1 = new DB;
	DB* db2 = new DB;

	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);

	readFile(*db1);
	*db2 = *db1;
	DB db3 = *db2;
	delete db1;
	writeFile(*db2);
	delete db2;
	
	

	return 0;
}

