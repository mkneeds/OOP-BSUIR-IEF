#include "TextWindow.h"

Frame TextWindow::createTextWindow() {
    cout << "¬ведите слово в блок:";
    getline(cin,text);
    t.add(text);
    t.endOfRow();
    return t;
}