#include "TextWindow.h"

Frame TextWindow::createTextWindow() {
    cout << "������� ����� � ����:";
    getline(cin,text);
    t.add(text);
    t.endOfRow();
    return t;
}