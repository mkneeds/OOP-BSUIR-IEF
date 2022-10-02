#pragma once
#include <iostream>
#include "Container.h"
#include <string>

using namespace std;

class Dict
{
public:
	Container store;
	string date;
	string translates;
	void addWord();
	void getWord();
	void setDate(string word,string translate);
	string getDate();
	void printInformation();
};

namespace menu {
	void menu();
};
int checkInterval(int min, int max);
int checkInt();
