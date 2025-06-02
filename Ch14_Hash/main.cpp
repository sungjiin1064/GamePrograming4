
#include <iostream>
#include <map>
#include <unordered_map>
#include "ConsoleUtility.h"

using namespace std;

#pragma region
#pragma endregion

#pragma region 해쉬 함수가 무엇인가?

int HashFunction(int input)
{
	return input % 10;
}

void Test1()
{
	HashFunction(2342352359); // -> 9;

	std::unordered_map<string, int> umap;

	umap.insert({ "바나나",5 });
	umap.insert({ "사과",3 });

	cout << "예제 1" << endl;
	cout << "바나나의 갯수 : " << umap["바나나"] << endl;

	cout << "예제 2" << endl;
	cout << "파인애플이 존재하나요?" <<  endl;

	auto it = umap.find("파인애플");
	if (it != umap.end())
	{
		cout << "찾았습니다." << endl;
	}
	else
	{
		cout << "찾지못했습니다." << endl;
	}
	cout << endl;
}
#pragma endregion

#pragma region map과 unordered_map 비교

// 데이터의 수가 많을수록 unordered_map이 좋다.

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
	cout << "첫번째 비교 - 데이터 입력시간 비교" << endl;

	ConsoleUtil::TimeCheck(MapTimeTest);
	ConsoleUtil::TimeCheck(UMapTimeTest);

	cout << "map 장점 : 데이터의 자동 정렬이 발생한다." << endl;
	cout << "정렬이된 데이터를 필요할 때 map이 유용하다" << endl;
	cout << "그 이외에 컨테이너안에 빠르게 데이터를 찾고 변경하고 싶다." << endl;

	cout << "데이터 " << endl;
	ConsoleUtil::TimeCheck(MapTimeTest);
	ConsoleUtil::TimeCheck(UMapTimeTest);
}



#pragma endregion

int main()
{
	//Test1();
	Test2();
}