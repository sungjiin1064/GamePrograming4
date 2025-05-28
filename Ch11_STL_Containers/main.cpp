
#include "ConsoleUtility.h"
#include <vector>
#include <list>
#include <deque>

#include <set>
#include <map>
#include <algorithm> 

using namespace std;

/*         | Vector           |          List         |          Deque
*  push    |   1              |           3           |            2          입력
*  insert  |   2              |           1           |            3          중간에 넣기
*  front   |   3              |           2           |            1          맨 앞에 추가
*  access  |   1              |           3           |            2          
* 
*  Case1. 상황 부여. 데이터의 입력이 (많이) 발생하고, 중간 데이터 입력이 (적으며), 앞에 데이터 (적으며), 랜덤 접근이 (많은) 경우.
*/

//#pragma region
//#pragma endregion

#pragma region (1)단계. 순차 컨데이너 데이터 입력 시간 비교
void DataPushByVector()
{
	std::vector<int> nums;

	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}
}

void DataPushByList()
{
	std::list<int> nums;

	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}
}

void DataPushByDeque()
{
	std::deque<int> nums;

	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}
}

void Test1()
{
	cout << "데이터 입력 시간 비교" << endl;
	cout << "vector의 시간 : "; 
	ConsoleUtil::TimeCheck(DataPushByVector);
	cout << "list의 시간   : ";
	ConsoleUtil::TimeCheck(DataPushByList);
	cout << "deque의 시간  : ";
	ConsoleUtil::TimeCheck(DataPushByDeque);

	cout << "결과 : 단순 데이터를 입력할 때 vector 가장 빠르다" << endl;
	cout << endl;
}

#pragma endregion

#pragma region (2)단계. 순차 컨테이너 중간 데이터 입력 시간 비교

void InsertDataByVector()
{
	std::vector<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < 1000; i++)
	{
		auto it = nums.begin() + 5;
		nums.insert(it, 1);
	}
}

void InsertDataByList()
{
	std::list<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < 1000; i++)
	{
		auto it = next(nums.begin(), 5);
		nums.insert(it, 1);
	}
}

void InsertDataByDeque()
{
	std::deque<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < 1000; i++)
	{
		auto it = nums.begin() + 5;
		nums.insert(it, 1);
	}
}

void Test2()
{
	cout << "중간 데이터 입력 시간 비교" << endl;
	cout << "vector의 시간 : ";
	ConsoleUtil::TimeCheck(InsertDataByVector);
	cout << "list의 시간   : ";
	ConsoleUtil::TimeCheck(InsertDataByList);
	cout << "deque의 시간  : ";
	ConsoleUtil::TimeCheck(InsertDataByDeque);

	cout << "결과 : 처음에 데이터를 입력할 때 vector 가장 빠르다" << endl;
	cout << "결과 : 중간 삽입(삭제)하는 과정이 많으면 많을수록 list가 빨라질 수 있다." << endl;   ///
	cout << endl;
}

#pragma endregion

#pragma region (2-2)단계. 순차 컨데이너 데이터를 맨 앞에 추가할 때 걸리는 시간 비교

void FrontPushByVector()
{
	std::vector<int> nums;
		
	for (int i = 0; i < 1000; i++)
	{
		auto it = nums.begin();
		nums.insert(it, i);
	}
}

void FrontPushByList()
{
	std::list<int> nums;

	for (int i = 0; i < 1000; i++)
	{		
		nums.push_front(i);
	}
}

void FrontPushByDeque()
{
	std::deque<int> nums;

	for (int i = 0; i < 1000; i++)
	{
		nums.push_front(i);
	}
}

void Test2_2()
{
	cout << "첫번째 위치에 데이터 입력 시간 비교" << endl;
	cout << "vector의 시간 : ";
	ConsoleUtil::TimeCheck(FrontPushByVector);
	cout << "list의 시간   : ";
	ConsoleUtil::TimeCheck(FrontPushByList);
	cout << "deque의 시간  : ";
	ConsoleUtil::TimeCheck(FrontPushByDeque);

	cout << "결과 : 첫번째 원소를 넣는 경우 vector의 장점과 단점음 해결할 수 있다." << endl;
	
	cout << endl;
}

#pragma endregion

#pragma region (2_3)단계. 순차 컨테이너에서 랜덤 원소 접근에 걸리는 시간 비교

void RandomAccesByVector()
{
	std::vector<int> nums;

	for (int i = 0; i < 100; i++)
	{
		nums.push_back(i);
	}
	
	for (int i = 0; i < 50; i++)
	{
		nums[i] = 0;
	}

}

void RandomAccesByList()
{
	std::list<int> nums;

	for (int i = 0; i < 100; i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < 50; i++)
	{
		auto it = next(nums.begin(), i);
		*it = 0;
	}

}

void RandomAccesByDeque()
{
	std::deque<int> nums;

	for (int i = 0; i < 100; i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < 50; i++)
	{
		nums[i] = 0;
	}
}

void Test2_3()
{
	cout << "랜덤 위치에 데이터 입력 시간 비교" << endl;
	cout << "vector의 시간 : ";
	ConsoleUtil::TimeCheck(RandomAccesByVector);
	cout << "list의 시간   : ";
	ConsoleUtil::TimeCheck(RandomAccesByList);
	cout << "deque의 시간  : ";
	ConsoleUtil::TimeCheck(RandomAccesByDeque);

	cout << "결과 : 배열 형태의 자료구조(vector,deque) 바로 접근할 수 있다." << endl;
	cout << "list의 경우에는 시작과 거리가 멀면 멀수록 시간이 오래 걸린다." << endl;
	cout << endl;
}

#pragma endregion

#pragma region (3)단계. 순차 컨데이너와 연관 컨테이너



bool Find(int value)
{
	int nums[10] = { 0,1,2,3,4,5,6,7,8,9 };

	for (int i = 0; i < 10; i++)
	{
		if (nums[i] == value)
		{
			cout << nums[i] << " 값을 찾았습니다." << endl;
			return true;
		}
	}

	cout << "값을 찾지 못했습니다." << endl;
	return false;
}

void FindByVector()
{
	std::vector<int> nums;

	for (int i = 1000; i > 0; i--)
	{
		nums.push_back(i);		
	}

	for (auto num : nums)
	{
		cout << num << " ";
	}
}

void FindByList()
{
	std::list<int> nums;

	for (int i = 1000; i > 0; i--)
	{
		nums.push_back(i);
	}

	for (auto num : nums)
	{
		cout << num << " ";
	}
}

void FindByDeque()
{
	std::deque<int> nums;

	for (int i = 1000; i > 0; i--)
	{
		nums.push_back(i);
	}

	for (auto num : nums)
	{
		cout << num << " ";
	}
}

void FindBySet()
{
	std::set<int> nums;

	for (int i = 1000; i > 0; i--)
	{
		nums.insert(i);
	}

	for (auto num : nums)
	{
		cout << num << " ";
	}
}

void Test3()
{
	cout << "데이터의 검색 시간 비교" << endl;
	cout << "vector의 시간 : ";
	ConsoleUtil::TimeCheck(FindByVector);
	cout << "list의 시간   : ";
	ConsoleUtil::TimeCheck(FindByList);
	cout << "deque의 시간  : ";
	ConsoleUtil::TimeCheck(FindByDeque);
	cout << "set의 시간    : ";
	ConsoleUtil::TimeCheck(FindByDeque);

	cout << "결과 : " << endl;
	
	cout << endl;
}

#pragma endregion

int main()
{
	//Test1();
	//Test2();
	//Test2_2();
	//Test2_3();

	//cout << boolalpha;
	//cout<<Find(1)<<endl;

	Test3();

	FindByVector();
	cout << endl;
	FindByList();
	cout << endl;
	FindByDeque();
	cout << endl;
	FindBySet();
	cout << endl;
}


