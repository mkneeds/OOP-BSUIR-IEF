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
using namespace std;

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
	string name;
	int year;
public:
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
	vector<SystemSoftware> sys_softs;
	string os;
	string file_manager;
public:
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
		cout << "Введите год создания ПО: " << endl;
		cin >> num;
		obj.setYear(num);
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
		for (int i = 0; i < sys_softs.size(); i++) {
			cout << sys_softs[i].getName() << "|" << sys_softs[i].getYear() << "|" << sys_softs[i].getOs() << "|" << sys_softs[i].getFile_manager() << endl;
		}
	}
};

class InstrumentalSoftware : public virtual Software {
	vector<InstrumentalSoftware> instr_softs;
	string programming_lang;
	string translator; // Трансля́тор — программа или техническое средство, выполняющее трансляцию программы
public:
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
				for (int i = 0; i < instr_softs.size() + 1; i++) {
					cout << instr_softs[i].getName() << "|" << instr_softs[i].getYear() << "|" << instr_softs[i].getProgramming_lang() << "|" << instr_softs[i].getTranslator() << endl;
					throw except;
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
	vector<AppliedSoftware> apl_softs;
	string appointment; // Назначение
public:
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
		obj.setAppointment(s);
		apl_softs.push_back(obj);
	}

	vector<AppliedSoftware> getVector() {
		return apl_softs;
	}

	void print() {
		for (int i = 0; i < apl_softs.size(); i++) {
			cout << apl_softs[i].getName() << "|" << apl_softs[i].getYear() << "|" << apl_softs[i].getAppointment() << endl;
		}
	}
};

void termFunc() {
	cout << "Функция termFunc() вызвана функцией terminate().\n";
	exit(-1);
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
		cout << "Выберите тип программного обеспечения(ПО): " << endl;
		cout << "1. Системное ПО;" << endl;
		cout << "2. Инструментальное ПО;" << endl;
		cout << "3. Прикладное ПО;" << endl;
		cout << "4. Вывод на экран;" << endl;
		cout << "5. Выход." << endl;
		cin >> menuOption;
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
				instr_soft.print();
				apl_soft.print();
				break;
			case 5:
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