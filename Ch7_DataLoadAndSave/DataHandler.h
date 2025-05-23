#pragma once

#include <fstream>
#include <iostream>

using namespace std;

class Data
{
public:
	int _exp;
	int _level;

public:
	Data() : _exp(100), _level(1) {}

	void SaveData(const string& filename)
	{
		ofstream file(filename);

		if (file.is_open())
		{
			file << _level << " "<< _exp << endl;
			file.close();
			
		}

	}

	void LoadData(const string& filename)
	{
		ifstream file(filename);

		
		int exp, level;

		file >> level >> exp;
		

		

		_level = level;
		_exp = exp;

	

	}
};