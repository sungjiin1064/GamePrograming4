#pragma once


template<typename T>
class MyVector
{
private:
	int size;
	int capacity;
	T* vec;

public:
	MyVector() = default;
	MyVector(int startSize)
	{
		vec = new T[startSize];
		size = 0;
		capacity = startSize;
	}

	~MyVector()
	{
		delete[] vec;
	}

	T& operator[](int idx)
	{
		return vec[idx];
	}
	void resize(int nsize)
	{
		if (size < nsize)
		{
			size = size;
		}
		else
		{
			size = nsize;
		}

		capacity = nsize;

		T* arr = new T[nsize];

		for (int i = 0; i < size; i++)
		{
			arr[i] = vec[i];
		}
		delete[] vec;
		vec = arr;
		//delete[] vec; //¾²¸é¾ÈµÊ

	}
	void push_back(const T& element)
	{
		if (capacity <= size)
		{
			capacity = capacity * 2;
			resize(capacity);
		}

		vec[size] = element;
		size++;
	}
	void pop_back()
	{
		size = size > 0 ? size - 1 : 0;

	}

	int Size()	{ return size; }

};

void test1()
{
	while (true)
	{
		MyVector<int>* myvec = new MyVector<int>[10];
		delete myvec;
	}
}

#include <iostream>
using namespace std;

void test2()
{
	MyVector<int> vec(5);
	

	for (int i = 0; i < 5; i++)
	{
		vec.push_back(i + 1);

		cout << vec[i] << " ";
	}

	vec.push_back(6);
	cout << endl;

	for (int i = 0; i < vec.Size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
	MyVector<double> vec2(5);

	for (int i = 0; i < vec.Size(); i++)
	{
		vec2.push_back(i + 0.1);

		cout << vec2[i] << " ";
	}

}