#pragma once
#include "Window.h"
class TextWindow : virtual public Window
{
public:
	string text;
	Window ob;
	Frame createTextWindow();
};

