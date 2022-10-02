
#include "Container.h"
#include "Dict.h"
#include <Windows.h>
#include "SmartPointer.cpp"
#include "Transaction.cpp"
#include "Header.h"
#include <memory>
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SmartPointer<Dict> b = new Dict();
	while (1) {
		menu::menu();
		switch (checkInterval(1, 5)) {
		case 1: system("cls"); b->addWord(); break;
		case 2: system("cls"); b->printInformation(); break;
		case 3: system("cls"); b->getWord(); break;
		case 4: system("cls"); {
			SmartPointer<Transaction<Dict>> a = new Transaction<Dict>;
			a->getCurrentStatePtr();
			a->showState(State::middle);
			a->beginTransactions("Привет", "Hello");
			a->showState(State::middle);
			cout << "удаляем" << endl;
			a->deleteTransactions();
			a->showState(State::middle);
			a->commit();
		} break;
		case 5: return 0;
		}
	}

	

}