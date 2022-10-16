#pragma once
#include <iostream>

using namespace std;

int checkInt()
{
	int value, counter = 0;
	char* BufForWriting = new char[256];
	cin.clear();
	cin.getline(BufForWriting, 256, '\n');
	for (int i = 0; BufForWriting[i] != '\0'; i++)
		if (isdigit(BufForWriting[i]))
			counter++;
	if (strlen(BufForWriting) != counter ||
		(BufForWriting[0] == '0' && strlen(BufForWriting) > 1))
		value = -1;
	else value = atoi(BufForWriting);
	delete[] BufForWriting;
	return value;
}

int checkInterval(int min, int max)
{
	int value;
	value = checkInt();
	while (value < min || value > max)
	{
		cout << "Неккоректный ввод. Повторите попытку->";
		value = checkInt();
	}
	return value;
}

namespace menu {
	void menu() {
		cout << "\t\tМеню:" << endl;
		cout << "\t(1) ~ Проверить ПК" << endl;
		cout << "\t(2) ~ Вывести системные файлы" << endl;
		cout << "\t(3) ~ Вывести Пользовательские файлы" << endl;
		cout << "\t(4) ~ Исключительная ситуация(invalid operation)" << endl;
		cout << "\t(5) ~ Исключительная ситуация(owerflow)" << endl;
		cout << "\t(6) ~ Свой класс исключения" << endl;
		cout << "\t(7) ~ Собственная функция завершения" << endl;
		cout << "\t(8) ~ Исключительная ситуация с оператором new" << endl;
		cout << "\t(9) ~ Исключительная ситуация с конструктором " << endl;
		cout << "\t(10) ~ Распечатать содержимое файла " << endl;
		cout << "\t(11) ~ Удалить содержимое файла " << endl;
		cout << "\t(12) ~ Поиск по файлу " << endl;
		cout << "\t(13) ~ Удалить какую-то строку " << endl;
		cout << "\t(14) ~ Выход" << endl;
		cout << "Ваш выбор: ";
	}

}

float division(float divisible, float divisor) {
	if (divisor == 0) throw 1;
	return divisible / divisor;
}

void First_exp() {
	float result, value = 3;
	while (true) {
		try {
			result = division(77., value);
			cout << "Результат деления:" << result << endl;
			value--;
		}
		catch (int) {
			cout << "Произошло деление на ноль" << endl;
			break;
		}
	}
}

void Five_exp() {
	try { PcSoftware *ob = new PcSoftware(1);
	}
	catch (int) { cout << "Construtor exception handler" << endl; }
}
void Four_exp() {
	char* p;
	try
	{
		for (int i = 0; i < 1000; i++)
		{
			int a = -1;
			p = new char[a];
			cout << i << ":success of allocation " << endl;
		}
	}
	catch (bad_alloc)
	{
		cout << "Allocation failure " << endl;
		/*abort();*/
	}
}

void termFunc();
void Three_exp() {
	int i = 10, j = 0, result;
	set_terminate(termFunc);
	try {
		if (j == 0) throw "Деление на ноль!";
		else result = i / j;
	}
	catch (int) {

		cout << "Обработка исключения типа int.\n";
	}
	cout << "Эта строка не будет выведена на экран.\n";
}
void termFunc() {
	cout << "Функция termFunc() вызвана функцией terminate().\n";
	exit(-1);
}

class Exception : public std::exception
{
	std::string msg;
public:
	Exception(const std::string& msg) : msg(msg) {}

	virtual const char* what() const noexcept override
	{
		return msg.c_str();
	}
};
LONG new_filter(PEXCEPTION_POINTERS  pExceptionInfo)
{
	cout << "Новыый фильтр." << endl;
	cout << "Код ошибки = " << hex << pExceptionInfo->ExceptionRecord->ExceptionCode << endl;
	return EXCEPTION_EXECUTE_HANDLER;
}
void Twice_exp() {
	int* p = NULL;
	LPTOP_LEVEL_EXCEPTION_FILTER  old_filter;
	//устанавливаем новую функцию-фильтр необработанных исключений
	old_filter =
		SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)new_filter);
	//выводим адрес старой функции-фильтра
	cout << "Адрес старой функции = " << hex << old_filter << endl;
	*p = 10;  //создаем необработанное исключение
	cout << "The END." << endl;
}

void delete_file() {
	ofstream ofs;
	ofs.open("window.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();
}
void print_file() {
	fstream in;
	in.open("window.txt");
	string s;
	while (getline(in,s) && !in.eof()){
		cout << s << endl;
	}
}
void search_in_file() {
	ifstream file("window.txt"); // открыли файл с текстом
	string s, find;
	char c;

	while (!file.eof()) {  // прочитали его и заполнили им строку
		file.get(c);
		s.push_back(c);
	}

	file.close(); // обязательно закрыли

	cout << "Введите слово для поиска: ";
	cin >> find;

	int pos = s.find(find); // поиск

	if (pos == -1)
		cout << "Ничего не найдено" << endl;
	else
		cout << "Найдено совпадение" << find << "Позиция ->"<< pos << endl;
	file.close();
}

void delete_inform() {
	ifstream file_zin;
	file_zin.open("window.txt");
	if (!file_zin) {
		cout << "Ошибка, невозможно открыть файл: " << endl;
	}
	cout << "Введите запись которую нужно удалить..." << endl;
	char* str = new char[256];
	cin >> str;
	char* str_check = new char[256];
	int checker = 0;
	int proverka = 0;
	int nomer_str = 0;
	while (!file_zin.eof()) {
		file_zin >> str_check;
		if (strcmp(str, str_check) == 0) {
			proverka = 1;
			nomer_str++;
			break;
		}
		else {
			checker++;
		}
		if (checker % 3 == 0) {
			checker = 0;
			nomer_str++;
		}
	}
	if (proverka != 1) {
		cout << "Строка не найдена..." << endl;
	}
	else {
		file_zin.seekg(0, ios::beg);
		int i_number_line_now = 0;
		string line;
		string line_file_text;

		while (getline(file_zin, line))
		{
			i_number_line_now++;
			if (!(i_number_line_now == nomer_str))
			{
				line_file_text.insert(line_file_text.size(), line);
				line_file_text.insert(line_file_text.size(), "\r\n");
			}
		}
		file_zin.close();
		ofstream file_zout;
		file_zout.open("window.txt", std::ios::trunc | std::ios::binary);
		file_zout.write(line_file_text.c_str(), line_file_text.size());
		file_zout.clear();
		file_zout.close();
	}
	system("pause");
	delete[]str_check;
	delete[]str;
}