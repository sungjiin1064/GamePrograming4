
#include "GameModel.h"
#include <conio.h>
#include "DropTable.h"
#include "DataHandler.h"


int main()
{
	Player player(0,100);
	Monster monster(0, 0);

	Data data;
	data.SaveData("data.txt");
	data.LoadData("data.txt");

	cout<< "datadÀÇ level" << 

	while (true)
	{
		system("cls");
		player.GetExp(35);
		player.Show();
		_getch();
	}
}