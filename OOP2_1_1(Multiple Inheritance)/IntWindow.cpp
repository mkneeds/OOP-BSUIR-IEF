#include "IntWindow.h"

void IntWindow::tokenize(string const& str, const char delim, vector<string>& out) {
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}
bool is_digits(const std::string& str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}
Frame IntWindow::createIntWindow() {
    cout << "Введите ЦИФРЫ в блок:";
    cin.clear();
    getline(cin, s);
    const char symbol = ' ';
    vector <string> out;
    bool flag = true;
    tokenize(s, symbol, out);
    for (auto& s : out) {
        if (is_digits(s)) {
            flag = true;
        }
        else {
            flag = false;
        }
    }
    if (flag == true) {
        t.add(s);
        t.endOfRow();
        return t;
    }
    else {
        system("cls");
        cout << "Строка содержит нетолько цифры.Повторите попытку." << endl;
        s = "";
        return t;
    }
}