
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
		cout << "Ű�� �Է��ϸ� ���� ������ ����˴ϴ�." << endl;
		_getch();
	}
}