#include "Window.h"
#include "Validators.h"

int main() {
	system("color 3F");
	setlocale(0, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Window* A = new Window[2];


	while (1) {
		menu::menu();
		switch (checkInterval(1, 5)) {
		case 1: system("cls"); A->createInterface(); break;
		case 2: system("cls"); A->createInterfaceInt(); break;
		case 3: system("cls"); A->showInterface(); break;
		case 4: system("cls"); menu::changer();
			switch (checkInterval(1, 3)) {
			case 1: system("cls"); A->choose_locate(); break;
			case 2: break;
			};
			break;
		case 5: return 0;
		}
	}
}