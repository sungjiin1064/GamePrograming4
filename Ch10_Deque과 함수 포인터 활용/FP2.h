#pragma once

#include "ConsoleUtility.h"
#include <iostream>

#pragma region 심화1. 함수 포인터에 일반화 프로그해밍Generic Programing 적용

using namespace std;

template<typename T>
void Plus(T a, T b)
{
	cout << "더하기 결과 : " << a + b << endl;
}

template<typename T>
void Minus(T a, T b)
{
	cout << "빼기 결과 : " << a - b << endl;
}

template<typename T>
void Multiply(T a, T b)
{
	cout << "곱하기 결과 : " << a * b << endl;
}

template<typename T>
void Divide(T a, T b)
{
	if (b == 0)
	{
		return;
	}
	cout << "나누기 결과 : " << a / b << endl;
}

template<typename T>
void Calculate(void (*Func)(T a, T b), T outA, T outB)
{
	Func(outA, outB);
}

#pragma endregion

#pragma region 심화2. 열거형과 클래스로 함수포인터 활용

enum ActorAction
{
	MOVE, TALK
};

class Actor
{
private:
	static void Move()
	{
		cout << "움직입니다." << endl;

	}

	static void Talk()
	{
		cout << "대화합니다." << endl;
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
		int select = ConsoleUtil::GetRandomInt(2); // 0부터가 아닌 1부터 나오기때문에 -1

		ActorAction aaction = static_cast<ActorAction>(select - 1);

		/*switch(select -1)
		{
		case 0: Action = Move;
			break;
		case 1: Action = Talk;
			break;
		default:
			cout << "잘못된 입력을 받아왔습니다." << endl;
			return;
		}*/
		switch (aaction)
		{
		case MOVE: Action = Move;
			break;
		case TALK: Action = Talk;
			break;
		default:
			cout << "잘못된 입력을 받아왔습니다." << endl;
			return;
		}
	}

};

#pragma endregion

#pragma region 가위,바위,보 예제 만들기

enum RSP_TYPE
{
	ROCK = 1,
	SCISSORS, 
	PAPER // 묵,찌,빠
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
		cout << "바위를 냈습니다." << endl;
	}

	static void Scissors()
	{
		cout << "가위를 냈습니다." << endl;
	}

	static void Paper()
	{
		cout << "보를 냈습니다." << endl;
	}

	void Result()
	{
		if (userType == computerType)
		{
			cout << "비겼다" << endl;
		}
		else if (userType == ROCK && computerType == SCISSORS ||
			userType == SCISSORS && computerType == PAPER ||
			userType == PAPER && computerType == ROCK)
		{
			cout << "이겼다." << endl;
			userScore++;
			ConsoleUtil::GotoXY(45, 0);
			cout << "유 저  : " << userScore << " 점" << endl;
		}
		else
		{
			cout << "졌다." << endl;
			computerScore++;
			ConsoleUtil::GotoXY(45, 2);
			cout << "컴퓨터 : " << computerScore << " 점" << endl;
		}
	}

public:
	RSPGame() : userScore(0), computerScore(0) {};

	void ShowScore()
	{
		ConsoleUtil::GotoXY(45, 0);
		cout << "유 저  : " << userScore << " 점" << endl;
		ConsoleUtil::GotoXY(45, 2);
		cout << "컴퓨터 : " << computerScore << " 점" << endl;
	}

	void StartGame()
	{
		system("cls");
		ShowScore();

		while (true)
		{
			ConsoleUtil::GotoXY(0, 0);
			cout << "1 : 바위, 2 : 가위, 3 : 보" << endl;
			ConsoleUtil::GotoXY(0, 1);
			cout << "선택해주세요." << endl;
			ConsoleUtil::GotoXY(0, 2);
			int input = 0;
			cin >> input;

			if (input < 1 || input >3)
			{
				cout << "잘못된 입력입니다." << endl;				
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
				cout << "잘못된 입력을 받아왔습니다." << endl;
				return;
			}
			cout << "유저는" << GetRSPName(userType) << " 를 냈습니다" << endl;
			cout << "컴퓨터는 ";
			Action();
			Result();

			if (userScore >= 3 || computerScore >= 3)
			{

				break;
			}

		}
		if (userScore >= 3)
		{
			cout << "컴퓨터를 이겼다." << endl;

		}
		else if (computerScore >= 3)
		{
			cout << "컴퓨터가 이겼다." << endl;

		}
	}

};

string GetRSPName(RSP_TYPE type)
{
	switch (type)
	{
	case ROCK: return "바위";
	case SCISSORS: return "가위";
	case PAPER: return "보";
	default: return "알 수 없음";
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
