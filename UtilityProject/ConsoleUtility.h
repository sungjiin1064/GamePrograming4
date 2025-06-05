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

	static void SetColor(int colorID)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
	}

	static void SetWindowSize(int cols, int lines)
	{
		system("title PacManX");
		char cmd[30];
		sprintf_s(cmd, "mode con cols=%d lines=%d", cols, lines);
		system(cmd);
	}
};

//const int WHITE_COLOR = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
//const int RED_COLOR = FOREGROUND_RED | FOREGROUND_INTENSITY;
//const int BLUE_COLOR = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
//const int GREEN_COLOR = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
//const int BLUE_GREEN_COLOR = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
//const int BLUE_LITE_COLOR = FOREGROUND_BLUE | FOREGROUND_GREEN;
//const int YELLOW_COLOR = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
//const int YELLOW_LITE_COLOR = FOREGROUND_RED | FOREGROUND_GREEN;
//const int GRAY_COLOR = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
//const int PINK_COLOR = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
//
//const int TITLE_COLOR = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;
//const int SELECTED_COLOR = BACKGROUND_GREEN | BACKGROUND_BLUE | WHITE_COLOR;
//const int THEME_COLOR = BLUE_GREEN_COLOR;
//const int GAMENAME_COLOR = FOREGROUND_GREEN;
//const int HIGHLIGHT_COLOR = BACKGROUND_GREEN | WHITE_COLOR;
//const int PAUSE_COLOR = BACKGROUND_RED | WHITE_COLOR;
//const int LOST_COLOR = BACKGROUND_RED | BACKGROUND_INTENSITY | WHITE_COLOR;
//const int WIN_COLOR = BACKGROUND_GREEN | BACKGROUND_INTENSITY | WHITE_COLOR;
//const int MODE_COLOR = TITLE_COLOR | FOREGROUND_GREEN;