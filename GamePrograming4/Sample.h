#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class PocketMonster
{
private:
	int _number;
	string _name;
public:
	PocketMonster(int number, string name)
		: _number(number), _name(name) { }

	int Get_Number() const
	{
		return _number;
	}
	string Get_Name() const
	{
		return _name;
	}

	bool operator < (const PocketMonster& other)
	{
		return this->_number < other.Get_Number();		
	}

	bool operator > (const PocketMonster& other)
	{
		return this->_number > other.Get_Number();
	}

};

void Example()
{
	PocketMonster pica(25, "��ī��");
	PocketMonster �̻��ؾ�(1, "�̻��ؾ�");
	PocketMonster ���̸�(10, "���̸�");
	PocketMonster ���α�(8, "���α�");
	PocketMonster ����(16, "����");

	//cout << "No. " << pica.Get_Number() << " " << pica.Get_Name() << endl;

	
	cout <<"�̻��ؾ��� ��ī�� ���� ���� ��ȣ�� ū����?  " ;

	if (pica < �̻��ؾ�)
	{
		cout << "��." << endl;
	}
	else
	{
		cout << "�ƴϿ�." << endl;
	}

	vector<PocketMonster> pocketDatabase;

	pocketDatabase.push_back(pica);
	pocketDatabase.push_back(�̻��ؾ�);
	pocketDatabase.push_back(���̸�);
	pocketDatabase.push_back(���α�);
	pocketDatabase.push_back(����);

	sort(pocketDatabase.begin(), pocketDatabase.end());

	//reverse(pocketDatabase.begin(), pocketDatabase.end());

	for (auto& pocketmon : pocketDatabase)
	{
		cout << "No. " << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
	}

	/*for (auto& pocketmon : pocketDatabase)
	{
		cout << pocketmon.Get_Number()<<"�� ���͸� ã�Ҵ�.";
		cout << "No. " << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
	}*/
	
	

}