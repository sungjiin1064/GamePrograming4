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

	cout << "iterator �ڷᱸ��" << endl;
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

	std::list<int>::iterator it2 = intlist.begin();
	cout << endl;

	cout << "list �ڷᱸ��" << endl;
	while (it2 != intlist.end())
	{
		cout << *it2 << " ";
		it2++;
	}
}

// ����
void test2()
{
	cout << "\n=======================" << endl;
	std::vector<int> vec = { 1,2,3,4,5,6,7,8,9 };
	//std::vector<int>::reverse_iterator it = vec.rbegin();
	auto it = vec.rbegin(); // ���� ����

	while (it != vec.rend())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	
	cout << "list �������" << endl;
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

	// &�ٿ��� ������ �ٲ� �������信 0������, & �Ⱥ��̸� ���纻�� �ٲ㼭 �������信 �������
	for (const auto& num : nums) 
	{
		cout << num << " ";
	}
	cout << endl;

	for (auto& i : nums)
	{
		i = 0;
		//cout << i << " ";
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
		//*it = 0; // begin() �ϋ� ��� 
		cout << *it << " ";
		it++;
	}
	cout << endl;	
}

void test5()
{
	cout << "\n=======================" << endl;
	std::vector<int> vec = { 1,2,3,4,5,6,7,8,9,10 };

	
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	find_test();
}