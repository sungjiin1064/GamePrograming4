#pragma once

#include <iostream>

class Combat
{
private:
	
public:
	virtual ~Combat() = default;

	virtual void attack(Combat& target) = 0;
	virtual void takeDamage(int damage) = 0;
	virtual void getHealth() = 0;
};

class Player : public Combat
{

};

class Monster
{

};
