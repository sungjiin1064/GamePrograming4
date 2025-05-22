#pragma once

#include <iostream>

using namespace std;

class Combat
{
private:
	
public:
	virtual ~Combat() = default;

	virtual void attack(Combat& target) = 0;
	virtual void takeDamage(int damage) = 0;
	virtual int getHealth() = 0;
};

class Player : public Combat
{
private:
	int _health;
	int _ATK;

public:
	Player(int health, int ATK) : _health(health), _ATK(ATK) {}

	void attack(Combat& target) override
	{
		target.takeDamage(_ATK);
	}

	void takeDamage(int damage) override
	{
		_health -= damage;
		cout << "Player가 " << damage << " 의 피해를 입었습니다" << endl;
	}

	int getHealth() override
	{
		return _health;
	}
};

class Monster : public Combat
{
private:
	int _health;
	int _ATK;

public:
	Monster(int health, int ATK) : _health(health), _ATK(ATK) {}

	void attack(Combat& target) override
	{
		target.takeDamage(_ATK);
	}

	void takeDamage(int damage) override
	{
		_health -= damage;
		cout << "Monster가 " << damage << " 의 피해를 입었습니다" << endl;
	}

	int getHealth() override
	{
		return _health;
	}
};