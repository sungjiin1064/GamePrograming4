
#include <iostream>
#include <map>
#include <conio.h>
#include "ConsoleUtility.h"

#include <fstream> // ifstream ofstream
#include <iomanip> // ����� ���� ���
#include <utility> // pairŬ������ ���ǵǾ��ִ�.

using namespace std;

//#pragma region#pragma endregion

const int total_width = 60;
const int field1_width = 30;
const int field2_width = 15;
const int field3_width = 15;

#pragma region ���� �ڵ�

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
		/*items.insert({ 0, Item("�ռҵ�", 100, "����") });
		items.insert(make_pair(1, Item("ü������", 5, "�Һ�")));
		std::pair<int, Item> p1(2, Item("��������", 50, "����"));
		items.insert(p1);
		items.insert({ 3, Item("��������", 5, "�Һ�") }); 
		items.insert({ 4, Item("�Ͱ���", 30, "�Ǽ��縮") });*/

		/*items.insert({ 0, Item("��������", 10, "�Һ�") });
		items.insert(make_pair(1, Item("ü������", 5, "�Һ�")));
		std::pair<int, Item> p1(2, Item("�ص�����", 11, "�Һ�"));
		items.insert(p1);
		items.insert({ 3, Item("��������", 5, "�Һ�") });
		items.insert({ 4, Item("���ǵ�", 20, "�Һ�") });*/

		items.insert({ 0, Item("�ռҵ�", 100, "����") });
		items.insert(make_pair(1, Item("���ҵ�", 50, "����")));
		std::pair<int, Item> p1(2, Item("��������", 50, "����"));
		items.insert(p1);
		items.insert({ 3, Item("��ö��", 500, "����") });
		items.insert({ 4, Item("���", 300, "����") });
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
			cerr << "������ ���µ� �����߽��ϴ�." << endl;
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
			cerr << "������ ���µ� �����߽��ϴ�." << endl;
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

		// �Ӹ���
		std::cout << headersize << endl;

		cout << setw(field1_width) << left << "�̸�" <<
			setw(field2_width) << right << "����" <<
			setw(field3_width) << right << "Ÿ��" << endl;
				
		// ������ �ߴ� ���
		cout << setw(total_width) << setfill('-') << "" << endl;
		cout << setfill(' ');

		for (int i = 0; i < items.size(); i++) // �ε��� ��� ������ ������ �ڷᱸ������ �Ѵ�.
		{ 
			cout << setw(field1_width) << left << items[i].name <<
				setw(field2_width) << right << items[i].price <<
				setw(field3_width) << right << items[i].type << endl;
		}

	}

};

#pragma endregion

#pragma region NPC �ڵ�

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

#pragma region Player �ڵ�

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