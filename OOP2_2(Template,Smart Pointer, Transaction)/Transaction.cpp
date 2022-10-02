#include"Transaction.h"

template <class T>
Transaction<T>& Transaction<T>::operator=(const Transaction<T>& obj) {
	if (this != &obj) {
		delete currentState;
		currentState = new T(*(obj.currentState));
	}
	return *this;
}

template <class T>
void Transaction<T>::showState(State state) {
	cout << "Состояние объекта ";
	if (!state) cout << "до начала транзакции " << endl;
	else cout << "после выполнения транзакции " << endl;
	if (prevState) cout << "prevState = " << prevState->getDate() << endl;
	else cout << "prevState = NULL" << endl;
	cout << "currentState = " << currentState->getDate() << endl;
}

template <class T>
int Transaction<T>::beginTransactions(string data,string translate) {
	delete prevState;
	prevState = currentState;
	currentState = new T(*prevState);
	if (!currentState) return 0;
	currentState->setDate(data,translate);
	return 1;
}

template <class T>
void Transaction<T>::commit() {
	delete prevState;
	prevState = NULL;
}
template <class T>
void Transaction<T>::deleteTransactions() {
	if (prevState != NULL) {
		delete currentState;
		currentState = prevState;
		prevState = NULL;
	}
}

template<class T>
T* Transaction<T>::getCurrentStatePtr()
{
	return currentState;
}