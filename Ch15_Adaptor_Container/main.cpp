
#include <iostream>

using namespace std;

#pragma region
#pragma endregion

#pragma region ����
#include <stack>

void Test1()
{	
	cout << "���� ��� ����" << endl;

	std::stack<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);
	}

	cout << "nums�� ������ ���" << endl;

	while (!nums.empty())
	{
		cout << nums.top() << " ";
		nums.pop();
	}

	//for (int i = 0; i < 10; i++)
	//{
	//	cout << nums.top() << " ";
	//	nums.pop();
	//}
}



#pragma endregion

#pragma region ť
#include <queue>

void Test2()
{
	cout << endl;
	cout << endl;
	cout << "ť ��� ����" << endl;

	std::queue<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);
	}

	cout << "nums�� ������ ���" << endl;

	while (!nums.empty())
	{
		cout << nums.front() << " ";
		nums.pop();
	}
		
}

#pragma endregion

#pragma region �켱���� ť

void Test3()
{
	cout << endl;
	cout << endl;
	cout << "�켱 ���� ť ��� ����" << endl;

	std::priority_queue<int> nums;

	nums.push(0);
	nums.push(3);
	nums.push(7);
	nums.push(5);
	nums.push(2);

	cout << "nums�� ������ ���" << endl;

	while (!nums.empty())
	{
		cout << nums.top() << " ";
		nums.pop();
	}

}

#pragma endregion

#include <vector>
#include <deque>

template <typename T>
class MyQueue
{
private:
	int _size;
	std::deque<T> data;

public:
	MyQueue() : _size(0) {}
	
	void push(T& e)
	{
		_size++;
		data.push_back(e);
	}

	T fornt()
	{
		return data[0];
	}

	void pop()
	{
		size--;
		data.pop_front();
	}

	void size()
	{
		retuen _size;
	}

	void empty()
	{
		retuen _size == 0;
	}
};

template <typename T>
class MyStack
{
private:
	int _size;
	std::vector<T> data;

public:
	MyStack() : _size(0) {}

	void push(T& e)
	{
		_size++;
		data.push_back(e);
	}

	T top()
	{
		return data[_size - 1];
	}

	void pop()
	{
		size--;
		data.pop_back();
	}

	void size()
	{
		retuen _size;
	}

	void empty()
	{
		retuen _size == 0;
	}

};

void Test4()
{
	cout << endl;
	cout << endl;
	cout << "������ť ��� ����" << endl;

	MyQueue<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);
	}

	cout << "nums�� ������ ���" << endl;

	while(!nums.empty())
	{
		cout << nums.front() << " ";
		nums.pop();
	}
}

void Test5()
{

}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
}