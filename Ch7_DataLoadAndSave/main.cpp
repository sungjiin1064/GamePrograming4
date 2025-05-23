
#include "GameModel.h"
#include <conio.h>
#include "DropTable.h"
#include "DataHandler.h"


int main()
{
	Player player(0,100);
	Monster monster(0, 0);

	//player.LoadData("player.txt");

	Data data;
	//data.SaveData("data1.txt");
	data.LoadData("data1.txt");

	cout << "dataÀÇ  level : " << data._level << ", exp : " << data._exp << endl;

	_getch();

	int count = 0;

	while (true)
	{
		system("cls");
		player.GetExp(35);
		player.Show();
		_getch();

		if (count >= 4)
		{
			break;
		}
	}

	player.SaveData("player.txt");
}