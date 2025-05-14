
#define Max(a,b) ( (a>b) ? a:b)
#define Square(a) (a*a)

#include <iostream>
#include <array>

using namespace std;



template<typename T1>
T1 MaxFunc(T1 a, T1 b)
{
	return (a > b) ? a : b;
}

//double MaxFunc(double a, double b)
//{
//	return (a > b) ? a : b;
//}

#pragma region 예제 코드들

#pragma endregion


template<typename T1, typename T2>
void Func(T1 a, T2 b)
{
	cout <<"NO " << a << " " <<  b << endl;
}

template<int N>
void Func2()
{
	cout << N << endl;
}

template<int N, typename T>
void Func3()
{
	for (int i = 0; i < N; i++)
	{
		cout << typeid(T).name << endl;
	}
}

template<typename T>
T Min(T a, T b)
{
	return (a < b) ? a : b; // 작은수를 반환하라
}

template<typename T>
T Multiply(T a, T b)
{
	return a * b;
}

struct Person
{
	int age;
	string name;

	bool operator<(const Person& other)
	{
		return this->age < other.age;
	}
};

template<int N>
class People
{
private:
	int size = N;
	Person HumanInCity[N];

public:
	Person& operator[](int index)
	{
		return HumanInCity[index];
	}

	void at(int index)
	{
		cout << "나이 : " << HumanInCity[index].age << ", 이름 : " << HumanInCity[index].name << endl;
	}
};

template<int N, typename T>
class Array
{
private:
	int size = N;
	T value[N];

public:
	T& operator[](int index)
	{
		return HumanInCity[index];
	}

	T& at(int index)
	{
		retuen value[index];
		//cout << "나이 : " << HumanInCity[index].age << ", 이름 : " << HumanInCity[index].name << endl;
	}
};

void Ex1()
{
	int result1 = Max(5, 1);
	double result2 = Max(1.1, 2.2);
	int result3 = 100 / Square(5);

	std::cout << result1 << std::endl;
	std::cout << result2 << std::endl;
	std::cout << result3 << std::endl;

	cout << MaxFunc<double>(1.1, 2.1) << endl;
	cout << MaxFunc(0.1, 0.2) << endl;

	// 타입 추론
	cout << MaxFunc(1.2, 8.4) << endl;

	Func<int, string>(1, "피카츄");

	Func2<4>();

	cout << Min(1, 5);
}

int main()
{
	Ex1();

	Person p1{ 10,"A" };
	Person p2{ 20,"B" };

	Person p3 = Min<Person>(p1, p2);

	cout << p3.name << "나이가 더 어리다" << endl;

	People<5> busan;
	busan[0] = { 15,"이순신" };
	busan.at(0);

	Array<5, Person> seoul;
	seoul[0] = { 13, "장보고" };
	seoul.at(0);
	cout << seoul[0].name << endl;

}