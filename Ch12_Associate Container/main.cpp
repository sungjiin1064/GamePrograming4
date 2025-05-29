
#include <set>
#include <map>
#include <algorithm>

#include <iostream>
#include <iomanip>
#include <utility>

using namespace std;

//#pragma region#pragma endregion

#pragma region 연관 컨테이너 사용하기

void Test1()
{
	std::set<int> nums;

	cout << "Set의 데이터가 자동으로 정렬됨" << endl;
	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7);

	for (const auto& num : nums)
	{
		cout << num << " ";
	}
	cout << endl;

	cout << "Set의 데이터는 중복이 안됨" << endl;
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
	cout << "연관 컨테이너 앞에 특정 키워드를 붙이면 성질이 변한다." << endl;
	std::multiset<int> nums;

	cout << "Set의 데이터가 자동으로 정렬됨" << endl;
	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7);

	for (const auto& num : nums)
	{
		cout << num << " ";
	}
	cout << endl;

	cout << "Set의 데이터는 중복이 된다." << endl;
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

#pragma region 커스텀 클랴스를 set에 넣는 방법

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
	cout << "커스텀 객체를 Set으로 출력하기" << endl;
	std::set<Item> items;

	Item item1(1, "유리");
	Item item2(2, "김");
	Item item3(3, "바나나");
	Item item4(100, "칼");
	Item item5(50, "방패");


	items.insert(item1);
	items.insert(item2);
	items.insert(item3);
	items.insert(item4);
	items.insert(item5);

	cout << "중복을 허용 안함" << endl;
	items.insert(Item(3, "투구"));

	for (const auto& item : items)
	{
		cout << item.id << " " << item.name << endl;
	}

	cout << "Set을 사용하면 데이터의 크기에 따라 자동으로 정렬한 결과를 얻을 수 있습니다." << endl;
	cout << "find함수를 사용해서 빠르게 데이터를 찾을 수 있다." << endl;
}

#pragma endregion

#pragma region map 사용하기

void Test4()
{
	cout << "map 자료구조 사용하기" << endl;

	std::map<int, Item> items;

	// pair클래스를 선언. 중괄호를 사용하기
	items.insert({ 0,Item(100,"포션") });

	items.insert(make_pair(10, Item(1000, "롱소드")));

	std::pair<int, Item> p1(5, Item(101, "빨간포션"));

	items.insert(p1);

	cout << "특징1. map는 pair로 이루어진 데이터를 저장하는 컨테이너이다." << endl;
	cout << "특징2. map의 key값으로 자동 정렬이 이루어집니다." << endl;

	for (const auto& item : items)
	{
		cout << item.first << " " << " ID : " << item.second.id << " 이름 : " << item.second.name << endl;
	}

	cout << "특징3. 사전(Dictionary)형 자료구조입니다." << endl;

	cout << items[0].id << items[0].name << endl;

}

#pragma endregion

#pragma region 연관 컨테이너 실습

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
	map1.insert({"김", 0});
	map1.insert({"임", 1});
	//map1.insert(make_pair("다",2));
	//map1.insert(make_pair("라",3));

	for (const auto& e : map1)
	{
		cout << "[";
		cout << e.first << " " << e.second;
		cout << "]"<<" ";
	}
	
	cout << "김 키워드에는 어떠한 숫자가 들어있습니까? " << map1["김"] << endl;

	std::map<int, int> map2;
	map2.insert({0,10});
	map2.insert({5,100});

	cout << "map2 컨테이너 안에 0이라는 키워드에는 어떠힌 숫자가 들어있습니까" << map2[0] << endl;

	std::map<string, Item> map3;
	map3.insert({"롱소드", Item()});

	//cout << "map3를 사용해서 특정이름으로 아이템을 찾는 방법" << map3["롱소드"] << endl;
}

#pragma endregion //미완성

#pragma region 상점 UI 및 기능 구현하기

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