#include "Interfaces.h"
#include "Layout.h"
#include "Validators.h"

int main() {
	Interfaces A;
	setlocale(0, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	menu:
	menu::menu();
	switch (checkInterval(1, 4)) {
	case 1: A.createInterface(); goto menu; break;
	case 2: A.showInterface(); goto menu; break;
	case 3: system("cls"); menu::changer();
		switch (checkInterval(1, 3)) {
		case 1: A.choose_locate(); goto menu;
		case 2: goto menu;
		};
		goto menu; break;
	case 4: return 0;
	}
}