
#include <set>
#include <map>
#include <algorithm>

#include <iostream>
#include <iomanip>
#include <utility>

using namespace std;

//#pragma region#pragma endregion

#pragma region ���� �����̳� ����ϱ�

void Test1()
{
	std::set<int> nums;

	cout << "Set�� �����Ͱ� �ڵ����� ���ĵ�" << endl;
	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7);

	for (const auto& num : nums)
	{
		cout << num << " ";
	}
	cout << endl;

	cout << "Set�� �����ʹ� �ߺ��� �ȵ�" << endl;
	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7);


	for (const auto& num : nums)
	{
		cout << num << " ";
	}
	cout << endl;

}

void Test2()
{
	cout << "���� �����̳� �տ� Ư�� Ű���带 ���̸� ������ ���Ѵ�." << endl;
	std::multiset<int> nums;

	cout << "Set�� �����Ͱ� �ڵ����� ���ĵ�" << endl;
	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7);

	for (const auto& num : nums)
	{
		cout << num << " ";
	}
	cout << endl;

	cout << "Set�� �����ʹ� �ߺ��� �ȴ�." << endl;
	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7);

	for (const auto& num : nums)
	{
		cout << num << " ";
	}
	cout << endl;
}

#pragma endregion

#pragma region Ŀ���� Ŭ������ set�� �ִ� ���

struct Item
{
	int id;
	string name;
	
	Item() = default;
	Item(int id, string name) : id(id), name(name) {}

	bool operator<(const Item& other) const
	{
		return id < other.id;
		//return name < other.name;
	}
};

void Test3()
{
	cout << "Ŀ���� ��ü�� Set���� ����ϱ�" << endl;
	std::set<Item> items;

	Item item1(1, "����");
	Item item2(2, "��");
	Item item3(3, "�ٳ���");
	Item item4(100, "Į");
	Item item5(50, "����");


	items.insert(item1);
	items.insert(item2);
	items.insert(item3);
	items.insert(item4);
	items.insert(item5);

	cout << "�ߺ��� ��� ����" << endl;
	items.insert(Item(3, "����"));

	for (const auto& item : items)
	{
		cout << item.id << " " << item.name << endl;
	}

	cout << "Set�� ����ϸ� �������� ũ�⿡ ���� �ڵ����� ������ ����� ���� �� �ֽ��ϴ�." << endl;
	cout << "find�Լ��� ����ؼ� ������ �����͸� ã�� �� �ִ�." << endl;
}

#pragma endregion

#pragma region map ����ϱ�

void Test4()
{
	cout << "map �ڷᱸ�� ����ϱ�" << endl;

	std::map<int, Item> items;

	// pairŬ������ ����. �߰�ȣ�� ����ϱ�
	items.insert({ 0,Item(100,"����") });

	items.insert(make_pair(10, Item(1000, "�ռҵ�")));

	std::pair<int, Item> p1(5, Item(101, "��������"));

	items.insert(p1);

	cout << "Ư¡1. map�� pair�� �̷���� �����͸� �����ϴ� �����̳��̴�." << endl;
	cout << "Ư¡2. map�� key������ �ڵ� ������ �̷�����ϴ�." << endl;

	for (const auto& item : items)
	{
		cout << item.first << " " << " ID : " << item.second.id << " �̸� : " << item.second.name << endl;
	}

	cout << "Ư¡3. ����(Dictionary)�� �ڷᱸ���Դϴ�." << endl;

	cout << items[0].id << items[0].name << endl;

}

#pragma endregion

#pragma region ���� �����̳� �ǽ�

struct NewItem
{
	string _name;
	int _ATK;
	int _price;

	NewItem() = default;
	NewItem(string name, int ATK, int price) : _name(name), _ATK(ATK), _price(price) {}
};

void Test5()
{
	std::map<string, int> map1;
	map1.insert({"��", 0});
	map1.insert({"��", 1});
	//map1.insert(make_pair("��",2));
	//map1.insert(make_pair("��",3));

	for (const auto& e : map1)
	{
		cout << "[";
		cout << e.first << " " << e.second;
		cout << "]"<<" ";
	}
	
	cout << "�� Ű���忡�� ��� ���ڰ� ����ֽ��ϱ�? " << map1["��"] << endl;

	std::map<int, int> map2;
	map2.insert({0,10});
	map2.insert({5,100});

	cout << "map2 �����̳� �ȿ� 0�̶�� Ű���忡�� ��� ���ڰ� ����ֽ��ϱ�" << map2[0] << endl;

	std::map<string, Item> map3;
	map3.insert({"�ռҵ�", Item()});

	//cout << "map3�� ����ؼ� Ư���̸����� �������� ã�� ���" << map3["�ռҵ�"] << endl;
}

#pragma endregion //�̿ϼ�

#pragma region ���� UI �� ��� �����ϱ�

class Player
{
	int money;

public:
	Player(int money) : money(money) {}

	void BuyItem(NewItem item)
	{

	}

};

class Shop
{
private:

public:
	Shop()
	{

	}

	void SellItem(Player& player)
	{

	}

};

void ShopTest()
{

}

#pragma endregion

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();

}