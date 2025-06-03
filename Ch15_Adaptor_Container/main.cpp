
#include <iostream>

using namespace std;

#pragma region
#pragma endregion

#pragma region 스택
#include <stack>

void Test1()
{	
	cout << "스택 사용 예시" << endl;

	std::stack<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);
	}

	cout << "nums의 데이터 출력" << endl;

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

#pragma region 큐
#include <queue>

void Test2()
{
	cout << endl;
	cout << endl;
	cout << "큐 사용 예시" << endl;

	std::queue<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);
	}

	cout << "nums의 데이터 출력" << endl;

	while (!nums.empty())
	{
		cout << nums.front() << " ";
		nums.pop();
	}
		
}

#pragma endregion

#pragma region 우선순위 큐

void Test3()
{
	cout << endl;
	cout << endl;
	cout << "우선 순위 큐 사용 예시" << endl;

	std::priority_queue<int> nums;

	nums.push(0);
	nums.push(3);
	nums.push(7);
	nums.push(5);
	nums.push(2);

	cout << "nums의 데이터 출력" << endl;

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
	cout << "직접만큐 사용 예시" << endl;

	MyQueue<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);
	}

	cout << "nums의 데이터 출력" << endl;

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