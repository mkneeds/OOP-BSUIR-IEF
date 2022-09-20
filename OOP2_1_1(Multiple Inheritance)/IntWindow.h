#pragma once
#include "Window.h"
#include "Frame.h"
#include <string.h>

class IntWindow : virtual public Window
{
public:
	string s;
	Window obj;
	void tokenize(string const& str, const char delim, vector<string>& out);
	Frame createIntWindow();

};

