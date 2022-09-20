#include "Window.h"
#include "Validators.h"

using namespace std;

void menu::menu() {
	cout << "\t\tМеню:" << endl;
	cout << "\t(1) ~ Добавить текстовое окно" << endl;
	cout << "\t(2) ~ Добавить числовое окно" << endl;
	cout << "\t(3) ~ Отобразить окно" << endl;
	cout << "\t(4) ~ Редактирование" << endl;
	cout << "\t(5) ~ Выход" << endl;
	cout << "Ваш выбор: ";
}


void menu::changer() {
	cout << "\t\tМеню параметров:" << endl;
	cout << "\t(1) ~ Изменить расположение" << endl;
	cout << "\t(2) ~ Назад" << endl;
	cout << "Ваш выбор: ";
}
//vector<string> Interfaces::createInterface() {
//	cout << "Введите высоту рамки:"<<endl;
//	size_l = checkInt();
//	cout << "Введите ширину рамки:" << endl;
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
	cout << "Введите название блока который хотите добавить:";
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

