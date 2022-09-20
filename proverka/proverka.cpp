/*Создать класс Array(массив), в котором реализовать методы для
работы с одномерными массивами: получить пересечение и объединение
элементов массивов. Память под массивы выделять в конструкторе
динамически. Использовать конструктор с параметрами, конструктор без
параметров, конструктор копирования. Деструктор должен освобождать
динамическую память, выделенную под массивы. В класс добавить
необходимый набор полей и методов (минимум два поля и два метода) на
свое усмотрение. Предусмотреть метод для записи полученных данных в
файл.*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
using namespace std;

extern int size_of_array = 0;


class Array
{
public:

	int* mas;
	int size;

	Array(int size);
	Array();
	Array(const Array& other);
	~Array();
	void vvod(int size);
	void vivod();
	void peresechenie(Array& other);
	void obedinenie(Array& other);
	void write_file(int size);
	void read_file();
};

Array::Array()
{
	this->size = 3;
	mas = new int[3];
	vvod(size);
	write_file(size);
}

Array::Array(int size)
{

	this->size = size;
	mas = new int[size];
	vvod(size);
}

Array::Array(const Array& other)
{
	this->size = other.size;
	this->mas = new int[other.size];
	for (int i = 0; i < other.size; i++)
	{
		this->mas[i] = other.mas[i];
	}
}

Array::~Array()
{
	delete[] mas;
}

void Array::peresechenie(Array& other)
{
	int k = 0, * mas_1, size_mas_1;
	if (this->size > other.size)
	{
		mas_1 = new int[this->size];
	}
	else
	{
		mas_1 = new int[other.size];
	}
	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < other.size; j++)
		{
			if (this->mas[i] == other.mas[j])
			{
				mas_1[k] = other.mas[j];
				k++;
			}
		}
	}
	cout << "\nresultat peresecheniya:" << " ";
	for (int i = 0; i < k; i++)
	{
		cout << mas_1[i] << " ";
	}
	cout << endl;
}

void Array::obedinenie(Array& other)
{
	int* mas_2, size_mas_2, j = 0;
	size_mas_2 = this->size + other.size;
	mas_2 = new int[size_mas_2];
	for (int i = 0; i < this->size; i++)
	{
		mas_2[j] = this->mas[i];
		j++;
	}
	for (int i = 0; i < other.size; i++)
	{
		mas_2[j] = other.mas[i];
		j++;
	}
	cout << "resultat obedineniya:" << " ";
	for (int i = 0; i < size_mas_2; i++)
	{
		cout << mas_2[i] << " ";
	}
}

void Array::vivod()
{
	for (int i = 0; i < size; i++)
	{
		cout << mas[i] << " ";
	}
}

void Array::vvod(int size)
{
	int chek;
	for (int i = 0; i < size; i++)
	{
		cout << "vvedite " << i + 1 << " element massiva" << endl;
		cin >> chek;
		if (!cin) {
			cout << "vvodite tilko chisla\n" << endl;
			cin.clear();
			while (cin.get() != '\n');
			i--;
		}
		else mas[i] = chek;

	}
}

void Array::write_file(int size)
{
	ofstream f;
	f.open("test.txt");
	if (!f.is_open())
	{
		cout << "Ошибка создания файла" << endl;
	}
	else
	{
		for (int i = 0; i < this->size; i++)
		{
			f << this->mas[i];
		}
	}
	f.close();
	cout << "\nmassiv zapisan v fail" << endl;
}

void Array::read_file()
{
	ifstream f;
	f.open("test.txt");
	if (!f.is_open())
	{
		cout << "nevozmojno otkrit fail" << endl;
	}
	else
	{
		string str;
		getline(f, str);
		cout << "\nprochitano iz faila:" << str << endl;
	}
}



void vvod_size() // размер первого массива
{
	cout << "vvedite razmer massiva 1(razmer >0):" << endl;
	cin >> size_of_array;
	if (!cin) {
		cout << "vvodite tilko chisla\n" << endl;
		cin.clear();
		while (cin.get() != '\n');
		vvod_size();
	}
	else if (size_of_array <= 0) { vvod_size(); }
}

void main()
{
	vvod_size();
	Array a(size_of_array);
	a.vivod();
	cout << "\n\nvvod massiva 2 (3 elementa po umolchaniu):\n" << endl;
	Array b;
	b.vivod();
	cout << "\n\nskopirovan massiv 1:" << " ";
	Array c(a);
	c.vivod();
	a.peresechenie(b);
	a.obedinenie(b);
	b.read_file();
}