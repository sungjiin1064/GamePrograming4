
#include <iostream>
#include "ConsoleUtility.h"

using namespace std;

int main()
{

	while (true)
	{
		int random = ConsoleUtil::GetRandomInt(100);
		cout << random << endl;
		Sleep(100);
		break;
	}

	ConsoleUtil::GotoXY(0, 10);
	cout << "����" << endl;
	ConsoleUtil::GotoXY(10, 10);
	cout << "����" << endl;
}