#pragma once
#include<iostream>
#include "Header.h"
using namespace std;

enum State { begin, middle };
template <class T>
class Transaction {
	T* currentState;//������� �������� ������� ������
	T* prevState;//���������� ��������� �������
public:
	Transaction() :prevState(NULL), currentState(new T)
	{}//����������� ��� ����������
	Transaction(const Transaction& obj) : currentState(new
		T(*(obj.currentState))), prevState(NULL) {}// ����������������������
	~Transaction() {
		delete currentState; delete prevState;
	}//����������
	Transaction& operator=(const Transaction& obj);//������������������� ������������
	void showState(State state);//����������� ���������(����������� � ��������) �������
	int beginTransactions(string date,string translate);//����� ����������������
	void commit();//����� ������������� (�������) ����������
	void deleteTransactions(); //����� ������ ����������
	T* getCurrentStatePtr();
};

