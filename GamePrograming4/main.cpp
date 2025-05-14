
/*
* 자료 구조(Data Structure)
* 
* Data      : 게임에 등장하는 정보를 컴퓨터가 해석할 수 있도록 작성한 것
* Structure : 구조, 설계 - 생산성, 안전성
* 
* 데이터를 설계해야 하는 이유?
* STL(Standard Template Library)
* 표준      : 신용할 수 있다. 대중적으로 많이 사용한다.
* 템플릿     : 일반화 프로그래밍을 구현하기 위한 문법
* 라이브러리 : 만들어진 함수, 클래스
* 
* STL의 종류
* 
* 컨데이너 : 특정한 목적에 따라 모아놓은 객체 - 배열(Array),백터(Vector),
* 알고리즘 : 컨테이너 안에 있는 데이터를 사용하는 함수 라이브러리* 
* 반복자 : 알고리즘 코드를 용이하게 사용하기 위한 문법
*/

#include <iostream>
#include <vector>  // 자료 구조를 사용할 때 가장대표적으로 사용
#include <algorithm>

#include "Template.h"
#include "Sample.h"
using namespace std;

int main()
{
	
	vector<int> nums = { 1,5,3,9,4,7 };

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

