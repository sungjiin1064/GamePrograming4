#pragma once

#include "ConsoleUtility.h"
#include <vector>
#include <iostream>

using namespace std;

class Monster
{
private:

public:
	string _name;
	int _hp;
	int _atk;
public:
	Monster() = default;
	~Monster() = default;

	Monster(string name, int hp, int atk) 
		: _name(name), _hp(hp), _atk(atk){}

	void ShowInfo() const
	{
		cout << "���� �̸� : " << _name << endl;
	}

	void takeDamage(int dmg)
	{
		_hp -= dmg;
		if (_hp = 0)
		{
			cout << _name << " �� �й��߽��ϴ�." << endl;
		}
		else
		{
			cout << " ���� ü�� : " << _hp <<   endl;
		}

	}
};

class Player
{
private:
	std::vector<Monster> huntedMonster;

public:
	void huntMonster(const Monster& monster)
	{
		huntedMonster.push_back(monster);
	}

	void display() const
	{
		cout << "����� ���� ���" << endl;
		int i = 1;
		for (const auto& monster : huntedMonster)
		{
			cout << i << " ��° ����� ����" << monster._name << endl;
		}
	}

};

void Battle(Player& player)
{
	std::vector<Monster> monsters =
	{
		Monster("Goblin", 30,5),
		Monster("Orc", 10,6),
		Monster("Dragon", 60,11),
		Monster("Zombie", 20,8),
		Monster("Vampire", 40,10)
	};

	int randIndex = ConsoleUtil::GetRandomInt(monsters.size() - 1);
	Monster& selectMonster = monsters[randIndex];

	int playerAttackDMG = 10;

	while (selectMonster._hp > 0)
	{
		//cout << "���Ϳ��� " << playerAttackDMG << " ��ŭ ������ �߽��ϴ�.";
		selectMonster.takeDamage(playerAttackDMG);
	}
}