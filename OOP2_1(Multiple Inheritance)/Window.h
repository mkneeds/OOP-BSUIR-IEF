#pragma once
#include "IntWindow.h"
#include "Validators.h"
#include "Table.h"
#include <vector>
#include <fstream>
#include "Window.h"
#include <Windows.h>
#include <fstream>
using namespace std;

class Window : public IntWindow, public TextWindow
{
public:
	vector <string> windows;
	string s;
	TextWindow t;
	float Size_l; // in lenght
	float Size_w;// in width
	Window(float size_l, float size_w,string s) : Size_l(size_l), Size_w(size_w),s(s) {}
	Window();
	float getSize_l() const noexcept { return Size_l; }
	float getSize_w() const noexcept { return Size_w; }
	/*vector<string>createInterface();*/
	void showInterface();
	TextWindow createInterface();
	void push_in_file();
};
namespace menu {
	void menu();
	void changer();
}

