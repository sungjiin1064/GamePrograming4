#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>

using namespace std;

void find_test()
{
	cout << "\n=======================" << endl;
	std::vector<int> nums = { 1,2,3,4,5 };

	auto it =  std::find(nums.begin(), nums.end(), 3);

	if (it != nums.end())
	{
		cout << *it << endl;
	}
	else
	{
		cout << "데이터를 찾지 못했습니다" << endl;
	}

}

struct Monster
{
	int _id;
	string _name;

	Monster(int id,string name) : _id(id), _name(name){}
};

//void find_test2()
//{
//	std::vector<Monster> monsters;
//
//	monsters.emplace_back
//}