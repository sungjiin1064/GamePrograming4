
#include <iostream>
#include <map>
#include <unordered_map>
#include "ConsoleUtility.h"

using namespace std;

#pragma region
#pragma endregion

#pragma region �ؽ� �Լ��� �����ΰ�?

int HashFunction(int input)
{
	return input % 10;
}

void Test1()
{
	HashFunction(2342352359); // -> 9;

	std::unordered_map<string, int> umap;

	umap.insert({ "�ٳ���",5 });
	umap.insert({ "���",3 });

	cout << "���� 1" << endl;
	cout << "�ٳ����� ���� : " << umap["�ٳ���"] << endl;

	cout << "���� 2" << endl;
	cout << "���ξ����� �����ϳ���?" <<  endl;

	auto it = umap.find("���ξ���");
	if (it != umap.end())
	{
		cout << "ã�ҽ��ϴ�." << endl;
	}
	else
	{
		cout << "ã�����߽��ϴ�." << endl;
	}
	cout << endl;
}
#pragma endregion

#pragma region map�� unordered_map ��

// �������� ���� �������� unordered_map�� ����.

void MapTimeTest()
{
	std::map<string, int> map;

	map.insert({ "A",1 });
	map.insert({ "B",1 });
	map.insert({ "C",1 });
	map.insert({ "D",1 });
	map.insert({ "E",1 });

	for (int i = 0; i < 100000; i++)
	{
		map.find("A");
	}
}

void UMapTimeTest()
{
	std::map<string, int> umap;

	umap.insert({ "A",1 });
	umap.insert({ "B",1 });
	umap.insert({ "C",1 });
	umap.insert({ "D",1 });
	umap.insert({ "E",1 });

	for (int i = 0; i < 100000; i++)
	{
		umap.find("A");
	}
}

void Test2()
{
	cout << "ù��° �� - ������ �Է½ð� ��" << endl;

	ConsoleUtil::TimeCheck(MapTimeTest);
	ConsoleUtil::TimeCheck(UMapTimeTest);

	cout << "map ���� : �������� �ڵ� ������ �߻��Ѵ�." << endl;
	cout << "�����̵� �����͸� �ʿ��� �� map�� �����ϴ�" << endl;
	cout << "�� �̿ܿ� �����̳ʾȿ� ������ �����͸� ã�� �����ϰ� �ʹ�." << endl;

	cout << "������ " << endl;
	ConsoleUtil::TimeCheck(MapTimeTest);
	ConsoleUtil::TimeCheck(UMapTimeTest);
}



#pragma endregion

int main()
{
	//Test1();
	Test2();
}