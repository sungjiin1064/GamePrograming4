
#include <iostream>
#include <vector>

using namespace std;

enum Trait
{
	Strength,
	Dexterity,
	Inteligence
};

enum Stat
{
	Damage,
	Health,
	Mana,
	Speed
	
};

class TraitBonus
{
private:
	void IncreaseStat(Stat stat, int amount)
	{
		Stats[static_cast<int>(stat)] += amount;
	}

public:
	Trait trait;
	Stat stat;
	int additiveBonusPoint;
	std::vector<int> Stats;

	TraitBonus() : Stats(4, 0) {};
	TraitBonus(Trait trait, Stat stat, float additiveBonusPoint)
		: trait(trait), stat(stat), additiveBonusPoint(additiveBonusPoint), Stats(4, 0) {}

	void GetTrait(Trait trait)
	{
		switch (trait)
		{
		case Trait::Strength:
			IncreaseStat(Damage, 5);
			IncreaseStat(Health, 1);
			break;
		case Trait::Dexterity:
			IncreaseStat(Speed, 1);

			break;
		case Trait::Inteligence:
			IncreaseStat(Mana, 5);
			break;
		}
	}

	void ShowStat()
	{
		cout << "Damage : " << Stats[Damage] << endl;
		cout << "Health : " << Stats[Health] << endl;
		cout << "Mana   : " << Stats[Mana] << endl;
		cout << "Speed   : " << Stats[Speed] << endl;
	}
	
};

class Player
{
	std::vector<TraitBonus> traitmanager;
	
	std::vector<int> stats;

public:
	Player() : stats(4, 0)
	{
		stats[static_cast<int>(Stat::Damage)] = 5;
		stats[static_cast<int>(Stat::Health)] = 50;
		stats[static_cast<int>(Stat::Mana)] = 100;
	}

	void IncreaseStat(Stat stat, int amount)
	{
		stats[static_cast<int>(stat)] += amount;
	}

	void ShowPlayerStat()
	{
		cout << "Damage : " << stats[Damage] <<endl;
		cout << "Health : " << stats[Health] <<endl;
		cout << "Mana   : " << stats[Mana] <<endl;
	}
};

void EnumTest1()
{
	int num = Stat::Damage;

	Stat someType = (Stat)num;                //   C 형태의 형변환
	Stat someType2 = static_cast<Stat>(num);  // CPP 형태의 형변환

	if (someType2 == Stat::Damage)
	{
		cout << num << endl;
		//cout << "스텟::데미지가 출력되었습니다." << endl;
	}

	
}

void EnumTest2()
{
	Player player;

	player.IncreaseStat(Stat::Damage, 5);
	player.ShowPlayerStat();
}

void EnumTest3()
{
	TraitBonus traits;

	traits.GetTrait(Trait::Strength);

	traits.ShowStat();


}

void EnumTest4()
{
	Player player;
	
}

int main()
{
	EnumTest1();
	//EnumTest2();
}