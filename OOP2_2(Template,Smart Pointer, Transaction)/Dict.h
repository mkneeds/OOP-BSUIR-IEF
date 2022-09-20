#pragma once
#include <iostream>
#include "Container.h"
#include <string>

using namespace std;

class Dict : virtual public Container
{
public:
	void addWord();
	void getWord();
};

