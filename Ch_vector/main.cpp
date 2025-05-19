
#include <iostream>
#include <vector>

using namespace std;


template<typename T, int N>  
void MakeArray(T*& ptr, T value)
{
	delete[] ptr;
	ptr = new T[N];

	for (int i = 0; i < N; i++)
	{
		*(ptr + i) = value; // ptr[i] = value로 써도되는데  값은바꿀수없다.
		cout << *(ptr + i) << " ";
	}

	cout << endl;
}

class Monster
{
private:	
	int _num;
	string _name;

public:
	Monster() = default;
	~Monster() = default;
	Monster(int num, string name) : _num(num),_name(name){}

	int get_num() const { return _num; }
	string get_name() const { return _name; }

	friend ostream& operator<<(ostream& os, const Monster& obj)
	{
		os << obj._num << "_" << obj._name << " ";
		return os;
	}
};

template<typename T>
void Show(std::vector<T>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

int main()
{
	int* aPtr = new int[10];
	double* bPtr = new double[10];
	string* cPtr = new string[10];
	Monster* dPtr = new Monster[10];

	Monster sample(0, "고블린");

	MakeArray<int,10>(aPtr,0);
	MakeArray<double,10>(bPtr,0.1);
	MakeArray<string,10>(cPtr,"슬라임");
	MakeArray<Monster,10>(dPtr, sample);
	cout << endl;
	
	cout << "백터사용 예제" << endl;

	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);

	Show<int>(nums);

	/*for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}*/


	std::vector<Monster> monsterDatabase;
	monsterDatabase.emplace_back(1, "고블린");
	monsterDatabase.emplace_back(2, "슬라임");
	monsterDatabase.emplace_back(3, "골렘");
	//monsterDatabase.pop_back(); // 앞에걸 지운다.한번더쓰면 1개더 지운다
	Show<Monster>(monsterDatabase);

	if (!monsterDatabase.empty())
	{
		cout << "데이터가 있습니다." << endl;
	}

}





//delete[] aPtr;
//
//aPtr = new int[20];
//
//for (int i = 0; i < 20; i++)
//{
//	*(aPtr + i) = 0;
//	cout << *(aPtr + i) << " ";
//}

//delete[] aPtr;
//ptr = new T[N];

