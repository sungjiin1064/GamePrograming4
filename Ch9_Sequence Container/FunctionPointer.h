#pragma once

#include <iostream>

using namespace std;

void Add()
{
	cout << "���ϱ� ����" << endl;
	cout << 1 + 2 << endl;
}

void Minus()
{
	cout << "���� ����" << endl;
	cout << 1 - 2 << endl;
}

void Calculate(void (*Func)())
{
	Func();
}


void Add2(int a, int b)
{
	cout << "���ϱ� ����" << endl;
	cout << a + b << endl;
}

void Minus2(int a, int b)
{
	cout << "���� ����" << endl;
	cout << a - b << endl;
}

void Calculate2(void (*Func)(int a, int b), int a,int b)
{
	Func(a,b);
}

void Multiply(int a, int b)
{
	cout << "���ϱ� ����" << endl;
	cout << a * b << endl;
}

void Test()
{
	//Calculate(Add);
	//Calculate(Minus);
	//Calculate2(Add2, 10, 5);
	//Calculate2(Minus2, 10, 5);
	Calculate2(Multiply, 5, 5);

}