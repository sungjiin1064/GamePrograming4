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
	ROCK = 1,
	SCISSORS, 
	PAPER // ��,��,��
};

class RSPGame
{
	void (*Action)();
	int userScore;
	int computerScore;
	RSP_TYPE computerType;
	RSP_TYPE userType;

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
			cout << "�̰��." << endl;
			userScore++;
			ConsoleUtil::GotoXY(45, 0);
			cout << "�� ��  : " << userScore << " ��" << endl;
		}
		else
		{
			cout << "����." << endl;
			computerScore++;
			ConsoleUtil::GotoXY(45, 2);
			cout << "��ǻ�� : " << computerScore << " ��" << endl;
		}
	}

public:
	RSPGame() : userScore(0), computerScore(0) {};

	void ShowScore()
	{
		ConsoleUtil::GotoXY(45, 0);
		cout << "�� ��  : " << userScore << " ��" << endl;
		ConsoleUtil::GotoXY(45, 2);
		cout << "��ǻ�� : " << computerScore << " ��" << endl;
	}

	void StartGame()
	{
		system("cls");
		ShowScore();

		while (true)
		{
			ConsoleUtil::GotoXY(0, 0);
			cout << "1 : ����, 2 : ����, 3 : ��" << endl;
			ConsoleUtil::GotoXY(0, 1);
			cout << "�������ּ���." << endl;
			ConsoleUtil::GotoXY(0, 2);
			int input = 0;
			cin >> input;

			if (input < 1 || input >3)
			{
				cout << "�߸��� �Է��Դϴ�." << endl;				
				continue;
			}

			userType = static_cast<RSP_TYPE>(input);
			

			int select = ConsoleUtil::GetRandomInt(3);
			computerType = static_cast<RSP_TYPE>(select);

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
			cout << "������" << GetRSPName(userType) << " �� �½��ϴ�" << endl;
			cout << "��ǻ�ʹ� ";
			Action();
			Result();

			if (userScore >= 3 || computerScore >= 3)
			{

				break;
			}

		}
		if (userScore >= 3)
		{
			cout << "��ǻ�͸� �̰��." << endl;

		}
		else if (computerScore >= 3)
		{
			cout << "��ǻ�Ͱ� �̰��." << endl;

		}
	}

};

string GetRSPName(RSP_TYPE type)
{
	switch (type)
	{
	case ROCK: return "����";
	case SCISSORS: return "����";
	case PAPER: return "��";
	default: return "�� �� ����";
	}
}

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
	rsp.StartGame();



}
