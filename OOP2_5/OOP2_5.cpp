/*
Разработать набор классов (минимум 5 классов, связи между
классами: агрегация, композиция, наследование) по предметной области
«Программное обеспечение компьютера». Функционал программы
должен позволить собрать данные о необходимом программном
обеспечении. Сгенерировать минимум пять типов исключительных
ситуаций. Реализовать перенаправление исключительных ситуаций.
|Сгенерировать минимум одну исключительную ситуацию с оператором new.|
Создать исключительную ситуацию в конструкторе и продемонстрировать
вызов конструкторов и деструкторов. Задать собственную функцию
завершения. Создать собственный (пользовательский) класс исключения,
сгенерировать исключение этого типа и обработать его.
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdio>
#include "Header.h"
#include <algorithm>

using namespace std;

vector<string> cont;

class MyException : public exception {
	int dataState;
public:
	MyException(const char* msg, int dataState) :exception(msg) {
		this->dataState = dataState;
	}
	int getDataState() {
		return dataState;
	}
};

class Software {
	int year;
public:
	string name;
	Software() {
		this->name = "noname";
		cout << "Конструктор Software" << endl;
	};
	Software(string name) {
		this->name = name;
	}
	~Software() {
		cout << "Деструктор Software" << endl;
	};

	void setName(string name) {
		this->name = name;
	}

	string getName() {
		return name;
	}

	void setYear(int year) {
		this->year = year;
	}

	int getYear() {
		return year;
	}

};

class SystemSoftware : public virtual Software {
	string os;
	string file_manager;
public:
	vector<SystemSoftware> sys_softs;
	SystemSoftware() {
		cout << "Констр. класса SystemSoftware" << endl;
		this->os = "noname";
		this->file_manager = "noname";
	};
	SystemSoftware(string os, string file_manager) {
		cout << "Констр. c параметрами класса SystemSoftware" << endl;
		throw 1;
		this->os = os;
		this->file_manager = file_manager;
	}
	~SystemSoftware() {
		cout << "Дестр. класса SystemSoftware" << endl;
	};

	void setOs(string os) {
		this->os = os;
	}

	string getOs() {
		return os;
	}

	void setFile_manager(string file_manager) {
		this->file_manager = file_manager;
	}

	string getFile_manager() {
		return file_manager;
	}

	void add() {
		int num;
		string s;
		SystemSoftware obj;
		cout << "Введите название ПО: " << endl;
		cin.ignore();
		getline(cin, s);
		obj.setName(s);
		while (true) {
			cout << "Введите год создания ПО: " << endl;
			try {
				cin >> num;
				if (num <= 1981) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw MyException("В это время ЭВМ ещё не было. Повторите ввод\n", num);
				}
				obj.setYear(num);
				break;
			}
			catch (MyException& ex) {
				cout << "Состояние ввода: " << ex.getDataState() << endl;
				cout << ex.what() << endl;
				continue;
			};
		}
		cout << "Введите название операционной системы: " << endl;
		cin.ignore();
		getline(cin, s);
		obj.setOs(s);
		cout << "Введите название файлового менеджера: " << endl;
		getline(cin, s);
		obj.setFile_manager(s);
		sys_softs.push_back(obj);
	}

	/*vector<SystemSoftware> getVector() {
		return sys_softs;
	}
	*/

	void print() {
		if (sys_softs.empty()) {
			cout << "Добавьте что нибудь чтобы вывести 'Системное ПО'" << endl;
		}
		else {
			ShowTable t;
			t.add("Название");
			t.add("Год Создания");
			t.add("Система");
			t.add("Файловый менеджер");
			t.endOfRow();
			for (int i = 0; i < sys_softs.size(); i++) {
				t.add(sys_softs[i].getName());
				t.add(to_string(sys_softs[i].getYear()));
				t.add(sys_softs[i].getOs());
				t.add(sys_softs[i].getFile_manager());
				t.endOfRow();
			}
			cout << "Системное ПО" << endl;
			cout << t;
		}
	}
};

class InstrumentalSoftware : public virtual Software {
	string programming_lang;
	string translator; // Трансля́тор — программа или техническое средство, выполняющее трансляцию программы
public:
	vector<InstrumentalSoftware> instr_softs;
	InstrumentalSoftware() {
		this->programming_lang = "noname";
		this->translator = "noname";
	};
	InstrumentalSoftware(string programming_lang, string translator) {
		this->programming_lang = programming_lang;
		this->translator = translator;
	}
	~InstrumentalSoftware() {};
	void setProgramming_lang(string programming_lang) {
		this->programming_lang = programming_lang;
	}

	string getProgramming_lang() {
		return programming_lang;
	}

	void setTranslator(string translator) {
		this->translator = translator;
	}

	string getTranslator() {
		return translator;
	}

	void add() {
		int num;
		string s;
		InstrumentalSoftware obj;
		cout << "Введите название ПО: " << endl;
		cin.ignore();
		getline(cin, s);
		obj.setName(s);
		while (true) {
			try {
				cout << "Введите год создания ПО: " << endl;
				cin >> num;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw 1;
				}
				if (num <= 1981) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw runtime_error("В это время ЭВМ ещё не было. Повторите ввод\n");
				}
				if (num >= 2023) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw "Error";
				}
				obj.setYear(num);
				break;
			}
			catch (runtime_error err) {
				cout << err.what() << endl;
				continue;
			}
			catch (const char* message) {
				cout << "Сейчас 2022 год вообще-то. Повторите ввод" << endl;
				throw;
				continue;
			}
			catch (int) {
				cout << "Ошибка ввода данных. Вы ввели не int" << endl;
				continue;
			}
			catch (...) {
				cout << "Абсолютный обработчик. Что-то пошло не так! Повторите ввод." << endl;
			}
		}
		cout << "Введите название языка программирования: " << endl;
		cin.ignore();
		getline(cin, s);
		obj.setProgramming_lang(s);
		cout << "Введите название транслятора: " << endl;
		getline(cin, s);
		obj.setTranslator(s);
		instr_softs.push_back(obj);
	}

	/*vector<InstrumentalSoftware> getVector() {
		return instr_softs;
	} */

	void print() {
		while (true) {
			bad_alloc except;
			try {
				if (instr_softs.empty()) {
					cout << "Добавьте что нибудь чтобы вывести 'Инструментальное ПО'" << endl;
					break;
				}
				else {
					ShowTable t;
					t.add("Название");
					t.add("Год Создания");
					t.add("Язык Программирования");
					t.add("Транслятор");
					t.endOfRow();
					for (int i = 0; i < instr_softs.size(); i++) {
						t.add(instr_softs[i].getName());
						t.add(to_string(instr_softs[i].getYear()));
						t.add(instr_softs[i].getProgramming_lang());
						t.add(instr_softs[i].getTranslator());
						t.endOfRow();

					}
					cout << "Инструментальное ПО" << endl;
					cout << t;
				}
				break;
			}
			catch (bad_alloc exept) {
				cout << "Возникло исключение " << exept.what() << endl;
				break;
			}
		}
	}
};

class AppliedSoftware : public virtual Software {
	string appointment; // Назначение
public:
	vector<AppliedSoftware> apl_softs;
	AppliedSoftware() { this->appointment = "noname"; };
	AppliedSoftware(string appointment) {
		this->appointment = appointment;
	}
	~AppliedSoftware() {};

	void setAppointment(string appointment) {
		this->appointment = appointment;
	}

	string getAppointment() {
		return appointment;
	}

	void add() {
		int num;
		string s;
		AppliedSoftware obj;
		cout << "Введите название ПО: " << endl;
		cin.ignore();
		getline(cin, s);
		obj.setName(s);
		while (true) {
			try {
				cout << "Введите год создания ПО: " << endl;
				cin >> num;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw 1;
				}
				if (num <= 1981) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw runtime_error("В это время ЭВМ ещё не было. Повторите ввод\n");
				}
				if (num >= 2023) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw "Error";
				}
				obj.setYear(num);
				break;
			}
			catch (runtime_error err) {
				cout << err.what() << endl;
				continue;
			}
			catch (const char* message) {
				cout << "Сейчас 2022 год вообще-то. Повторите ввод" << endl;
				throw;
				continue;
			}
			catch (int) {
				cout << "Ошибка ввода данных. Вы ввели не int" << endl;
				continue;
			}
			catch (...) {
				cout << "Абсолютный обработчик. Что-то пошло не так! Повторите ввод." << endl;
			}
		}
		cout << "Введите назначение ПО: " << endl;
		cin.ignore();
		getline(cin, s);
		while (!cin.good()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Повторите попытку: ";
			getline(cin, s);
		}
		obj.setAppointment(s);
		apl_softs.push_back(obj);
	}

	vector<AppliedSoftware> getVector() {
		return apl_softs;
	}

	void print() {
		if (apl_softs.empty()) {
			cout << "Добавьте что-нибудь в пользовательское по, чтобы вывести" << endl;
		}
		else {
			ShowTable t;
			t.add("Название");
			t.add("Год Создания");
			t.add("Назначение");
			t.endOfRow();
			for (int i = 0; i < apl_softs.size(); i++) {
				t.add(apl_softs[i].getName());
				t.add(to_string(apl_softs[i].getYear()));
				t.add(apl_softs[i].getAppointment());
				t.endOfRow();
			}
			cout << t;
		}
		
	}
};

void termFunc() {
	cout << "Функция termFunc() вызвана функцией terminate().\n";
	exit(-1);
}

void menu() {
	cout.width(50);
	cout.setf(ios::right);
	cout << "Выберите тип программного обеспечения(ПО): " << endl;
	cout.unsetf(ios::right);
	cout << setfill('|') << setw(17) <<right<< "1. Системное ПО;" << endl;
	cout << setfill('|') << setw(24) << right << "2. Инструментальное ПО;" << endl;
	cout << setfill('|') << setw(18) << right << "3. Прикладное ПО;" << endl;
	cout << setfill('|') << setw(33) << right << "4. Вывод на экран(Cистемное ПО);" << endl;
	cout << setfill('|') << setw(40) <<  right << "5. Вывод на экран(Инструментальное ПО);" << endl;
	cout << setfill('|') << setw(34) <<  right << "6. Вывод на экран(Прикладное ПО);" << endl;
	cout << setfill('|') << setw(28) << right << "7. Сортировать по названию." << endl;
	cout << setfill('|') << setw(24) << right << "8. Редактировать запись" << endl;
	cout << setfill('|') << setw(10) << right << "9. Выход." << endl;
	cout << setfill(' ');
}

int main() {
	system("chcp 1251");
	system("cls");
	set_terminate(termFunc);
	SystemSoftware sys_soft;
	InstrumentalSoftware instr_soft;
	AppliedSoftware apl_soft;
	int menuOption;
	while (true) {
		system("pause");
		system("cls");
		menu();
		cin >> menuOption;
		if (cin.eof()) {
			cout << "Что-то пошло не так..." << endl;
			cin >> menuOption;
		}
		try {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw invalid_argument("Error");
			}
			switch (menuOption)
			{
			case 1:
				try {
					sys_soft.add();
				}
				catch (int) { cout << "исключение из конструктора" << endl; }
				break;
			case 2:
				instr_soft.add();
				break;
			case 3:
				try {
					apl_soft.add();
				}
				catch (const char* message) {
					cout << "Второй обработчик, который перенаправил" << endl;
				}
				break;
			case 4:
				sys_soft.print();
				break;
			case 5:
				instr_soft.print();
				break;
			case 6:
				apl_soft.print();
				break;
			case 7: {
				if (!sys_soft.sys_softs.empty()) {
					sort(sys_soft.sys_softs.begin(), sys_soft.sys_softs.end(),[](const SystemSoftware a, const SystemSoftware b) -> bool
						{
							return a.name < b.name;
						});
				}
				system("cls");
			
				sys_soft.print();
				system("pause");
				if (!instr_soft.instr_softs.empty()) {
					sort(instr_soft.instr_softs.begin(), instr_soft.instr_softs.end(),[](const InstrumentalSoftware a, const InstrumentalSoftware b) -> bool
						{
							return a.name < b.name;
						});
				}
				system("cls");
				instr_soft.print();
				system("pause");
				if (!apl_soft.apl_softs.empty()) {
					sort(apl_soft.apl_softs.begin(), apl_soft.apl_softs.end(), [](const AppliedSoftware a, const AppliedSoftware b) -> bool
						{
							return a.name < b.name;
						});
				}
				system("cls");
				apl_soft.print();
				system("pause");

			}break;
			case 8: {
				system("cls");
				cout << "\t\tМеню редактирования" << endl;
				cout << "\t1.System" << endl;
				cout << "\t2.Applied" << endl;
				cout << "\t3.Instrumental" << endl;
				cout << "Ваш выбор:";
				int choise;
				cin.setf(ios::skipws);
				cin >> choise;
				switch (choise) {
				case 1: {
					cout << "Введите название которое хотите изменить" << endl;
					string name;
					cin >> name;
					cout << "Введите новое название" << endl;
					string new_name;
					cin.ignore();
					getline(cin, new_name);
					for (int i = 0; i < sys_soft.sys_softs.size(); i++) {
						if (strcmp(sys_soft.sys_softs[i].name.c_str(), name.c_str()) == 0) {
							sys_soft.sys_softs[i].name = new_name;
						}
						else {
							cout << "Ничего не найдено" << endl;
						}
					}
				}break;
				case 2: {
					cout << "Введите название которое хотите изменить" << endl;
					string name;
					cin >> name;
					cout << "Введите новое название" << endl;
					string new_name;
					cin.ignore();
					getline(cin, new_name);
					for (int i = 0; i < apl_soft.apl_softs.size(); i++) {
						if (strcmp(apl_soft.apl_softs[i].name.c_str(), name.c_str()) == 0) {
							apl_soft.apl_softs[i].name = new_name;
						}
						else {
							cout << "Ничего не найдено" << endl;
						}
					}
				}break;
				case 3: {
					cout << "Введите название которое хотите изменить" << endl;
					string name;
					cin >> name;
					cout << "Введите новое название" << endl;
					string new_name;
					cin.ignore();
					getline(cin, new_name);
					for (int i = 0; i < instr_soft.instr_softs.size(); i++) {
						if (strcmp(instr_soft.instr_softs[i].name.c_str(), name.c_str()) == 0) {
							instr_soft.instr_softs[i].name = new_name;
						}
						else {
							cout << "Ничего не найдено" << endl;
						}
					}
				}break;
				}

			}break;
			case 9:
				termFunc();
				break;
			default:
				cout << "Такого пункта меню не существует. Повторите ввод." << endl;
				break;
			};
		}
		catch (invalid_argument e) {
			cout << "Ошибка ввода" << endl;
			continue;
		}
	}
	return 0;
}
