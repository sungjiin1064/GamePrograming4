
#include <ConsoleUtility.h>
#include <iostream>
#include <conio.h>
#include "Pokeball.h"
#include <array>

using namespace std;

void Example()
{
	while (true)
	{
		int rand = ConsoleUtil::GetRandomInt(50);
		cout << rand << endl;
		Sleep(100);
		break;
	}

	int x = ConsoleUtil::GetRandomInt(50);
	int y = ConsoleUtil::GetRandomInt(50);
	//ConsoleUtil::GotoXY();l
}

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ENTER 13

template<int N>
void Display(int index)
{
	for (int i = 0; i < N; i++)
	{
		if (i == index)
		{
			cout << "▣ ";
		}
		else
		{
			cout << "□ ";
		}
	}

}

template<int N>
void Display2D(int index)
{
	int height = index / N;
	int width = index % N;

	for (int y = 0; y < N; y++)
	{
		for (int i = 0; i < N; i++)
		{
			if (i == width && y == height)
			{
				cout << "▣ ";
			}
			else
			{
				cout << "□ ";
			}
		}
		cout << endl;
	}
}


int main()
{
	ConsoleUtil::SetCursorVisible(false);

	int selectedIndex = 0;
	int input;

	std::array<PokeMon*, 40> pokeballs;

	PokeMon defaultMonster(0, "");

	pokeballs.fill(&defaultMonster);

	pokeballs[0] = new PokeMon(1, "이상해씨");
	pokeballs[1] = new PokeMon(25, "피카츄");
	pokeballs[2] = new PokeMon(8, "꼬부기");
	pokeballs[3] = new PokeMon(13, "파이리");

	while (true)
	{
		

		const int size = 10; // const 필수
		int sizePow = size * size;

		ConsoleUtil::GotoXY(0, 0);
		Display2D<size>(selectedIndex);

		if (_kbhit())
		{
			input = _getch();

			if (input == LEFT)
			{
				//cout << "왼쪽";
				selectedIndex = (selectedIndex - 1 + sizePow) % sizePow; // 0~5

			}
			else if (input == RIGHT)
			{
				selectedIndex = (selectedIndex + 1) % sizePow;
			}
			else if (input == UP)
			{
				selectedIndex = (selectedIndex - size + sizePow) % sizePow;
			}
			else if (input == DOWN)
			{
				selectedIndex = (selectedIndex + size) % sizePow;
			}
			else if (input == ENTER)
			{

				break;
			}
			system("cls");
		}

		ConsoleUtil::GotoXY(30, 0);
		cout << "몬스터 UI";
		ConsoleUtil::GotoXY(30, 1);
		cout << "No_" << pokeballs[selectedIndex]->get_number() << pokeballs[selectedIndex]->get_name() << endl;
	}

	cout << pokeballs[selectedIndex]->get_name() << endl;

}

