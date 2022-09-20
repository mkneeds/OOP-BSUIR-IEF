#pragma once
#include <string>
#include <vector>
#include <iomanip>
#include <Windows.h>
#include <iostream>
#include "Table.h"

using namespace std;

class IntWindow : public TextWindow
{
public:
	TextWindow z;
	string str;
	int key=0;
	float distance_from_bottom;
	float disctance_from_top;
	IntWindow(float bottom, float top,int key) : disctance_from_top(top), distance_from_bottom(bottom),key(key) {}
	IntWindow();
	void GetConsBuff(int& x, int& y); //get size(window)
	void CenterString(string& s, const size_t& width);
	int get_key() const noexcept { return key;}
	int choose_locate();
	TextWindow createInterfaceInt();
	void push_in_file();
	void tokenize(string const& str, const char delim,vector<string>& out);
};
