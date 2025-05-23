#pragma once

#include <iostream>
#include <vector>
#include "ConsoleUtility.h"

using namespace std;

struct DropItem
{
	int _index;
	int _exp;
	int _money;

	DropItem() = default;
	DropItem(int index ,int exp,int money) : _index(index), _exp(exp), _money(money) {}

};

class Monster
{
private:
	int _exp;
	int _money;

	std::vector<DropItem> dropTable;
	DropItem currentDropItem;

public:

	Monster(int exp, int money) : _exp(exp), _money(money)
	{
		dropTable.emplace_back(1, 10, 100);
		dropTable.emplace_back(2, 20, 200);
		dropTable.emplace_back(3, 30, 300);
		dropTable.emplace_back(4, 40, 400);
		dropTable.emplace_back(5, 50, 500);
	}

	void SetDropItem()
	{
		int index = ConsoleUtil::GetRandomInt(dropTable.size() -1);

		currentDropItem = dropTable[index];
	}

	void GetDropPoint()
	{
		cout << "È¹µæÇÑ °æÇèÄ¡ : " << currentDropItem._exp<< endl;
		cout << "È¹µæÇÑ µ· : " << currentDropItem._money<< endl;
	}
};