#include "Container.h"
#include "ShowTable.h"

void Container::writeEndFile() {
	ofstream fout("data.txt", ios::app);
	for (int i = 0; word[i]; i++)
		if (word[i] == ' ')
			word[i] = '.';
	for (int i = 0; translate[i]; i++)
		if (translate[i] == ' ')
			translate[i] = '.';
	fout << key << " " << word << " " << translate;
	fout << endl;
	fout.close();
}

int Container::uploadInformation() {
	ifstream fin("data.txt", ios::in);
	string line;
	if (!fin) {
		cout << "Нет доступа к файлу,обратитесь к админу///";
	}
	else {
		while (getline(fin, line)) {
			key++;
		}
	}
	fin.close();
	return key;
}

void Container::addInformation() {
	uploadInformation();
	writeEndFile();
}

void Container::printInformation() {
	ifstream fout("data.txt", ios::in);
	if (!fout) {
		cout << "Нет доступа к файлу,обратитесь к админу///";
	}
	else {
		ShowTable t('-', '|', '+');
		t.add("Порядковый номер");
		t.add("Слово на русском");
		t.add("Перевод");
		t.endOfRow();
		while (fout >> key_co >> word >> translate) {
			for (int i = 0; word[i]; i++)
				if (word[i] == '.')
					word[i] = ' ';
			for (int i = 0; translate[i]; i++)
				if (translate[i] == '.')
					translate[i] = ' ';
			t.add(key_co);
			t.add(word);
			t.add(translate);
			t.endOfRow();
		}
		cout << t;
		fout.close();
	}
}
void del_remove(string translate,ShowTable&t) {
	for (int i = 0; translate[i]; i++)
		if (translate[i] == '.')
			translate[i] = ' ';
	t.add(translate);
}
void Container::searchInformation() {
	ShowTable t('-', '|', '+');
	t.add("Порядковый номер");
	t.add("Слово на русском");
	t.add("Перевод");
	t.endOfRow();
	ifstream fout("data.txt", ios::in);
	if (!fout) {
		cout << "Нет доступа к файлу,обратитесь к админу///";
	}
	else{
		string str;
		while (getline(fout, str)) {
			if (str.find(searchStr) != std::string::npos) {
				istringstream ist(str);
				for (std::string word; ist >> word; del_remove(word,t));
				t.endOfRow();
				cout << t;
			}
			}
		}

	}