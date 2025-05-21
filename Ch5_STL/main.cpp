/*
* iterator 을 사용해서 자료구조의 element를 출력할 수 있다.
* begin() - 컨테이너의 첫번째 요소를 가리킴, cbegin(), rbegin(), crbegin()
* end()   - 컨테이너의 마지막 요소를 가리킴 , cend()  , rend()  , crend()
* cbegin() - 컨테이너의 첫번째 요소를 가리키지만 const속성이 적용
* cend()   - 컨테이너의 마지막 요소를 가리키지만 const속성이 적용
* 역방향
* rbegin() - 컨테이너의 마지막 요소부터 시작
* rend()   - 컨테이너의 첫번째 요소부터 시작
* crbegin()
* crend()
*/

#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include "algo.h"

using namespace std;



void test1()
{
	std::vector<int> nums = { 1,2,3,4,5 };
	std::list<int> intlist = { 2,4,6,8,10 };
	std::vector<int>::iterator it = nums.begin();
	//auto it = nums.begin();

	cout << "iterator 자료구조" << endl;
	while (it != nums.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;


	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;

	std::list<int>::iterator it2 = intlist.begin();

	cout << "list 자료구조" << endl;
	while (it2 != intlist.end())
	{
		cout << *it2 << " ";
		it2++;
	}


}

// 역순
void test2()
{
	cout << "\n=======================" << endl;
	std::vector<int> vec = { 1,2,3,4,5,6,7,8,9 };
	//std::vector<int>::reverse_iterator it = vec.rbegin();
	auto it = vec.rbegin(); // 위와 같다

	while (it != vec.rend())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	
	cout << "list 역순출력" << endl;
	std::list<int> lis = { 2,4,6,8,10 };
	//std::vector<int>::reverse_iterator it2 = lis.rbegin();
	auto it2 = lis.rbegin();
	
	while (it2 != lis.rend())
	{
		cout << *it2 << " ";
		it2++;
	}
	cout << endl;
}

void test3()
{
	cout << "\n=======================" << endl;

	auto x = 5;

	std::vector<int> nums = { 1,2,3,4,5 };
	auto it = nums.begin();

	// &붙여서 원본을 바꿈 다음오토에 0을적용, & 안붙이면 복사본을 바꿔서 다음오토에 영향없음
	for (const auto& num : nums) 
	{
		cout << num << " ";
	}
	cout << endl;

	for (auto& i : nums)
	{
		i = 0;
		cout << i << " ";
	}
	cout << endl;

	for (auto num : nums)
	{		
		cout << num << " ";
	}
}

void test4()
{
	cout << "\n=======================" << endl;
	std::vector<int> vec = { 1,2,3,4,5,6,7,8,9 };

	//std::vector<int>::const_iterator it = vec.begin();

	auto it = vec.cbegin();

	while (it != vec.cend())
	{
		//*it = 0; // begin() 일떄 사용 
		cout << *it << " ";
		it++;
	}
	cout << endl;	
}

void test5()
{
	cout << "\n=======================" << endl;
	std::vector<int> vec  { 1,2,3,4,5,6,7,8,9,10 };

	auto start = vec.begin() + 2;
	auto finish = vec.end() - 3;

	while (start != finish)
	{
		cout << *start << " ";
		start++;
	}
}

int main()
{
	//test1();
	//test2();
	test3();
	//test4();
	//test5();
	//find_test();
}