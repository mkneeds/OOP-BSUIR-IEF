#include "IntWindow.h"
#include "Validators.h"
#include "fstream"
#include <sstream>
IntWindow::IntWindow() {
	distance_from_bottom = 0;
	disctance_from_top = 0;
}

void IntWindow::GetConsBuff(int& x, int& y) {
    HANDLE hWndConsole; //window handle
    if (hWndConsole = GetStdHandle(-12)) //standart handle error
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
            cout << "Error: %d\n"<< GetLastError();
    }
    else
        cout << "Error: %d\n"<< GetLastError();
}

void IntWindow::CenterString(string &s, const size_t& width)
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
int IntWindow::choose_locate() {
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
bool is_digits(const std::string& str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}
TextWindow IntWindow::createInterfaceInt() {
    cout << "Введите ЦИФРЫ в блок:";
    getline(cin, str);
    const char symbol = ' ';
    vector <string> out;
    bool flag = true;
    tokenize(str, symbol, out);
    for (auto& str : out) {
        if (is_digits(str)) {
            flag = true;
        }
        else {
            flag = false;
        }
    }
    if (flag == true) {
        z.add(str);
        z.endOfRow();
        push_in_file();
        return z;
    }
    else {
        system("cls");
        cout << "Строка содержит нетолько цифры.Повторите попытку." << endl;
        IntWindow::createInterfaceInt();
    }
}
void IntWindow::push_in_file() {
    ofstream fout("Inter.txt", ios::app);
    fout << z;
    fout.close();
}
    void IntWindow::tokenize(std::string const& str, const char delim,
        std::vector<std::string> &out)
    {
        size_t start;
        size_t end = 0;

        while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
        {
            end = str.find(delim, start);
            out.push_back(str.substr(start, end - start));
        }
    }