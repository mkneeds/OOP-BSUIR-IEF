#include "Transaction.h"

template <class T>
Transaction<T>& Transaction<T>::operator=(const Transaction<T>& obj) {
	if (this != &obj) {//проверка на случай obj=obj
		delete currentState;//удаление текущего значения объекта
		currentState = new T(*(obj.currentState));//создание икопирование объекта, используя присваеваемую транзакцию
	}
	return *this;
}

template <class T>
void Transaction<T>::showState(State state) {//метод отображениесостояния объекта
	cout << "Состояние объекта ";
	if (!state) cout << "до начала транзакции " << endl;
	else cout << "после выполнения транзакции " << endl;
	if (prevState) prevState->getWord();//предыдущее состояние
	else cout << "prevState = NULL" << endl;
	currentState->getWord();//текущее состояние
}

template <class T>
int Transaction<T>::beginTransactions() {// методначала транзакции
	delete prevState;//удаление предыдущего значения
	prevState = currentState;//сохранение предыдущего состояниякак текущего
	currentState = new T(*prevState);//текущее состояние создается!!!!!!!!!!!!!!
	if (!currentState) return 0;//ошибка (необходимо отменитьтранзакцию)
	currentState->addWord();//изменение состоянияобъекта
	return 1;//успешное окончание транзакции
}

template <class T>
void Transaction<T>::commit() {
	delete prevState;//удаление предыдущего значения
	prevState = NULL;//предыдущего состояния нет
}
template <class T>
void Transaction<T>::deleteTransactions() {
	if (prevState != NULL) {
		delete currentState;//удаление текущего значения
		currentState = prevState;//предыдущее становится текущим
		prevState = NULL;//предыдущего состояния нет
	}
}

template<class T>
T* Transaction<T>::getCurrentStatePtr()
{
	return currentState;
}