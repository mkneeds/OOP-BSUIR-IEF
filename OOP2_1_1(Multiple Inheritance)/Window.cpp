#include "Window.h"
#include "Validators.h"

Window::Window() {
	sizeL = 0;
	sizeW = 0;
}

void Window::getConsBuff(int& x, int& y) {
    HANDLE hWndConsole; //window handle
    if (hWndConsole = GetStdHandle(-12)) //standart handle error
    {
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo))
        {
            x = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
            y = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
           sizeL = x;
           sizeW = y;
        }
        else
            cout << "Error: %d\n" << GetLastError();
    }
    else
        cout << "Error: %d\n" << GetLastError();
}

void Window::centerString(string& s, const size_t& width)
{
	int buffer_x_size, buffer_y_size;
	getConsBuff(buffer_x_size, buffer_y_size);
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


void Window::showWindow() {
	ifstream fin("Text.txt");
	string s;
	while (getline(fin, s)) {
		if (key == 1 || key == 0) {
			cout << s << endl;
		}
		if (key == 2) {
			centerString(s, 25u);
		}
		if (key == 3) {
			cout << setw(115) << s << endl;
		}
	}
	fin.close();
}

void menu::menu() {
	cout << "\t\t����:" << endl;
	cout << "\t(1) ~ �������� ��������� ����" << endl;
	cout << "\t(2) ~ �������� �������� ����" << endl;
	cout << "\t(3) ~ ��������� ��������� � �������� ����" << endl;
	cout << "\t(4) ~ ���������� ����" << endl;
	cout << "\t(5) ~ �������������� �������" << endl;
	cout << "\t(6) ~ �����" << endl;
	cout << "��� �����: ";
}

void Window::pushInFile() {
	ofstream fout("Text.txt", ios::app);
	fout << t;
	fout.close();
}

void menu::changer() {
	cout << "\t\t���� ����������:" << endl;
	cout << "\t(1) ~ �������� ������������" << endl;
	cout << "\t(2) ~ �����" << endl;
	cout << "��� �����: ";
}
int Window::chooseLocate() {
	cout << "\t(1) ~ �����" << endl;
	cout << "\t(2) ~ �����" << endl;
	cout << "\t(3) ~ ������" << endl;
	cout << "��� �����: ";
	key = checkInterval(1,3);
	return key;
	
}