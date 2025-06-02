
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

#pragma region Player �ڵ�

class Item
{
public:
	string name;
	int price;
	string type;
public:
	Item() = default;
	Item(string name, int price, string type) : name(name), price(price), type(type) {}
};

class Player
{
private:

public:
	int posX, posY, money;

	Player() = default;
	Player(int posX, int posY, int money) : posX(posX), posY(posY), money(money) {}

	void ShowPlayerUI()
	{
		ConsoleUtil::GotoXY(70, 1);
		cout << "�÷��̾��� ����";
		ConsoleUtil::GotoXY(70, 3);
		cout << "������ : " << money;
	}

	void BuyItem(Item& item)
	{
		money -= item.price;
	}
};

#pragma endregion

#pragma region ���� �ڵ�

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

		items.insert({ 0, Item("��������", 10, "�Һ�") });
		items.insert(make_pair(1, Item("ü������", 5, "�Һ�")));
		std::pair<int, Item> p1(2, Item("�ص�����", 11, "�Һ�"));
		items.insert(p1);
		items.insert({ 3, Item("��������", 5, "�Һ�") });
		items.insert({ 4, Item("���ǵ�����", 20, "�Һ�") });

		//items.insert({ 0, Item("�ռҵ�", 100, "����") });
		//items.insert(make_pair(1, Item("���ҵ�", 50, "����")));
		//std::pair<int, Item> p1(2, Item("��������", 50, "����"));
		//items.insert(p1);
		//items.insert({ 3, Item("��ö��", 500, "����") });
		//items.insert({ 4, Item("���", 300, "����") });
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
			cerr << "������ ���µ� �����߽��ϴ�." << endl;
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
			items.insert({ index ,Item(name, price, type) });
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

	void ShowItems(int x,int y)
	{
		/*for (const auto& elem : items)
		{

		}*/

		string headersize = "012345678901234567890123456789012345678901234567890123456789";

		// �Ӹ���
		//std::cout << headersize << endl;

		ConsoleUtil::GotoXY(x, y);
		cout << setw(field1_width) << left << "�̸�" <<
			setw(field2_width) << right << "����" <<
			setw(field3_width) << right << "Ÿ��" << endl;
				
		// ������ �ߴ� ���
		//ConsoleUtil::GotoXY(0, 11);
		cout << setw(total_width) << setfill('=') << "" << endl;
		cout << setfill(' ');

		for (int i = 0; i < items.size(); i++) // �ε��� ��� ������ ������ �ڷᱸ������ �Ѵ�.
		{ 
			//ConsoleUtil::GotoXY(0, 10);
			cout << setw(field1_width) << left << items[i].name <<
				setw(field2_width) << right << items[i].price <<
				setw(field3_width) << right << items[i].type << endl;

			cout << setw(total_width) << setfill('-') << "" << endl;
			cout << setfill(' ');
		}

	}

	bool BuyItem(int index, Player& player)
	{
		if (items.find(index) != items.end())
		{
			Item itemInstance = items[index];

			if (player.money >= itemInstance.price)
			{
				player.BuyItem(itemInstance);
				return true;
			}
			else
			{
				cout << "�������� �����մϴ�." << endl;
			}
		}
		else
		{
			cout << "�������� ã�� ���߽��ϴ�." << endl;
		}
	}

	void Interact(Player& player)
	{
		int select;

		cout << "��ȣ�� �Է��Ͽ� �������� ������ �� �ֽ��ϴ�." << endl;
		cin >> select;

		BuyItem(select, player);
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
		if (isActivate = false)
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
		if(npc.isActivate == false) // if(!npc.isActivate == false)
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

