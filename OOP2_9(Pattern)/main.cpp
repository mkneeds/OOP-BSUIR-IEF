#include "Building.h"
#include <Windows.h>
#include <memory>
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (1) {
		cout << "\t\tВыберите фабрику: " << endl;
		cout << "\t1. Фабрика" << endl;
		cout << "\t2. Фабрика с париметрам, и фабричный конструктор" << endl;
		cout << "\t3. Полиморфная фабрика" << endl;
		cout << "\t4. Полиморфное копирование" << endl;
		cout << "\t5. Выход" << endl;
		cout << "Ваш выбор:";
		int ch;
		cin >> ch;
		switch (ch) {
		case 1: {
			cout << "\t\t~Меню выбора словаря~" << endl;
			cout << "\t1)Технический словарь" << endl;
			cout << "\t2)Толковый словарь" << endl;
			cout << "\t3)Обычный словарь" << endl;
			cout << "\t4)Назад" << endl;
			cout << "Ваш выбор:";
			int choose;
			cin >> choose;
			Buildings buildingType;
			switch (choose) {
			case 1: buildingType = TECH; break;
			case 2: buildingType = SENS; break;
			case 3: buildingType = TRANS; break;
			case 4: main();
			default: break;
			}
			Building* b = makeBuilding(buildingType);
			bool flag = true;
			while (flag) {
				menu::menu();
				cin.clear();
				switch (checkInterval(1, 5)) {
				case 1: system("cls"); b->addWord(); break;
				case 2: system("cls"); b->printInformation(); break;
				case 3: system("cls"); b->getWord(); break;
				case 4: system("cls"); flag = false; main(); break;
				}
			}
		}break;
		case 2: {
			cout << "Вызов фабрики с параметрами(Толковый словарь)" << endl;;
			cout << "Введите слово на русском языке->" << endl;
			string word;
			cin.ignore();
			getline(cin, word);
			string translate;
			cout << "Введите слово на английском языке->" << endl;
			getline(cin, translate);
			SensibleDict* sens = new SensibleDict(word, translate);
			Building* b = makeBuilding(sens->dictType());
		}break;
		case 3: {
			DesignDict* dict = new MakingDesignTechDict;
			Dict* di = dict->makeDict();
			di->printInformation();
			break;
		}break;
		case 4: {
			unique_ptr<Dict> p(new TechDict);
			p->addWord();
			unique_ptr<Dict> b = p->clone();
			cout << "Копирование прошло успешно" << endl;
		}break;
		case 5: {

		}break;
		}
		
	}

}
