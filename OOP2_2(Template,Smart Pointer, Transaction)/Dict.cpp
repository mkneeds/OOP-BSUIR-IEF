#include "Dict.h"

void Dict::addWord() {
	cout <<"������� �����(�� �������)->";
	cin >> word;
	cout << endl;
	cout << "������� �����(�� ����������)->";
	cin >> translate;
	addInformation();
}
 
void Dict::getWord() {
	cout << "������� ����� ��� ������ �� �������(�� �������)->" << endl;
	cin >> searchStr;
	searchInformation();
}