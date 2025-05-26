#pragma once

#include <iostream>
#include <chrono>
#include <vector>
#include <list>

using namespace std;

void TimeCheckTest()
{
	cout << "Ư�� ����� �󸶳� �ð��� �ɸ����� �����ϴ� vector�ڵ�" << endl;
	auto Start = std::chrono::high_resolution_clock::now();

	std::vector<int> nums;
	for(int i = 0; i < 1000000; i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < 1000; i++)
	{
		auto it = nums.begin() + 500;
		//auto it = std::next(nums.begin() + 500);
		nums.erase(it);
	}
	
	//nums.insert();
	

	auto End = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> duration = End - Start;

	cout << duration.count() << "ms" << endl;

}

void TimeCheckTest2()
{
	cout << "Ư�� ����� �󸶳� �ð��� �ɸ����� �����ϴ� list�ڵ�" << endl;
	auto Start = std::chrono::high_resolution_clock::now();

	std::list<int> nums;
	for (int i = 0; i < 1000000; i++)
	{
		nums.push_back(i);
	}


	for (int i = 0; i < 1000; i++)
	{
		auto it = std::next(nums.begin(), 500);
		//auto it = nums.begin() + 500; // + �� �� �� ����
		nums.erase(it);
	}




	auto End = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> duration = End - Start;

	cout << duration.count() << "ms" << endl;

}

