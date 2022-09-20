#include "Layout.h"
#include "PatternLayout.h"
#include "SimpleLayout.h"
#include "HTMLLayout.h"

class Layout {
	string line_sep;
	int line_sep_len;
	Layout();
public:
	int format();
	string getContentType();
	int getFooter();
	int getHeader();
	int ignoresThrowable();
};

