#pragma once
#include "IntWindow.h"
#include "TextWindow.h"

class IntTextWindow : virtual public IntWindow, virtual public TextWindow
{
	public:
	string newText;
	Frame connectionWindow();
	void pushInFile();
	
};

