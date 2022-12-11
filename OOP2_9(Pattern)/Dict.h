#pragma once
#include <iostream>
#include "Container.h"
#include <string>

using namespace std;

class Dict
{
public:
	Container store;
	virtual unique_ptr<Dict> clone() = 0;
	virtual void setFileStore(string name) { store.name = name; }
	string date;
	string translates;
	virtual void addWord();
	virtual void getWord();
	virtual void setDate(string word, string translate);
	virtual string getDate();
	virtual void printInformation();
};

namespace menu {
	void menu();
};
int checkInterval(int min, int max);
int checkInt();
