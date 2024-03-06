#include"stdafx.h"

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

struct Leaks {
	~Leaks() { _CrtDumpMemoryLeaks(); }
}_l;

// Описание университетов, производные классы работают с отдельными данными

class Reshetov // Работа с названием университета (string)
{
	std::string* u_name;
public:
	
	std::string Get_u_name() { return *u_name; }
	void Set_u_name(std::string tmp) { u_name = new std::string(tmp); }
	virtual void Print_state() { std::cout << "Существует университет " << Get_u_name() << '\n'; }

	virtual Reshetov* copy() { return new Reshetov(*this); }
	Reshetov(const Reshetov& obj) :u_name(new std::string("Станкин")) { *u_name = *obj.u_name; }

	Reshetov() : u_name(new std::string("Станкин")) {};

	Reshetov(std::string tmp) : u_name(new std::string(tmp)) {};
	virtual ~Reshetov() { delete u_name; }
};

class Reshetov_child_1:public Reshetov // Работа с номером группы (int)
{
	int* group_id;
public:
	int Get_group_id() { return *group_id; }
	void Set_group_id(int tmp) { group_id = new int(tmp); }
	void Print_state() { std::cout << "В университете " << Get_u_name() << " есть группа номер " << Get_group_id() << '\n'; }

	Reshetov_child_1(const Reshetov_child_1& obj) :Reshetov(obj), group_id(new int(2206)) { *group_id = *obj.group_id; }
	Reshetov* copy() { return new Reshetov_child_1(*this); }

	Reshetov_child_1(std::string tmp1, int tmp2) : group_id(new int(tmp2)), Reshetov(tmp1) {}
	Reshetov_child_1() : group_id(new int(2206)), Reshetov() {}

	virtual ~Reshetov_child_1() { delete group_id;}
};

class Reshetov_child_2 :public Reshetov_child_1 // Работа с подгруппой A/B
{
	char* group_id2;
public:
	char Get_group_id2() { return *group_id2; }
	void Set_group_id2(char tmp) { group_id2 = new char(tmp); }
	void Print_state() { std::cout << "В университете " << Get_u_name() << " есть группа номер " << Get_group_id() << " и подгруппа " << Get_group_id2() << '\n'; }

	Reshetov_child_2(const Reshetov_child_2& obj) :Reshetov_child_1(obj), group_id2(new char('Б')) { *group_id2 = *obj.group_id2; }
	Reshetov* copy() { return new Reshetov_child_2(*this); }

	Reshetov_child_2(std::string tmp1, int tmp2, char tmp3) : group_id2(new char(tmp3)), Reshetov_child_1(tmp1, tmp2){}
	Reshetov_child_2() : group_id2(new char('Б')), Reshetov_child_1() {}
	virtual~Reshetov_child_2() { delete group_id2; }
	
};

class Reshetov_child_3 :public Reshetov_child_2 // Работа с именем и фамилией студента (string)
{
	std::string* s_name;                        // имя
	std::string* s_surname;                     // фамилия
	std::string* s_patr;                        // отчество
public:
	void Print_state() { std::cout << "В университете " << Get_u_name() << " есть группа номер " << Get_group_id() << " и подгруппа " << Get_group_id2() << " в ней есть студент " << Get_s_surname() << " " << Get_initials() << '\n'; }

	std::string Get_s_surname() { return *s_surname; }
	std::string Get_initials(){ return ((*s_name).substr(0, 1) + "." + (*s_patr).substr(0, 1) + "."); }

	Reshetov_child_3(const Reshetov_child_3& obj) :Reshetov_child_2(obj), s_name(new std::string("Владимир")), s_surname(new std::string("Решетов")), s_patr(new std::string("Борисович")) { *s_name = *obj.s_name; *s_surname = *obj.s_surname; *s_patr = *obj.s_patr;}
	Reshetov* copy() { return new Reshetov_child_3(*this); }

	Reshetov_child_3(std::string tmp1, int tmp2, char tmp3, std::string surname, std::string name, std::string patr) : s_surname(new std::string(surname)), s_name(new std::string(name)), s_patr(new std::string(patr)), Reshetov_child_2(tmp1, tmp2, tmp3) {}
	Reshetov_child_3() : s_name(new std::string("Владимир")), s_surname(new std::string("Решетов")), s_patr(new std::string("Борисович")), Reshetov_child_2() {}

	~Reshetov_child_3() { delete s_name; delete s_surname; delete s_patr;}

};

int main() {
	
	setlocale(LC_ALL, "Russian");
	std::vector<Reshetov*>v;
	std::vector<Reshetov*>v2;

	v.push_back(new Reshetov ("МФТИ"));
	v.push_back(new Reshetov_child_1 ("ВШЭ", 8677));
	v.push_back(new Reshetov_child_2 ("МИРЭА", 8677, 'А'));
	v.push_back(new Reshetov_child_3 ("МЭИ", 8677, 'А', "Иванов", "Иван", "Петрович"));
	v.push_back(new Reshetov_child_3);

	for (std::vector<Reshetov*>::iterator it = v.begin(); it != v.end(); ++it)
	{
		Reshetov* new_obj = (*it)->copy();
		v2.insert(v2.end(), new_obj);
	}


	for (Reshetov* obj : v) { //очистка первого вектора
		delete obj;
	}
	v.clear();

	for (int i = 0; i < v2.size(); i++) //проверка корректного заполнения второго вектора
	{
		v2.at(i)->Print_state();
	}

	for (Reshetov* obj : v2) { //очистка второго вектора
		delete obj;
	}
	v2.clear();

	return 0;
}