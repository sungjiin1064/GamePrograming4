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
	ROCK, SCISSORS, PAPER // 묵,찌,빠
};

class RSPGame
{
	RSPGame() : userScore(0), computerScore(0);
	void (*Action)();

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

	RSP_TYPE computerType;
	RSP_TYPE userType;

	int userScore;
	int computerScore;
	//string name[] = { "바위", "가위", "보" };

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
			cout<< "이겼다."<< endl;
		}
		else
		{
			cout << "졌다." << endl;
		}
	
	}

public:	
	void StartGame()
	{
		
		cout << "0 : 바위, 1 : 가위, 2 : 보" << endl;
		cout << "선택해주세요." << endl;
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
			cout << "잘못된 입력을 받아왔습니다." << endl;
			return;
		}
		cout << "유저는" << name[0] << " 를 냈습니다" << endl;
		cout << "컴퓨터는 ";
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