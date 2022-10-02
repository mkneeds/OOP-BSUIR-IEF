#pragma once
#include<iostream>
#include "Header.h"
using namespace std;

enum State { begin, middle };
template <class T>
class Transaction {
	T* currentState;//текущее значение объекта класса
	T* prevState;//предыдущее состояние объекта
public:
	Transaction() :prevState(NULL), currentState(new T)
	{}//конструктор без параметров
	Transaction(const Transaction& obj) : currentState(new
		T(*(obj.currentState))), prevState(NULL) {}// конструкторкопирования
	~Transaction() {
		delete currentState; delete prevState;
	}//деструктор
	Transaction& operator=(const Transaction& obj);//перегрузкаоператора присваивания
	void showState(State state);//отображение состояний(предыдущего и текущего) объекта
	int beginTransactions(string date,string translate);//метод началатранзакции
	void commit();//метод подтверждения (коммита) транзакции
	void deleteTransactions(); //метод отката транзакции
	T* getCurrentStatePtr();
};

