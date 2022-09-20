#include "Window.h"
#include "Validators.h"

using namespace std;

void menu::menu() {
	cout << "\t\t����:" << endl;
	cout << "\t(1) ~ �������� ��������� ����" << endl;
	cout << "\t(2) ~ �������� �������� ����" << endl;
	cout << "\t(3) ~ ���������� ����" << endl;
	cout << "\t(4) ~ ��������������" << endl;
	cout << "\t(5) ~ �����" << endl;
	cout << "��� �����: ";
}


void menu::changer() {
	cout << "\t\t���� ����������:" << endl;
	cout << "\t(1) ~ �������� ������������" << endl;
	cout << "\t(2) ~ �����" << endl;
	cout << "��� �����: ";
}
//vector<string> Interfaces::createInterface() {
//	cout << "������� ������ �����:"<<endl;
//	size_l = checkInt();
//	cout << "������� ������ �����:" << endl;
//	size_w = checkInt();
//	window.clear();
//	for (int i = 0; i < size_w; i++)
//	{
//		if (i == 0 || i == size_l - 1)
//		{
//			int temp = size_w;
//			while (temp--) window.push_back("-");
//			window.push_back("\n");
//		}
//		else if (i == 0) {
//			int temp = size_w;
//			while (temp--) window.push_back("-");
//			window.push_back("\n");
//			
//		}
//		else
//		{
//			for (int j = 0; j < size_w; j++)
//			{
//				if (j == 0 || j == size_w - 1) window.push_back("|");
//				else window.push_back(" ");;
//			}
//			window.push_back("\n");
//		}
//	}
//	return window;
//	
//}

TextWindow Window::createInterface() {
	cout << "������� �������� ����� ������� ������ ��������:";
	getline(cin, s);
	t.add(s);
	t.endOfRow();
	push_in_file();
	return t;
}

void Window::showInterface() {
	ifstream fin("Inter.txt");
	string s;
	while (getline(fin, s)) {
		if (key == 1 || key == 0) {
			cout << s << endl;
		}
		if (key == 2) {
			CenterString(s, 25u);
		}
		if (key == 3) {
			cout<<setw(115) << s << endl;
		}
	}
	fin.close();
}


Window::Window() {
	Size_l = 0;
	Size_w = 0;
	s = "";
}

void Window::push_in_file() {
	ofstream fout("Inter.txt", ios::app);
	fout << t;
	fout.close();
 }

