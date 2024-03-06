#include"stdafx.h"

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

struct Leaks {
	~Leaks() { _CrtDumpMemoryLeaks(); }
}_l;

// �������� �������������, ����������� ������ �������� � ���������� �������

class Reshetov // ������ � ��������� ������������ (string)
{
	std::string* u_name;
public:
	
	std::string Get_u_name() { return *u_name; }
	void Set_u_name(std::string tmp) { u_name = new std::string(tmp); }
	virtual void Print_state() { std::cout << "���������� ����������� " << Get_u_name() << '\n'; }

	virtual Reshetov* copy() { return new Reshetov(*this); }
	Reshetov(const Reshetov& obj) :u_name(new std::string("�������")) { *u_name = *obj.u_name; }

	Reshetov() : u_name(new std::string("�������")) {};

	Reshetov(std::string tmp) : u_name(new std::string(tmp)) {};
	virtual ~Reshetov() { delete u_name; }
};

class Reshetov_child_1:public Reshetov // ������ � ������� ������ (int)
{
	int* group_id;
public:
	int Get_group_id() { return *group_id; }
	void Set_group_id(int tmp) { group_id = new int(tmp); }
	void Print_state() { std::cout << "� ������������ " << Get_u_name() << " ���� ������ ����� " << Get_group_id() << '\n'; }

	Reshetov_child_1(const Reshetov_child_1& obj) :Reshetov(obj), group_id(new int(2206)) { *group_id = *obj.group_id; }
	Reshetov* copy() { return new Reshetov_child_1(*this); }

	Reshetov_child_1(std::string tmp1, int tmp2) : group_id(new int(tmp2)), Reshetov(tmp1) {}
	Reshetov_child_1() : group_id(new int(2206)), Reshetov() {}

	virtual ~Reshetov_child_1() { delete group_id;}
};

class Reshetov_child_2 :public Reshetov_child_1 // ������ � ���������� A/B
{
	char* group_id2;
public:
	char Get_group_id2() { return *group_id2; }
	void Set_group_id2(char tmp) { group_id2 = new char(tmp); }
	void Print_state() { std::cout << "� ������������ " << Get_u_name() << " ���� ������ ����� " << Get_group_id() << " � ��������� " << Get_group_id2() << '\n'; }

	Reshetov_child_2(const Reshetov_child_2& obj) :Reshetov_child_1(obj), group_id2(new char('�')) { *group_id2 = *obj.group_id2; }
	Reshetov* copy() { return new Reshetov_child_2(*this); }

	Reshetov_child_2(std::string tmp1, int tmp2, char tmp3) : group_id2(new char(tmp3)), Reshetov_child_1(tmp1, tmp2){}
	Reshetov_child_2() : group_id2(new char('�')), Reshetov_child_1() {}
	virtual~Reshetov_child_2() { delete group_id2; }
	
};

class Reshetov_child_3 :public Reshetov_child_2 // ������ � ������ � �������� �������� (string)
{
	std::string* s_name;                        // ���
	std::string* s_surname;                     // �������
	std::string* s_patr;                        // ��������
public:
	void Print_state() { std::cout << "� ������������ " << Get_u_name() << " ���� ������ ����� " << Get_group_id() << " � ��������� " << Get_group_id2() << " � ��� ���� ������� " << Get_s_surname() << " " << Get_initials() << '\n'; }

	std::string Get_s_surname() { return *s_surname; }
	std::string Get_initials(){ return ((*s_name).substr(0, 1) + "." + (*s_patr).substr(0, 1) + "."); }

	Reshetov_child_3(const Reshetov_child_3& obj) :Reshetov_child_2(obj), s_name(new std::string("��������")), s_surname(new std::string("�������")), s_patr(new std::string("���������")) { *s_name = *obj.s_name; *s_surname = *obj.s_surname; *s_patr = *obj.s_patr;}
	Reshetov* copy() { return new Reshetov_child_3(*this); }

	Reshetov_child_3(std::string tmp1, int tmp2, char tmp3, std::string surname, std::string name, std::string patr) : s_surname(new std::string(surname)), s_name(new std::string(name)), s_patr(new std::string(patr)), Reshetov_child_2(tmp1, tmp2, tmp3) {}
	Reshetov_child_3() : s_name(new std::string("��������")), s_surname(new std::string("�������")), s_patr(new std::string("���������")), Reshetov_child_2() {}

	~Reshetov_child_3() { delete s_name; delete s_surname; delete s_patr;}

};

int main() {
	
	setlocale(LC_ALL, "Russian");
	std::vector<Reshetov*>v;
	std::vector<Reshetov*>v2;

	v.push_back(new Reshetov ("����"));
	v.push_back(new Reshetov_child_1 ("���", 8677));
	v.push_back(new Reshetov_child_2 ("�����", 8677, '�'));
	v.push_back(new Reshetov_child_3 ("���", 8677, '�', "������", "����", "��������"));
	v.push_back(new Reshetov_child_3);

	for (std::vector<Reshetov*>::iterator it = v.begin(); it != v.end(); ++it)
	{
		Reshetov* new_obj = (*it)->copy();
		v2.insert(v2.end(), new_obj);
	}


	for (Reshetov* obj : v) { //������� ������� �������
		delete obj;
	}
	v.clear();

	for (int i = 0; i < v2.size(); i++) //�������� ����������� ���������� ������� �������
	{
		v2.at(i)->Print_state();
	}

	for (Reshetov* obj : v2) { //������� ������� �������
		delete obj;
	}
	v2.clear();

	return 0;
}