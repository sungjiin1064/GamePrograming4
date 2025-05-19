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
		cout << "몬스터 이름 : " << _name << endl;
	}

	void takeDamage(int dmg)
	{
		_hp -= dmg;
		if (_hp = 0)
		{
			cout << _name << " 이 패배했습니다." << endl;
		}
		else
		{
			cout << " 남은 체력 : " << _hp <<   endl;
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
		cout << "사냥한 몬스터 목록" << endl;
		int i = 1;
		for (const auto& monster : huntedMonster)
		{
			cout << i << " 번째 사냥한 몬스터" << monster._name << endl;
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
		//cout << "몬스터에게 " << playerAttackDMG << " 만큼 공격을 했습니다.";
		selectMonster.takeDamage(playerAttackDMG);
	}
}