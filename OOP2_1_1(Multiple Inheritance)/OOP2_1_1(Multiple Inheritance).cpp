#include "IntTextWindow.h"
#include "Validators.h"
#include <vector>

int main() {
	
	system("color 2F");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	IntTextWindow* arr = new IntTextWindow[1];
	while (1) {
		menu::menu();
		switch (checkInterval(1, 6)) {
		case 1: system("cls"); system("color 1F"); (*arr).createTextWindow();  break;
		case 2: system("cls"); system("color 4F"); (*arr).createIntWindow(); break;
		case 4: system("cls"); system("color 5F"); (*arr).showWindow(); break;
		case 3: system("cls"); system("color 6F"); (*arr).connectionWindow(); break;
		case 5: system("cls"); menu::changer();
			switch (checkInterval(1, 3)) {
			case 1:   (*arr).chooseLocate();  system("cls");  break;
			case 2: break;
			};
			break;
		case 6: return 0;
			}
	}
}