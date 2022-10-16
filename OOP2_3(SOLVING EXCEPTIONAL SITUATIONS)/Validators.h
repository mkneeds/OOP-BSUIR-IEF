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
		cout << "������������ ����. ��������� �������->";
		value = checkInt();
	}
	return value;
}

namespace menu {
	void menu() {
		cout << "\t\t����:" << endl;
		cout << "\t(1) ~ ��������� ��" << endl;
		cout << "\t(2) ~ ������� ��������� �����" << endl;
		cout << "\t(3) ~ ������� ���������������� �����" << endl;
		cout << "\t(4) ~ �������������� ��������(invalid operation)" << endl;
		cout << "\t(5) ~ �������������� ��������(owerflow)" << endl;
		cout << "\t(6) ~ ���� ����� ����������" << endl;
		cout << "\t(7) ~ ����������� ������� ����������" << endl;
		cout << "\t(8) ~ �������������� �������� � ���������� new" << endl;
		cout << "\t(9) ~ �������������� �������� � ������������� " << endl;
		cout << "\t(10) ~ ����������� ���������� ����� " << endl;
		cout << "\t(11) ~ ������� ���������� ����� " << endl;
		cout << "\t(12) ~ ����� �� ����� " << endl;
		cout << "\t(13) ~ ������� �����-�� ������ " << endl;
		cout << "\t(14) ~ �����" << endl;
		cout << "��� �����: ";
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
			cout << "��������� �������:" << result << endl;
			value--;
		}
		catch (int) {
			cout << "��������� ������� �� ����" << endl;
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
		if (j == 0) throw "������� �� ����!";
		else result = i / j;
	}
	catch (int) {

		cout << "��������� ���������� ���� int.\n";
	}
	cout << "��� ������ �� ����� �������� �� �����.\n";
}
void termFunc() {
	cout << "������� termFunc() ������� �������� terminate().\n";
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
	cout << "������ ������." << endl;
	cout << "��� ������ = " << hex << pExceptionInfo->ExceptionRecord->ExceptionCode << endl;
	return EXCEPTION_EXECUTE_HANDLER;
}
void Twice_exp() {
	int* p = NULL;
	LPTOP_LEVEL_EXCEPTION_FILTER  old_filter;
	//������������� ����� �������-������ �������������� ����������
	old_filter =
		SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)new_filter);
	//������� ����� ������ �������-�������
	cout << "����� ������ ������� = " << hex << old_filter << endl;
	*p = 10;  //������� �������������� ����������
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
	ifstream file("window.txt"); // ������� ���� � �������
	string s, find;
	char c;

	while (!file.eof()) {  // ��������� ��� � ��������� �� ������
		file.get(c);
		s.push_back(c);
	}

	file.close(); // ����������� �������

	cout << "������� ����� ��� ������: ";
	cin >> find;

	int pos = s.find(find); // �����

	if (pos == -1)
		cout << "������ �� �������" << endl;
	else
		cout << "������� ����������" << find << "������� ->"<< pos << endl;
	file.close();
}

void delete_inform() {
	ifstream file_zin;
	file_zin.open("window.txt");
	if (!file_zin) {
		cout << "������, ���������� ������� ����: " << endl;
	}
	cout << "������� ������ ������� ����� �������..." << endl;
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
		cout << "������ �� �������..." << endl;
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