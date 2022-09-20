// class container,dirt(Technik,Common), person(User,Teacher)
#include "Container.h"
#include "Dict.h"
#include <Windows.h>
#include "SmartPointer.cpp"
#include "Transaction.cpp"
#include "Header.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SmartPointer<Transaction<Dict>> a = new Transaction<Dict>;
	a->getCurrentStatePtr()->addInformation();
	a->showState(State::middle);
	a->beginTransactions();
	a->showState(State::middle);
	cout << "удаляем" << endl;

}