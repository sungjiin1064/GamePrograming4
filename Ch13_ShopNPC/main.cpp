
#include <iostream>
#include <map>
#include <conio.h>
#include "ConsoleUtility.h"

#include <fstream> // ifstream ofstream
#include <iomanip> // 입출력 조작 헤어
#include <utility> // pair클래스가 정의되어있다.
#include <string>
#include <unordered_map>

using namespace std;

//#pragma region#pragma endregion

const int total_width = 60;
const int field1_width = 30;
const int field2_width = 15;
const int field3_width = 15;

class Item
{
public:
	string name;
	int price;
	string type;
public:
	Item() = default;
	Item(string name, int price, string type) : name(name), price(price), type(type) {}

	virtual void Use() = 0;
};

class Weapon : public Item
{
public:
	Weapon(string name, int price, string type) : Item(name, price, type) {}

	void Use() override
	{
		cout << "무기를 사용합니다" << endl;
	}
};

/// <summary>
/// 아이템을 use했을 때 사라지는 종류의 아이템입니다.
/// Player클래스 의 RemoveItem을 사용하세요.
/// </summary>
class UsableItem : public Item
{
public:
	UsableItem(string name, int price, string type) : Item(name, price, type) {}

	void Use() override
	{
		cout << "소비성 아이템을 사용합니다" << endl;
		// Remove되는 아이템을 호출하세요.
	}
};

#pragma region Player 코드

class Player
{
private:
	std::unordered_map<string, Item*> inventory;

public:
	int posX, posY, money;

#pragma region 인벤토리 코드

	void AddItem(Item* item)
	{
		inventory.insert({ item->name, item });
	}

	void RemoveItem(string name)
	{
		if (inventory.find(name) != inventory.end())
		{
			inventory.erase(name);
		}
		else
		{
			cout << "인벤토리에 해당하는 아이템이 없습니다." << endl;
		}
	}

	void RemoveItem(Item* item)
	{		
		if (inventory.find(item->name) != inventory.end())
		{
			inventory.erase(item->name);

		}
	}

	void Use(Item* item)
	{

		item->Use();
	}

#pragma endregion

	

	Player() = default;
	Player(int posX, int posY, int money) : posX(posX), posY(posY), money(money) {}

	void ShowPlayerUI()
	{
		int count = 0;

		system("cls");
		ConsoleUtil::GotoXY(70, 1);
		cout << "플레이어의 정보";
		ConsoleUtil::GotoXY(70, 3);
		cout << "소지금 : " << money << endl;;
		ConsoleUtil::GotoXY(70, 5);
		cout << "보유한 아이템 목록"  << endl;;
		ConsoleUtil::GotoXY(70, 7);
		for (const auto& item : inventory)
		{
			cout << item.first << " ";
			count++;

			if (count % 2 == 0)
			{
				cout << endl;
				ConsoleUtil::GotoXY(70, 7 + (count / 2));
			}
		}

	}

	void BuyItem(Item* item)
	{
		money -= item->price;
		AddItem(item);
		Use(item); // 구입시 아이템 자동사용
		
	}
};

#pragma endregion

#pragma region 상점 코드

class Shop
{
private:
	std::map<int, Item*> items;

public:
	Shop()
	{
		items.insert({ 0, new Weapon("롱소드", 100, "무기") });
		items.insert(make_pair(1, new Weapon("체력포션", 5, "소비")));
		std::pair<int, Item*> p1(2, new Weapon("나무방패", 50, "무기"));
		items.insert(p1);
		items.insert({ 3, new Weapon("마나포션", 5, "소비") });
		items.insert({ 4, new Weapon("귀걸이", 30, "악세사리") });

		/*items.insert({ 0, new Weapon("강한포션", 10, "소비") });
		items.insert(make_pair(1, new Weapon("체력포션", 5, "소비")));
		std::pair<int, Item*> p1(2, new Weapon("해독포션", 11, "소비"));
		items.insert(p1);
		items.insert({ 3, new Weapon("마나포션", 5, "소비") });
		items.insert({ 4, new Weapon("스피드포션", 20, "소비") });*/

		//items.insert({ 0, new Weapon("롱소드", 100, "무기") });
		//items.insert(make_pair(1, new Weapon("숏소드", 50, "무기")));
		//std::pair<int, Item*> p1(2, new Weapon("나무방패", 50, "무기"));
		//items.insert(p1);
		//items.insert({ 3, new Weapon("강철검", 500, "무기") });
		//items.insert({ 4, new Weapon("대검", 300, "무기") });
	}

	Shop(std::string filename)
	{
		LoadShopData(filename);
	}
	
	void LoadShopData(std::string filename)
	{
		ifstream in_file;
		in_file.open(filename);

		string name;
		int price;
		string type;

		if (!in_file)
		{
			cerr << "파일을 여는데 실패했습니다." << endl;
			exit(1);
		}

		int index = 0;

		/*while (!in_file.eof())
		{
			in_file >> name >> price >> type;
			items.insert({ index ,Item(name, price, type)});
			index++;
				
		}*/

		while (in_file>>name>>price>>type)
		{	
			if (type == "무기")
			{
				items.insert({ index , new Weapon(name, price, type) });
				index++;
			}
			/*else if (type == "악세사리")
			{

			}*/
			else
			{
				items.insert({ index , new UsableItem(name, price, type) });
				index++;
			}
		}

		in_file.close();
	}

	void SaveShopData(string filename)
	{
		ofstream out_file;
		out_file.open(filename);

		string name;
		int price;
		string type;

		if (!out_file)
		{
			cerr << "파일을 여는데 실패했습니다." << endl;
			exit(1);
		}

		for (int i = 0; i < items.size(); i++) 
		{
			out_file << setw(field1_width) << left << items[i]->name <<
				setw(field2_width) << right << items[i]->price <<
				setw(field3_width) << right << items[i]->type << endl;
		}

		out_file.close();
	}

	void ShowItems(int x,int y)
	{
		/*for (const auto& elem : items)
		{

		}*/

		string headersize = "012345678901234567890123456789012345678901234567890123456789";

		// 머릿말
		//std::cout << headersize << endl;

		ConsoleUtil::GotoXY(x, y);
		cout << setw(field1_width) << left << "이름" <<
			setw(field2_width) << right << "가격" <<
			setw(field3_width) << right << "타입" << endl;
				
		// 라인을 긋는 방법
		//ConsoleUtil::GotoXY(0, 11);
		cout << setw(total_width) << setfill('=') << "" << endl;
		cout << setfill(' ');

		for (int i = 0; i < items.size(); i++) // 인덱스 기반 접근이 가능한 자료구조여야 한다.
		{ 
			//ConsoleUtil::GotoXY(0, 10);
			cout << setw(field1_width) << left << items[i]->name <<
				setw(field2_width) << right << items[i]->price <<
				setw(field3_width) << right << items[i]->type << endl;

			cout << setw(total_width) << setfill('-') << "" << endl;
			cout << setfill(' ');
		}

	}

	bool BuyItem(int index, Player& player)
	{
		if (items.find(index) != items.end())
		{
			Item* itemInstance = items[index];

			if (player.money >= itemInstance->price)
			{
				player.BuyItem(itemInstance);
				return true;
			}
			else
			{
				cout << "소지금이 부족합니다." << endl;
			}
		}
		else
		{
			cout << "아이템을 찾지 못했습니다." << endl;
		}
	}

	void Interact(Player& player)
	{
		int select;

		cout << "번호를 입력해서 아이템을 구해할 수 있습니다." << endl;
		cin >> select;

		BuyItem(select, player);		
	}

};

#pragma endregion

#pragma region NPC 코드

class NPC
{
private:
	Shop shop;

public:
	int posX;
	int posY;
	bool isActivate;

	NPC() = default;
	NPC(string filename, int posX, int posY) : posX(posX),posY(posY), isActivate(true)
	{
		shop = Shop(filename);
	}

	void ShowItems(int x, int y)
	{
		shop.ShowItems(x,y);
	}
	
	void Interact(Player& player)
	{
		shop.Interact(player);
		isActivate = false;
	}

	void ShowNPC()
	{
		if (isActivate == false)
		{
			return;
		}

		ConsoleUtil::GotoXY(posX, posY);
		cout << "$";
	}

};

void Interact(Player& player,NPC& npc,int UI_X, int UI_Y )
{
	if (player.posX == npc.posX && player.posY == npc.posY)
	{
		if(npc.isActivate == false) // if(!npc.isActivate)
		{			
			return;
		}
		npc.ShowItems(UI_X, UI_Y);
		npc.Interact(player);
	}
}


#pragma endregion


int main()
{
	ConsoleUtil::SetCursorVisible(false);

	Player player(10, 10, 1000);

	//int playerX = 10;
	//int playerY = 10;
		
	/*Shop shop;
	shop.SaveShopData("shop3.txt");*/

	//Shop shop("shop3.txt");	

	NPC npc1("shop1.txt", 3, 5);
	NPC npc2("shop2.txt", 10, 2);
	NPC npc3("shop3.txt", 8, 6);

	while (true)
	{
		if (_kbhit())
		{
			system("cls");

			if (GetAsyncKeyState(VK_UP))
			{
				player.posY--;
				if (player.posY <= 0) { player.posY = 0; }
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				player.posY++;
			}
			if (GetAsyncKeyState(VK_LEFT))
			{
				player.posX--;
				if (player.posX <= 0) { player.posX = 0; }
			}
			if (GetAsyncKeyState(VK_RIGHT))
			{
				player.posX++;
			}
		}
			
		player.ShowPlayerUI();

		npc1.ShowNPC();
		npc2.ShowNPC();
		npc3.ShowNPC();

		Interact(player, npc1, 0, 10);
		Interact(player, npc2, 0, 10);
		Interact(player, npc3, 0, 10);

		//shop.ShowItems();

		ConsoleUtil::GotoXY(player.posX, player.posY);
		std::cout << "a";

		_getch();
	}
}

