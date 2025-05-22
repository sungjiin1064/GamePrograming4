
#include "GameModel.h"

int main()
{
	Player player(100, 10);
	Monster monster(80, 5);

	while (player.getHealth() > 0 && monster.getHealth() > 0)
	{
		player.attack(monster);
		if (monster.getHealth() > 0)
		{
			monster.attack(player);
		}
	
	}

	cout << "������ ����Ǿ����ϴ�." << endl;
}