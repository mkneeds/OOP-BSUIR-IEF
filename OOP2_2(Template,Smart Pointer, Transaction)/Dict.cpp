#include "Dict.h"

void Dict::addWord() {
	cout <<"Введите слово(На русском)->";
	cin >> word;
	cout << endl;
	cout << "Введите слово(На английском)->";
	cin >> translate;
	addInformation();
}
 
void Dict::getWord() {
	cout << "Введите слово для поиска по словарю(На русском)->" << endl;
	cin >> searchStr;
	searchInformation();
}