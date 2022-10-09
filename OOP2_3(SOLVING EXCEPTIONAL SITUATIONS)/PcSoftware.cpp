#include "PcSoftware.h"


int checkInts()
{
	int value, counter = 0;
	char* BufForWriting = new char[256];
	cin.clear();
	cin.getline(BufForWriting, 256, '\n');
	for (int i = 0; BufForWriting[i] != '\0'; i++)
		if (isdigit(BufForWriting[i]))
			counter++;
	if (strlen(BufForWriting) != counter ||
		(BufForWriting[0] == '0' && strlen(BufForWriting) > 1))
		value = -1;
	else value = atoi(BufForWriting);
	delete[] BufForWriting;
	return value;
}

int checkIntervals(int min, int max)
{
	int value;
	value = checkInts();
	while (value < min || value > max)
	{
		cout << "Неккоректный ввод. Повторите попытку->";
		value = checkInts();
	}
	return value;
}

void PcSoftware::SwitchPC() {
	SystemPO a;
	if (OnPc == 0) {
		cout << "\tПК выключен" << endl;
		cout << "\tЖелаете ли вы его включить...?" << endl;
		cout << "\t (0) -  Нет" << endl;
		cout << "\t (1) -  Да" << endl;
		switch (checkIntervals(0, 1)) {
		case 0: OnPc = 0; break;
		case 1: OnPc = 1; a.check_system(); break;
		case 2: a.print_i(); break;
		}
	}
	else {
		cout << "Компьютер включен....!" << endl;
	}
}
