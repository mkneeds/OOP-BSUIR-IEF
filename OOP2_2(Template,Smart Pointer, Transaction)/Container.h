#pragma once
#include <fstream>
#include <sstream>
using namespace std;

class Container
{
public:
	int key = 0;
	string key_co;
	string word;
	string translate;
	string searchStr;
	void writeEndFile();
	void addInformation();
	int uploadInformation();
	void printInformation();
	void searchInformation();

};

