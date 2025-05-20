
#include "CustomVector.h"
#include <vector>
#include "RandomEncount.h"
#include <conio.h>

int main()
{
	//test1();
	//test2();
	Player player;
	Monster monster;

	while (true)
	{
		system("cls");
		Battle(player,&monster);
		player.display();
		cout << "키를 입력하면 다음 전투가 진행됩니다." << endl;
		_getch();
	}
}