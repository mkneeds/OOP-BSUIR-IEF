//Написать программу учета наличия различных транспортных
//средств в автопарке.Разработать абстрактный базовый класс и набор
//дочерних классов содержащий поля с информацией о транспортных
//средствах.Классы должны содержать следующие поля : тип транспортного
//средства, количество мест для пассажиров и данные о водителе.По запросу
//выдавать необходимую информацию о транспортных средствах.
//Использовать конструктор с параметрами, конструктор без параметров,
//конструктор копирования.В класс добавить необходимый набор полей и
//методов(минимум два поля и два метода) на свое усмотрение.
//Предусмотреть метод для записи полученных данных в файл.

#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<locale.h>
#include <windows.h>
#include<fstream>

using namespace std;

bool isSymbolic(int varToCheck);

class foreWeels;
class twoWeels;

class vehicle
{
public:
	virtual void print() = 0;
	virtual void file_write() = 0;
};

class autoParkVehicle :public vehicle
{
protected:
	string type;
	int amountOfSits;
	string driverLicence;
	int engineVolume;
public:
	autoParkVehicle()
	{
		type = "no information";
		amountOfSits = NULL;
		driverLicence = "no information";
	}
	autoParkVehicle(string type, int amountOfSits, string driverLicence, int engineVolume)
	{
		this->type = type;
		this->amountOfSits = amountOfSits;
		this->driverLicence = driverLicence;
		this->engineVolume = engineVolume;
	}
	void print()
	{
		cout << "Тип: " << type << endl;
		cout << "Кол-во сидений: " << amountOfSits << endl;
		cout << "Категория прав: " << driverLicence << endl;
		cout << "Обьем двигателя: " << engineVolume << endl;
	}

	void file_write()
	{
		ofstream file;
		file.open("test.txt", ios::app);
		if (file.is_open())
		{
			file << type << endl << amountOfSits << endl << driverLicence << endl << engineVolume << endl;
		}
		file.close();
	}
};

class twoWeels : public autoParkVehicle
{
protected:
	string weelsAmount;
public:
	void print()
	{
		autoParkVehicle::print();
		cout << weelsAmount << endl;
	}
	twoWeels(string type, int amountOfSits, string driverLicence, int engineVolume) :autoParkVehicle(type, amountOfSits, driverLicence, engineVolume) {
		this->weelsAmount = "Двухколесное ТС";
	}
	void compareAmountOfSits(foreWeels& other);
	void compareEngineVolume(foreWeels& other);

	void file_write()
	{
		autoParkVehicle::file_write();
		ofstream file;
		file.open("test.txt", ios::app);
		if (file.is_open())
		{
			file << weelsAmount << endl;
		}
		file.close();
	}
};

class foreWeels : public autoParkVehicle
{
protected:
	string weelsAmount;
public:
	void print() {
		autoParkVehicle::print();
		cout << weelsAmount << endl;
	}
	foreWeels(string type, int amountOfSits, string driverLicence, int engineVolume) :autoParkVehicle(type, amountOfSits, driverLicence, engineVolume) {
		this->weelsAmount = "Четырехколесное ТС";
	}
	friend void twoWeels::compareAmountOfSits(foreWeels& other);
	friend void twoWeels::compareEngineVolume(foreWeels& other);

	void file_write()
	{
		autoParkVehicle::file_write();
		ofstream file;
		file.open("test.txt", ios::app);
		if (file.is_open())
		{
			file << weelsAmount << endl;
		}
		file.close();
	}
};

int main()
{
	SetConsoleCP(1251);
	setlocale(LC_ALL, "rus");
	string type;
	int amountOfSits, engineVolume;
	string driverLicence;

	vehicle* mashine[2];

	cout << "Введите тип четырехколесного ТС: " << endl;
	cin >> type;
	for (;;) {
		cout << "Введите  кол-во сидений: " << endl;
		cin >> amountOfSits;
		if (isSymbolic(amountOfSits) == false) break;
	}
	cout << "Введите  категорию прав: " << endl;
	cin >> driverLicence;
	for (;;) {
		cout << "Введите объем двигателя: " << endl;
		cin >> engineVolume;
		if (isSymbolic(amountOfSits) == false) break;
	}
	twoWeels moto(type, amountOfSits, driverLicence, engineVolume);

	cout << "Введите тип двухколесного ТС: " << endl;
	cin >> type;
	for (;;) {
		cout << "Введите  кол-во сидений: " << endl;
		cin >> amountOfSits;
		if (isSymbolic(amountOfSits) == false) break;
	}
	cout << "Введите  категорию прав: " << endl;
	cin >> driverLicence;
	for (;;) {
		cout << "Введите объем двигателя: " << endl;
		cin >> engineVolume;
		if (isSymbolic(amountOfSits) == false) break;
	}
	foreWeels cars(type, amountOfSits, driverLicence, engineVolume);

	mashine[0] = &moto;
	mashine[1] = &cars;

	for (int i = 0; i < 2; i++)
	{
		mashine[i]->print();
		cout << endl;
	}

	moto.compareAmountOfSits(cars);
	moto.compareEngineVolume(cars);
	for (int i = 0; i < 2; i++)
	{
		mashine[i]->file_write();
	}
}

void twoWeels::compareAmountOfSits(foreWeels& other)
{
	if (this->amountOfSits == other.amountOfSits) cout << "Кол-во сидений равно" << endl;
	else if (this->amountOfSits > other.amountOfSits) cout << "Кол-во сидений обьекта " << this->type << " больше" << endl;
	else cout << "Кол-во сидений обьекта " << other.type << " больше" << endl;
}

void twoWeels::compareEngineVolume(foreWeels& other)
{
	if (this->engineVolume == other.engineVolume) cout << "Объемы двигателей равен" << endl;
	else if (this->engineVolume > other.engineVolume) cout << "Объем двигателя обьекта " << this->type << " больше" << endl;
	else cout << "Объем двигателя обьекта " << other.type << " больше" << endl;
}

bool isSymbolic(int varToCheck) // Проверка на символ
{
	bool returnVar = false;
	if (!cin) {
		cout << "\nВводите только цифры!\n" << endl;
		cin.clear(); //сбрасывает флаги ошибок,
		while (cin.get() != '\n'); //возвращает последний символ из потока.
		returnVar = true;
	}
	return returnVar;
}

