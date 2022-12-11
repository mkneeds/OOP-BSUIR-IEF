#pragma once
#include "Dict.h"


using namespace std;

enum Buildings{SENS,TECH,TRANS};


class Building : public Dict
{
public:
	virtual unique_ptr<Dict> clone() = 0;
	virtual void addWord(){};
	virtual void getWord(){};
	virtual void setDate(string word, string translate){};
	virtual void printInformation(){};
	virtual void setFileStore(string name) { store.name = name; }
	virtual ~Building() {}
	Building(){}
	virtual Buildings dictType() = 0;
	inline Building* makeBuilding(Building* type);

};

class SensibleDict : public Building
{
public:
	unique_ptr<Dict> clone() { return  unique_ptr<Dict>(new SensibleDict(*this)); }
	SensibleDict() {
		cout << "Был вызван толковый словарь" << endl;
	};
	SensibleDict(string word, string translate) {
		setFileStore("Sensible.txt");
		store.word = word;
		store.translate = translate;
		store.addInformation();
		system("cls");
		store.printInformation();
		system("pause");
		system("cls");
	}
	void addWord() {
		setFileStore("Sensible.txt");
		cout << "Введите слово(На английском)->";
		getline(cin, store.word);
		cout << endl;
		cout << "Введите значение слова->";
		getline(cin, store.translate);
		store.addInformation();
	}
	Buildings dictType() { return SENS; }
	void getWord() {
		setFileStore("Sensible.txt");
		cout << "Введите слово для поиска по словарю(На русском)->" << endl;
		cin >> store.searchStr;
		store.searchInformation();
	}
	void setDate(string date, string translate) {
		this->date = date;
		this->translates = translate;
	}
	string getDate() {
		string str = date + " " + translates;
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
			cout << "Неккоректный ввод. Повторите попытку->";
			value = checkInt();
		}
		return value;
	}
void  printInformation() {
		setFileStore("Sensible.txt");
		store.printTolk();
	}
};
class TechDict :public Container, public Building
{
public:
	TechDict() {
	
		cout << "Был вызван технический словарь" << endl;
	}
	unique_ptr<Dict> clone() { return  unique_ptr<Dict>(new TechDict(*this)); }
	Buildings dictType() { return TECH; }
	void addWord() {
		setFileStore("Trans.txt");
		cout << "Введите слово(На русском)->";
		cin.ignore();
		getline(cin, store.word);
		cout << endl;
		cout << "Введите слово(На английском)->";
		getline(cin, store.translate);
		store.addInformation();
	}

	void getWord() {
		setFileStore("Trans.txt");
		cout << "Введите слово для поиска по словарю(На русском)->" << endl;
		cin >> store.searchStr;
		store.searchInformation();
	}
	void setDate(string date, string translate) {
		this->date = date;
		this->translates = translate;
	}
	string getDate() {
		string str = date + " " + translates;
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
			cout << "Неккоректный ввод. Повторите попытку->";
			value = checkInt();
		}
		return value;
	}
	void  printInformation() {
		setFileStore("Tech.txt");
		store.printInformation();
	}
};
class TransDict :public Container , public Building
{
public:
	unique_ptr<Dict> clone() { return  unique_ptr<Dict>(new TransDict(*this)); }
	TransDict() {
		cout << "Был вызван обычный словарь..." << endl;
	}
	Buildings dictType() { return TRANS; }
	void addWord() {
		setFileStore("Trans.txt");
		cout << "Введите слово(На русском)->";
		getline(cin, store.word);
		cout << endl;
		cout << "Введите слово(На английском)->";
		getline(cin, store.translate);
		store.addInformation();
	}

	void getWord() {
		setFileStore("Trans.txt");
		cout << "Введите слово для поиска по словарю(На русском)->" << endl;
		cin >> store.searchStr;
		store.searchInformation();
	}
	void setDate(string date, string translate) {
		this->date = date;
		this->translates = translate;
	}
	string getDate() {
		string str = date + " " + translates;
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
			cout << "Неккоректный ввод. Повторите попытку->";
			value = checkInt();
		}
		return value;
	}
	void  printInformation() {
		setFileStore("Trans.txt");
		store.printInformation();
	}
};

inline Building* makeBuilding(Buildings type) {
	switch (type)
	{
	case SENS: return new SensibleDict();
	case TECH: return new  TechDict();
	case TRANS: return new TransDict();
	default:
		break;
	}
}
Building* Building::makeBuilding(Building* type) {
	switch (type->dictType())
	{
	case SENS: return new SensibleDict();
	case TECH: return new  TechDict();
	case TRANS: return new TransDict();
	default:
		break;
	}
}

class DesignDict {
public:
	virtual Dict* makeDict() = 0;
	virtual unique_ptr<DesignDict> clone() = 0;
};

class MakingDesignTechDict : public DesignDict {
public:
	TechDict* makeDict() { return new TechDict; }
	unique_ptr<DesignDict>clone() { return unique_ptr<DesignDict>(new MakingDesignTechDict(*this)); }
};