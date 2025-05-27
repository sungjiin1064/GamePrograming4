#pragma once

#include "ConsoleUtility.h"
#include <iostream>

#pragma region ��ȭ1. �Լ� �����Ϳ� �Ϲ�ȭ ���α��ع�Generic Programing ����

using namespace std;

template<typename T>
void Plus(T a, T b)
{
	cout << "���ϱ� ��� : " << a + b << endl;
}

template<typename T>
void Minus(T a, T b)
{
	cout << "���� ��� : " << a - b << endl;
}

template<typename T>
void Multiply(T a, T b)
{
	cout << "���ϱ� ��� : " << a * b << endl;
}

template<typename T>
void Divide(T a, T b)
{
	if (b == 0)
	{
		return;
	}
	cout << "������ ��� : " << a / b << endl;
}

template<typename T>
void Calculate(void (*Func)(T a, T b), T outA, T outB)
{
	Func(outA, outB);
}

#pragma endregion

#pragma region ��ȭ2. �������� Ŭ������ �Լ������� Ȱ��

enum ActorAction
{
	MOVE, TALK
};

class Actor
{
private:
	static void Move()
	{
		cout << "�����Դϴ�." << endl;

	}

	static void Talk()
	{
		cout << "��ȭ�մϴ�." << endl;
	}

public:
	Actor() = default;

	void (*Action)();

	/*void ActionMove()
	{
		Action = Move;
	}*/

	/*void ActionTalk()
	{
		Action = Talk;
	}*/

	void Think()
	{
		int select = ConsoleUtil::GetRandomInt(2); // 0���Ͱ� �ƴ� 1���� �����⶧���� -1

		ActorAction aaction = static_cast<ActorAction>(select - 1);

		/*switch(select -1)
		{
		case 0: Action = Move;
			break;
		case 1: Action = Talk;
			break;
		default:
			cout << "�߸��� �Է��� �޾ƿԽ��ϴ�." << endl;
			return;
		}*/
		switch (aaction)
		{
		case MOVE: Action = Move;
			break;
		case TALK: Action = Talk;
			break;
		default:
			cout << "�߸��� �Է��� �޾ƿԽ��ϴ�." << endl;
			return;
		}
	}

};

#pragma endregion

#pragma region ����,����,�� ���� �����

enum RSP_TYPE
{
	ROCK, SCISSORS, PAPER // ��,��,��
};

class RSPGame
{
	RSPGame() : userScore(0), computerScore(0);
	void (*Action)();

	static void Rock()
	{
		cout << "������ �½��ϴ�." << endl;
	}

	static void Scissors()
	{
		cout << "������ �½��ϴ�." << endl;
	}

	static void Paper()
	{
		cout << "���� �½��ϴ�." << endl;
	}

	RSP_TYPE computerType;
	RSP_TYPE userType;

	int userScore;
	int computerScore;
	//string name[] = { "����", "����", "��" };

	void Result()
	{
		if (userType == computerType)
		{
			cout << "����" << endl;
		}
		else if (userType == ROCK && computerType == SCISSORS ||
			userType == SCISSORS && computerType == PAPER ||
			userType == PAPER && computerType == ROCK)
		{
			cout<< "�̰��."<< endl;
		}
		else
		{
			cout << "����." << endl;
		}
	
	}

public:	
	void StartGame()
	{
		
		cout << "0 : ����, 1 : ����, 2 : ��" << endl;
		cout << "�������ּ���." << endl;
		int input = 0;
		cin >> input;
		userType = static_cast<RSP_TYPE>(input);
		

		int select = ConsoleUtil::GetRandomInt(3);
		computerType = static_cast<RSP_TYPE>(select - 1);

		switch (computerType)
		{
		case ROCK: Action = Rock;
			break;
		case SCISSORS: Action = Scissors;
			break;
		case PAPER: Action = Paper;
			break;
		default:
			cout << "�߸��� �Է��� �޾ƿԽ��ϴ�." << endl;
			return;
		}
		cout << "������" << name[0] << " �� �½��ϴ�" << endl;
		cout << "��ǻ�ʹ� ";
		Action();
		Result();
	}

};

#pragma endregion
void FPTest()
{
	Calculate(Plus, 5, 6);
	Calculate(Plus, 5.5, 6.4);
	Calculate(Minus, 5, 15);
	Calculate(Minus, 6.6, 5.5);
	Calculate(Multiply, 6, 5);
	Calculate(Multiply, 6.6, 5.5);
	Calculate(Divide, 6, 5);
	Calculate(Divide, 6.6, 5.5);
}

void FPTest2()
{
	Actor actor;
	//actor.ActionTalk();
	actor.Think();
	actor.Action();
}

void FPTest3()
{
	RSPGame rsp;
	while (true)
	{
		rsp.StartGame();		
	}
}