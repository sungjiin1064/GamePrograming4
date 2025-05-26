#pragma once

#include <iostream>
#include <chrono>
#include <vector>
#include <list>

using namespace std;

void TimeCheckTest()
{
	cout << "특정 기능이 얼마나 시간이 걸리는지 측정하는 vector코드" << endl;
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
	cout << "특정 기능이 얼마나 시간이 걸리는지 측정하는 list코드" << endl;
	auto Start = std::chrono::high_resolution_clock::now();

	std::list<int> nums;
	for (int i = 0; i < 1000000; i++)
	{
		nums.push_back(i);
	}


	for (int i = 0; i < 1000; i++)
	{
		auto it = std::next(nums.begin(), 500);
		//auto it = nums.begin() + 500; // + 를 쓸 수 없음
		nums.erase(it);
	}




	auto End = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> duration = End - Start;

	cout << duration.count() << "ms" << endl;

}

