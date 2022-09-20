#include "Transaction.h"

template <class T>
Transaction<T>& Transaction<T>::operator=(const Transaction<T>& obj) {
	if (this != &obj) {//�������� �� ������ obj=obj
		delete currentState;//�������� �������� �������� �������
		currentState = new T(*(obj.currentState));//�������� ������������ �������, ��������� ������������� ����������
	}
	return *this;
}

template <class T>
void Transaction<T>::showState(State state) {//����� �������������������� �������
	cout << "��������� ������� ";
	if (!state) cout << "�� ������ ���������� " << endl;
	else cout << "����� ���������� ���������� " << endl;
	if (prevState) prevState->getWord();//���������� ���������
	else cout << "prevState = NULL" << endl;
	currentState->getWord();//������� ���������
}

template <class T>
int Transaction<T>::beginTransactions() {// ����������� ����������
	delete prevState;//�������� ����������� ��������
	prevState = currentState;//���������� ����������� ������������ ��������
	currentState = new T(*prevState);//������� ��������� ���������!!!!!!!!!!!!!!
	if (!currentState) return 0;//������ (���������� ������������������)
	currentState->addWord();//��������� ����������������
	return 1;//�������� ��������� ����������
}

template <class T>
void Transaction<T>::commit() {
	delete prevState;//�������� ����������� ��������
	prevState = NULL;//����������� ��������� ���
}
template <class T>
void Transaction<T>::deleteTransactions() {
	if (prevState != NULL) {
		delete currentState;//�������� �������� ��������
		currentState = prevState;//���������� ���������� �������
		prevState = NULL;//����������� ��������� ���
	}
}

template<class T>
T* Transaction<T>::getCurrentStatePtr()
{
	return currentState;
}