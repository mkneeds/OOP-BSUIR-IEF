#pragma once
#include <iostream>

using namespace std;

class PatternLayout
{
	string DEFAULT_CONVERSION_PATTERN;
	string TICC_CONVERSION_PATTERN;
	PatternLayout();
	PatternLayout(string a, string s) : DEFAULT_CONVERSION_PATTERN(a), TICC_CONVERSION_PATTERN(s);
	string activateOptions();
	int format();
	string ger
};

