
/*
* �ڷ� ����(Data Structure)
* 
* Data      : ���ӿ� �����ϴ� ������ ��ǻ�Ͱ� �ؼ��� �� �ֵ��� �ۼ��� ��
* Structure : ����, ���� - ���꼺, ������
* 
* �����͸� �����ؾ� �ϴ� ����?
* STL(Standard Template Library)
* ǥ��      : �ſ��� �� �ִ�. ���������� ���� ����Ѵ�.
* ���ø�     : �Ϲ�ȭ ���α׷����� �����ϱ� ���� ����
* ���̺귯�� : ������� �Լ�, Ŭ����
* 
* STL�� ����
* 
* �����̳� : Ư���� ������ ���� ��Ƴ��� ��ü - �迭(Array),����(Vector),
* �˰��� : �����̳� �ȿ� �ִ� �����͸� ����ϴ� �Լ� ���̺귯��* 
* �ݺ��� : �˰��� �ڵ带 �����ϰ� ����ϱ� ���� ����
*/

#include <iostream>
#include <vector>  // �ڷ� ������ ����� �� �����ǥ������ ���
#include <algorithm>

#include "Template.h"
#include "Sample.h"
using namespace std;

int main()
{
	
	vector<int> nums = { 1,5,3,9,4,7 };

	cout << "������ ���1" << endl;

	for (auto& num : nums)
	{
		cout << num<< " ";
	}

	cout << endl;

	sort(nums.begin(), nums.end()); // �����͸� �����Ѵ�.

	cout << "������ ���2" << endl;

	for (auto& num : nums) 
	{
		cout << num << " ";
	}

	cout << endl;

	cout << "���ø� ����" << endl;

	int num = Add<int>(2, 5);
	cout << num << endl;

	int num1 = Add(1, 4);
	double num2 = Add(1.5, 4.2);
	char num3 = Add('b', 'a');
	
	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;

	cout << "���ϸ�" << endl;

	Example();
}

