#pragma once

/*
* 생성자에 데이터를 직접 작성한다.
* vector.push_back()     - 이미있는 데이터를 넣을때
* vector.emplace_back()  - 생성하고 넣는 방식
*/

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct LevelExp
{
	int _level;
	int _maxExp;

	LevelExp(int level,int maxExp) : _level(level),_maxExp(maxExp){}
};

class Player
{
private:
	int _exp;
	int _maxExp;
	int _level;
	std::vector<LevelExp> levelTable;

public:
	Player() : _exp(0), _level(1), _maxExp(100) {}
	Player(int exp,int maxExp) :_level(1), _exp(exp),_maxExp(maxExp) 
	{
		levelTable.emplace_back(1, 100);
		levelTable.emplace_back(2, 100);
		levelTable.emplace_back(3, 100);
		levelTable.emplace_back(4, 100);
		levelTable.emplace_back(5, 100);
		levelTable.emplace_back(6, 150);
		levelTable.emplace_back(7, 150);
		levelTable.emplace_back(8, 150);
		levelTable.emplace_back(9, 150);
		levelTable.emplace_back(10, 150);
	}

	/*void LoadExpInExpTable(int i)
	{
		_maxExp = levelTable[i]._maxExp;
	}*/

	int GetMaxExpForLevel(int level)
	{
		for (const auto& data : levelTable)
		{
			if (level == data._level)
			{
				return data._maxExp;
			}
		}

		return -1;
	}

	void GetExp(int amount)
	{

		_maxExp = GetMaxExpForLevel(_level);

		if (_maxExp == -1)
		{
			cout << "최대 레벨에 도달하였습니다. 실행을 취소합니다" << endl;
			return;
		}

		_exp += amount;
		if (_exp >= _maxExp)
		{
			_level++;
			_exp -= _maxExp;
		}
	}

	void Show() const
	{
		cout << "Level " << _level << endl;
		cout << "Exp " << _exp << endl;
		cout << "MaxExp " << _maxExp << endl;
	}

	void SaveData(const string& filename)
	{
		ofstream file(filename);
		
		if (file.is_open())
		{
			file << _level << " " << _exp << " "<<_maxExp<<endl;
			file.close();
		}
	}

	void LoadData(const string& filename)
	{
		ifstream file(filename);

		int level, exp, maxExp;

		file >> level >> exp >> maxExp;

		_level = level;
		_exp = exp;
	}
};

