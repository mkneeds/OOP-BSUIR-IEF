#include "Layout.h"
#include "Validators.h"

Layout::Layout() {
	distance_from_bottom = 0;
	disctance_from_top = 0;
}

void Layout::GetConsBuff(int& x, int& y) {
    HANDLE hWndConsole;
    if (hWndConsole = GetStdHandle(-12))
    {
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo))
        {
            x = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
            y = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
            distance_from_bottom = x;
            disctance_from_top = y;
        }
        else
            printf("Error: %d\n", GetLastError());
    }
    else
        printf("Error: %d\n", GetLastError());
}
void Layout::CenterString(string &s, const size_t& width)
{
    int buffer_x_size, buffer_y_size;
    GetConsBuff(buffer_x_size, buffer_y_size);
    size_t left_bord = (buffer_x_size - width) / 2.;
    for (;;)
    {
        cout << setw(left_bord) << "";
        cout << s.substr(0u, width) << endl;
        s.erase(s.begin(), s.begin() + (s.size() < width ? s.size() : width));
        if (s.empty())
        {
            break;
        }
    }
}
int Layout::choose_locate() {
    cout << "\t\tВыбор отображения:" << endl;
    cout << "\t(1) ~ Слева" << endl;
    cout << "\t(2) ~ Центр" << endl;
    cout << "\t(3) ~ Справа" << endl;
    cout << "Ваш выбор: ";
    switch (checkInterval(1, 3)) {
    case 1: key = 1; break;
    case 2: key = 2; break;
    case 3: key = 3; break;
    }
    return key;
 }
