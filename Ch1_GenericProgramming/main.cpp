
#define Max(a,b) ( (a>b) ? a:b)
#define Square(a) (a*a)

#include <iostream>
#include <array>
#include <vector>

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

#pragma region ���� �ڵ��

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
	return (a < b) ? a : b; // �������� ��ȯ�϶�
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
		cout << "���� : " << HumanInCity[index].age << ", �̸� : " << HumanInCity[index].name << endl;
	}
};

struct PokeMon
{
	int number;
	string name;
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
		return value[index];
	}

	T& at(int index)
	{
		return value[index];
		//cout << "���� : " << HumanInCity[index].age << ", �̸� : " << HumanInCity[index].name << endl;
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

	// Ÿ�� �߷�
	cout << MaxFunc(1.2, 8.4) << endl;

	Func<int, string>(1, "��ī��");

	Func2<4>();

	Func3<5, int>;

	cout << Min(1, 5)<<endl;
}

int main()
{
	Ex1();

	Person p1{ 10,"A" };
	Person p2{ 20,"B" };

	Person p3 = Min<Person>(p1, p2);

	cout << p3.name << "���̰� �� ���" << endl;
	cout << endl;

	People<5> busan;
	busan[0] = { 15,"�̼���" };
	busan.at(0);
	cout << endl;

	Array<5, Person> seoul;
	seoul[0] = { 13, "�庸��" };
	seoul.at(1) = { 15,"���ָ�" };
	cout <<"���� : "<< seoul[0].age<<", �̸�  : " << seoul[0].name << endl;
	cout << seoul[1].name << endl;
	cout << seoul.at(0).name << endl;
	cout << seoul.at(1).name << endl;
	cout << endl;

	Array<10, PokeMon> MyPokemons;
	MyPokemons[0] = { 1,"�̻��ؾ�" };
	cout <<"��ȣ : "<<MyPokemons.at(0).number<<", �̸� : " << MyPokemons.at(0).name << endl;
	cout <<"��ȣ : "<<MyPokemons[0].number << ", �̸� : " << MyPokemons[0].name << endl;
	cout << endl;

	std::array<PokeMon,10> mPokemons;
	mPokemons[0] = { 1, "�̻��ؾ�"};
	cout << "��ȣ : " << mPokemons.at(0).number << ", �̸� : " << mPokemons.at(0).name << endl;
	cout << endl;

	std::vector<PokeMon> pokemon(10);
	pokemon[0] = { 1, "�̻��ؾ�" };
	pokemon[1] = { 2, "���α�" };
	cout << "��ȣ : " << pokemon.at(0).number << ", �̸� : " << pokemon.at(0).name << endl;
	cout << "��ȣ : " << pokemon[0].number << ", �̸� : " << pokemon[0].name << endl;
}