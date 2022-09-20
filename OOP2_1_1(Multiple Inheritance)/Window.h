#pragma once
#include <iostream>
#include <vector>
#include "Frame.h"
#include <Windows.h>
#include <fstream>

using namespace std;

class Window : public Frame
{
public:
	vector <string> window;
	string str;
	Frame t;
	float sizeL;
	float sizeW;
	int key = 1;
	Window();
	Window(float L , float W) : sizeL(L), sizeW(W){}
	Window(Window const& t, float const&sizeL,float const&sizeW) : t(t), sizeL(sizeL), sizeW(sizeW) {}
	int8_t getKey() const noexcept { return key; }
	void showWindow();
	virtual void pushInFile();
	void getConsBuff(int& x, int& y); //get size(window)
	void centerString(string& s, const size_t& width);
	int chooseLocate();
};

namespace menu {
	void menu();
	void changer();
}
