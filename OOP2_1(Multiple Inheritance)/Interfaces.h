#pragma once
#include <iostream>
#include "Layout.h"
#include <vector>
#include "Validators.h"
#include "Table.h"

#include <fstream>

using namespace std;

class Interfaces : public Layout, public TextWindow
{
public:
	vector<string> window;
	string s;
	TextWindow t;
	double size_l; // in lenght
	double size_w;// in width
	Interfaces(double size_l, double size_w,string s) : size_l(size_l), size_w(size_w),s(s) {}
	Interfaces();
	double getSize_L() const noexcept { return size_l; }
	double getSize_W() const noexcept { return size_w; }
	/*vector<string>createInterface();*/
	void showInterface();
	TextWindow createInterface();
	void push_in_file();
};
namespace menu {
	void menu();
	void changer();
}

