
#include <iostream>
#include <map>
#include <conio.h>
#include "ConsoleUtility.h"

#include <fstream> // ifstream ofstream
#include <iomanip> // 입출력 조작 헤어
#include <utility> // pair클래스가 정의되어있다.

using namespace std;

//#pragma region#pragma endregion

const int total_width = 60;
const int field1_width = 30;
const int field2_width = 15;
const int field3_width = 15;

#pragma region 상점 코드

class Item
{
public:
	string name;
	int price;
	string type;
public:
	Item() = default;
	Item(string name,int price, string type) : name(name), price(price), type(type) {}
};

class Shop
{
private:
	std::map<int, Item> items;

public:
	Shop()
	{
		/*items.insert({ 0, Item("롱소드", 100, "무기") });
		items.insert(make_pair(1, Item("체력포션", 5, "소비")));
		std::pair<int, Item> p1(2, Item("나무방패", 50, "무기"));
		items.insert(p1);
		items.insert({ 3, Item("마나포션", 5, "소비") }); 
		items.insert({ 4, Item("귀걸이", 30, "악세사리") });*/

		/*items.insert({ 0, Item("강한포션", 10, "소비") });
		items.insert(make_pair(1, Item("체력포션", 5, "소비")));
		std::pair<int, Item> p1(2, Item("해독포션", 11, "소비"));
		items.insert(p1);
		items.insert({ 3, Item("마나포션", 5, "소비") });
		items.insert({ 4, Item("스피드", 20, "소비") });*/

		items.insert({ 0, Item("롱소드", 100, "무기") });
		items.insert(make_pair(1, Item("숏소드", 50, "무기")));
		std::pair<int, Item> p1(2, Item("나무방패", 50, "무기"));
		items.insert(p1);
		items.insert({ 3, Item("강철검", 500, "무기") });
		items.insert({ 4, Item("대검", 300, "무기") });
	}

	Shop(string filename)
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

		while (in_file.eof())
		{
			in_file >> name >> price >> type;
			items.insert({ index ,Item(name, price, type)});
			index++;
				
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
			out_file << setw(field1_width) << left << items[i].name <<
				setw(field2_width) << right << items[i].price <<
				setw(field3_width) << right << items[i].type << endl;
		}

		out_file.close();
	}

	void ShowItems()
	{
		/*for (const auto& elem : items)
		{

		}*/

		string headersize = "012345678901234567890123456789012345678901234567890123456789";

		// 머릿말
		std::cout << headersize << endl;

		cout << setw(field1_width) << left << "이름" <<
			setw(field2_width) << right << "가격" <<
			setw(field3_width) << right << "타입" << endl;
				
		// 라인을 긋는 방법
		cout << setw(total_width) << setfill('-') << "" << endl;
		cout << setfill(' ');

		for (int i = 0; i < items.size(); i++) // 인덱스 기반 접근이 가능한 자료구조여야 한다.
		{ 
			cout << setw(field1_width) << left << items[i].name <<
				setw(field2_width) << right << items[i].price <<
				setw(field3_width) << right << items[i].type << endl;
		}

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

	NPC() = default;
	NPC(string filename, int posX, int posY) : posX(posX),posY(posY)
	{
		shop = Shop(filename);
	}

	void ShowItems()
	{
		shop.ShowItems();
	}
	
	void ShowNPC()
	{
		ConsoleUtil::GotoXY(posX, posY);
		cout << "$";
	}

};

void Interact(int x1, int y1, NPC& npc)
{
	if (x1 == npc.posX && y1 == npc.posY)
	{
		npc.ShowItems();
	}
}



#pragma endregion

#pragma region Player 코드

class Player
{

};

#pragma endregion

int main()
{
	ConsoleUtil::SetCursorVisible(false);

	int playerX = 10;
	int playerY = 10;

	Shop shop;
	//Shop shop("shop2.txt");
	//shop.SaveShopData("shop3.txt");

	/*Shop shop("shop")
	shop.LoadShopData("shop2.txt");*/

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
				playerY--;
				if (playerY <= 0) { playerY = 0; }
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				playerY++;
			}
			if (GetAsyncKeyState(VK_LEFT))
			{
				playerX--;
				if (playerX <= 0) { playerX = 0; }
			}
			if (GetAsyncKeyState(VK_RIGHT))
			{
				playerX++;
			}
		}
		
		shop.ShowItems();

		ConsoleUtil::GotoXY(playerX, playerY);
		std::cout << "a";

		_getch();
	}
}