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
	PocketMonster pica(25, "피카츄");
	PocketMonster 이상해씨(1, "이상해씨");
	PocketMonster 파이리(10, "파이리");
	PocketMonster 꼬부기(8, "꼬부기");
	PocketMonster 구구(16, "구구");

	//cout << "No. " << pica.Get_Number() << " " << pica.Get_Name() << endl;

	
	cout <<"이상해씨가 피카츄 보다 도감 번호가 큰가요?  " ;

	if (pica < 이상해씨)
	{
		cout << "네." << endl;
	}
	else
	{
		cout << "아니오." << endl;
	}

	vector<PocketMonster> pocketDatabase;

	pocketDatabase.push_back(pica);
	pocketDatabase.push_back(이상해씨);
	pocketDatabase.push_back(파이리);
	pocketDatabase.push_back(꼬부기);
	pocketDatabase.push_back(구구);

	sort(pocketDatabase.begin(), pocketDatabase.end());

	//reverse(pocketDatabase.begin(), pocketDatabase.end());

	for (auto& pocketmon : pocketDatabase)
	{
		cout << "No. " << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
	}

	/*for (auto& pocketmon : pocketDatabase)
	{
		cout << pocketmon.Get_Number()<<"번 몬스터를 찾았다.";
		cout << "No. " << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
	}*/
	
	

}