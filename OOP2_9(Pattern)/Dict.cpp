#include "Dict.h"

void Dict::addWord() {
	cout << "������� �����(�� �������)->";
	cin.ignore();
	getline(cin, store.word);
	cout << endl;
	cout << "������� �����(�� ����������)->";
	getline(cin, store.translate);
	store.addInformation();
}

void Dict::getWord() {
	cout << "������� ����� ��� ������ �� �������(�� �������)->" << endl;
	cin >> store.searchStr;
	store.searchInformation();
}
void Dict::setDate(string date, string translate) {
	this->date = date;
	this->translates = translate;
}
string Dict::getDate() {
	string str = date + " " + translates;
	cout << str << endl;
	return str;
}

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
		cout << "������������ ����. ��������� �������->";
		value = checkInt();
	}
	return value;
}

namespace menu {
	void menu() {
		cout << "\t\t����:" << endl;
		cout << "\t(1) ~ �������� �����" << endl;
		cout << "\t(2) ~ ������� �������" << endl;
		cout << "\t(3) ~ ����� �� �������" << endl;
		cout << "\t(4) ~ �����" << endl;
		cout << "��� �����: ";
	}

}
void Dict::printInformation() {
	store.printInformation();
}