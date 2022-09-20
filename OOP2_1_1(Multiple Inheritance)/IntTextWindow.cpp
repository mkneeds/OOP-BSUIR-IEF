#include "IntTextWindow.h"

Frame IntTextWindow::connectionWindow() {
	newText = text + " " + s;
    t.add(newText);
    t.endOfRow();
    pushInFile();
    return t;
}
void IntTextWindow::pushInFile() {
	ofstream fout("Text.txt", ios::app);
	fout << t;
	fout.close();
}
