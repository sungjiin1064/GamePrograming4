#pragma once

#include <chrono>
#include <random>
#include "Windows.h"
#include <iostream>

using namespace std;

class ConsoleUtil
{
public:
	static void GotoXY(int x, int y)
	{
		COORD pos = { static_cast<short>(x), static_cast<short>(y) };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	static int GetRandomInt(int max)
	{
		static std::random_device rd; // �õ� ������
		static std::mt19937 gen(rd()); // Mersenne Twister ����
		std::uniform_int_distribution<> dist(1, max); // 1���� max������ ������ ���� ����
		return dist(gen); // ��
	}

	static void SetCursorVisible(bool visible)
	{
		CONSOLE_CURSOR_INFO c = { 0 };
		c.dwSize = 1;
		c.bVisible = visible;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &c);
	}

	static void TimeCheck(void (*Func)())
	{
		auto start = std::chrono::high_resolution_clock::now();

		Func();

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> duration = end - start;
		cout << duration.count() << "ms�ð��� �ɷȽ��ϴ�." << endl;
		
	}

};