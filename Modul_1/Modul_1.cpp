#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "Header.h"

using namespace std;

int menu();
int main()
{
	int answer = menu();
	switch (answer)
	{
	case 0:Task_1(); break;
	case 1:Task_2(); break;
	case 2:Task_3(); break;
	case 3:Task_4(); break;
	case 4:Task_5(); break;
		system("pause");
		return 0;
	}
	return 0;
}

int menu() {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 5) % 5;
		if (key == 0) cout << "-> Task_1" << endl;
		else  cout << "   Task_1" << endl;
		if (key == 1) cout << "-> Task_2" << endl;
		else  cout << "   Task_2" << endl;
		if (key == 2) cout << "-> Task_3" << endl;
		else  cout << "   Task_3" << endl;
		if (key == 3) cout << "-> Task_4" << endl;
		else  cout << "   Task_4" << endl;
		if (key == 4) cout << "-> Task_5" << endl;
		else  cout << "   Task_5" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}
