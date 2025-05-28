
#include "ConsoleUtility.h"
#include <vector>
#include <list>
#include <deque>

#include <set>
#include <map>
#include <algorithm> 

using namespace std;

/*         | Vector           |          List         |          Deque
*  push    |   1              |           3           |            2          �Է�
*  insert  |   2              |           1           |            3          �߰��� �ֱ�
*  front   |   3              |           2           |            1          �� �տ� �߰�
*  access  |   1              |           3           |            2          
* 
*  Case1. ��Ȳ �ο�. �������� �Է��� (����) �߻��ϰ�, �߰� ������ �Է��� (������), �տ� ������ (������), ���� ������ (����) ���.
*/

//#pragma region
//#pragma endregion

#pragma region (1)�ܰ�. ���� �����̳� ������ �Է� �ð� ��
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
	cout << "������ �Է� �ð� ��" << endl;
	cout << "vector�� �ð� : "; 
	ConsoleUtil::TimeCheck(DataPushByVector);
	cout << "list�� �ð�   : ";
	ConsoleUtil::TimeCheck(DataPushByList);
	cout << "deque�� �ð�  : ";
	ConsoleUtil::TimeCheck(DataPushByDeque);

	cout << "��� : �ܼ� �����͸� �Է��� �� vector ���� ������" << endl;
	cout << endl;
}

#pragma endregion

#pragma region (2)�ܰ�. ���� �����̳� �߰� ������ �Է� �ð� ��

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
	cout << "�߰� ������ �Է� �ð� ��" << endl;
	cout << "vector�� �ð� : ";
	ConsoleUtil::TimeCheck(InsertDataByVector);
	cout << "list�� �ð�   : ";
	ConsoleUtil::TimeCheck(InsertDataByList);
	cout << "deque�� �ð�  : ";
	ConsoleUtil::TimeCheck(InsertDataByDeque);

	cout << "��� : ó���� �����͸� �Է��� �� vector ���� ������" << endl;
	cout << "��� : �߰� ����(����)�ϴ� ������ ������ �������� list�� ������ �� �ִ�." << endl;   ///
	cout << endl;
}

#pragma endregion

#pragma region (2-2)�ܰ�. ���� �����̳� �����͸� �� �տ� �߰��� �� �ɸ��� �ð� ��

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
	cout << "ù��° ��ġ�� ������ �Է� �ð� ��" << endl;
	cout << "vector�� �ð� : ";
	ConsoleUtil::TimeCheck(FrontPushByVector);
	cout << "list�� �ð�   : ";
	ConsoleUtil::TimeCheck(FrontPushByList);
	cout << "deque�� �ð�  : ";
	ConsoleUtil::TimeCheck(FrontPushByDeque);

	cout << "��� : ù��° ���Ҹ� �ִ� ��� vector�� ������ ������ �ذ��� �� �ִ�." << endl;
	
	cout << endl;
}

#pragma endregion

#pragma region (2_3)�ܰ�. ���� �����̳ʿ��� ���� ���� ���ٿ� �ɸ��� �ð� ��

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
	cout << "���� ��ġ�� ������ �Է� �ð� ��" << endl;
	cout << "vector�� �ð� : ";
	ConsoleUtil::TimeCheck(RandomAccesByVector);
	cout << "list�� �ð�   : ";
	ConsoleUtil::TimeCheck(RandomAccesByList);
	cout << "deque�� �ð�  : ";
	ConsoleUtil::TimeCheck(RandomAccesByDeque);

	cout << "��� : �迭 ������ �ڷᱸ��(vector,deque) �ٷ� ������ �� �ִ�." << endl;
	cout << "list�� ��쿡�� ���۰� �Ÿ��� �ָ� �ּ��� �ð��� ���� �ɸ���." << endl;
	cout << endl;
}

#pragma endregion

#pragma region (3)�ܰ�. ���� �����̳ʿ� ���� �����̳�



bool Find(int value)
{
	int nums[10] = { 0,1,2,3,4,5,6,7,8,9 };

	for (int i = 0; i < 10; i++)
	{
		if (nums[i] == value)
		{
			cout << nums[i] << " ���� ã�ҽ��ϴ�." << endl;
			return true;
		}
	}

	cout << "���� ã�� ���߽��ϴ�." << endl;
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
	cout << "�������� �˻� �ð� ��" << endl;
	cout << "vector�� �ð� : ";
	ConsoleUtil::TimeCheck(FindByVector);
	cout << "list�� �ð�   : ";
	ConsoleUtil::TimeCheck(FindByList);
	cout << "deque�� �ð�  : ";
	ConsoleUtil::TimeCheck(FindByDeque);
	cout << "set�� �ð�    : ";
	ConsoleUtil::TimeCheck(FindByDeque);

	cout << "��� : " << endl;
	
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


