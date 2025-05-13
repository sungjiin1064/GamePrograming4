
#include <iostream>
#include <vector>  // 
#include <algorithm>

#include "Template.h"
#include "Sample.h"
using namespace std;

int main()
{
	
	vector<int> nums = { 1,5,3 };

	cout << "데이터 출력1" << endl;

	for (auto& num : nums)
	{
		cout << num<< " ";
	}

	cout << endl;

	sort(nums.begin(), nums.end()); // 데이터를 정렬한다.

	cout << "데이터 출력2" << endl;

	for (auto& num : nums) 
	{
		cout << num << " ";
	}

	cout << endl;

	cout << "뎀플릿 예제" << endl;

	int num = Add<int>(2, 5);
	cout << num << endl;

	int num1 = Add(1, 4);
	double num2 = Add(1.5, 4.2);
	char num3 = Add('b', 'a');
	
	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;

	cout << "포켓몬" << endl;

	Example();
}