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
		if (_hp <= 0)
		{
			cout << _name << " �� �й��߽��ϴ�." << endl;
		}
		else
		{
			cout <<_name <<"�� ���� ü�� : " << _hp <<   endl;
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
			i++;
		}
	}

};

void Battle(Player& player, Monster* monster)
{
	std::vector<Monster> monsters =
	{
		Monster("Goblin", 50,5),
		Monster("Orc", 80,6),
		Monster("Dragon", 60,11),
		Monster("Zombie", 70,8),
		Monster("Vampire", 90,10)
	};

	int randIndex = ConsoleUtil::GetRandomInt(monsters.size() - 1);
	Monster& selectMonster = monsters[randIndex];

	int playerAttackDMG = 10;

	while (selectMonster._hp > 0)
	{
		cout << selectMonster._name<< playerAttackDMG << " ��ŭ ����-> ";
		selectMonster.takeDamage(playerAttackDMG);
		Sleep(500);
	}
	player.huntMonster(selectMonster);
}