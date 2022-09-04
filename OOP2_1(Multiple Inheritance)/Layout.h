#pragma once
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <Windows.h>
#include <string>
#include <iostream>

using namespace std;

class Layout
{
public:
	int key=0;
	double distance_from_bottom;
	double disctance_from_top;
	Layout(double bottom, double top,int key) : disctance_from_top(top), distance_from_bottom(bottom),key(key) {}
	Layout();
	void GetConsBuff(int& x, int& y); //get size(window)
	void CenterString(string& s, const size_t& width);
	int get_key() const noexcept { return key;}
	int choose_locate();
};

