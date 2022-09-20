#include<iostream>
#include<locale.h>
#include<string>
#include <windows.h>

using namespace std;

class String {

public:
	char* str;

	String()
	{
		this->str = nullptr;
	}

	String(char* line) // КОНСТРУКТОР С ПАРАМЕТРОМ
	{
		int length = strlen(line);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = line[i];
		}
		this->str[length] = '\0';
	}

	~String()
	{
		delete[] this->str;
	}

	String(const String& other) // КОНСТРУКТОР С КОПИРОВАНИЯ
	{
		int length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
	}

	friend ostream& operator <<(ostream& ost, const String& obj);
	friend istream& operator >>(istream& ist, String& obj);

	bool operator !() {
		if (this->str == nullptr) {
			return true;
		}
		else return false;
	}

	char operator[](int index)
	{
		return str[index];
	}

	String operator ()(int a, int b) {
		char* s = new char[b - a + 2];
		for (int i = a; i <= b; i++)
		{
			s[i - a] = str[i];
			s[b - a + 1] = 0;
		}
		String ret(s);
		delete[]s;
		return ret;
	}

	String operator =(String& other)
	{
		int length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
		return *this;
	}

	int lengthCheck()
	{
		int length = strlen(this->str);
		return length;
	}
};

ostream& operator <<(ostream& ost, const String& obj)
{
	ost << obj.str << endl;
	return ost;
}

istream& operator >>(istream& ist, String& obj)
{
	char* c = new char[100];
	ist >> c;
	String str(c);
	obj = str;
	return ist;
}

bool check(int value, bool toggle, int length)
{
	if (!cin) {
		cout << "\nVVODITE TOLKO CHISLA\n" << endl;
		cin.clear();
		while (cin.get() != '\n');

	}
	else if (value > length || value < 0)
	{
		cout << "\nINCORRECT INPUT\n" << endl;
	}
	else toggle = true;
	return toggle;
}

int main()
{
	bool toggle = false;
	int index, a, b;
	setlocale(LC_ALL, "RUS");

	cout << "Введите строку 1" << " ";

	String line_1;
	cin >> line_1;
	String line_2;

	int length = line_1.lengthCheck();

	bool f = !line_2;
	if (f)cout << "сторока 2 пуста" << endl;
	else cout << "сторока 2 не пуста" << endl;

	cout << "Введите номер элемента 1 строки который хотите возвратить" << endl;
	for (;;) {
		cin >> index;
		toggle = check(index, toggle, length);
		if (toggle == true) break;
	}
	toggle = false;
	cout << line_1[index - 1] << endl;

	cout << "Введите первый и последний элемент подстроки которую хотите вернуть" << endl;
	for (;;) {
		cin >> a;
		toggle = check(index, toggle, length);
		if (toggle == true) break;
	}
	toggle = false;
	for (;;) {
		cin >> b;
		toggle = check(b, toggle, length);
		if (toggle == true) break;
	}
	a = a - 1;
	b = b - 1;
	String line_3(line_1(a, b));

	cout << line_3;
}