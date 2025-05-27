
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "TimeCheck.h"
#include "FunctionPointer.h"
#include "ConsoleUtility.h"

using namespace std;

struct Node
{
	int value;
	Node* nextPtr;
	Node* prevPtr;
};

void Test1_Vector()
{
	std::vector<int> nums;
	
	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}
	cout << nums[500] << endl;
}

void Test2_List()
{
	std::list<int> nums;

	nums.push_back(3);
	nums.push_front(2);
	nums.push_back(1);

	for (const auto& num : nums)
	{
		cout << num<<" " ;
	}
}

void VectorExample()
{
	std::vector<int> nums;
	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}	

	cout << "임의의 데이터 vector 접근시간" << endl;
	cout << nums[900] << endl;
	
}

void ListExample()
{
	std::list<int> nums;
	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}

	cout << "임의의 데이터 list 접근시간" << endl;

	auto it = std::next(nums.begin(), 900);
	//cout << *it << endl;

}

int main()
{
	//Test1_Vector();
	//Test2_List();

	//TimeCheckTest();
	//TimeCheckTest2();

	//Test();

	ConsoleUtil::TimeCheck(VectorExample);
	ConsoleUtil::TimeCheck(ListExample);
	
}

void Num()
{
	std::vector<int> nums;
	for (int i = 0; i < 100;i++)
	{
		nums.push_back(i);
	}
	cout << nums[10] << endl;
}