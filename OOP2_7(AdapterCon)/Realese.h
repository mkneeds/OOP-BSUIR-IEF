#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <stack>
#include <vector>
#include <locale.h>
#include <iomanip>
using namespace std;

class Item {
	string item;
	int amount;
	int numOfItem;
public:
	Item(string item = "Null", int amount = 0, int numOfItem = 0)
		:item(item), amount(amount), numOfItem(numOfItem) {}
	void setItem(string item) {
		this->item = item;
	}
	void setAmount(int amount) {
		this->amount = amount;
	}
	void setNumOfItem(int numOfItem) {
		this->numOfItem = numOfItem;
	}
	string getItem() {
		return item;
	}
	int getAmount() {
		return amount;
	}
	int getNumOfItem() {
		return numOfItem;
	}

	void addItem() {
		cout << "������� ����� ������: ";
		cin >> this->numOfItem;
		cout << "������� �������� ������: ";
		cin >> this->item;
		cout << "������� ���-�� ������: ";
		cin >> this->amount;
	}

	friend ostream& operator<<(ostream& os, Item& obj) {
		os << "����� ������: " << obj.getNumOfItem() << endl;
		os << "�������� ������: " << obj.getItem() << endl;
		os << "���-��: " << obj.getAmount() << endl;
		os << "----------------------------------------------------" << endl;
		return os;
	}

	static void print(stack<Item> item) {
		while (!item.empty()) {
			cout << item.top();
			item.pop();
		}
	}

	friend bool operator< (const Item& st1, const Item& st2) {
		return st1.numOfItem > st2.numOfItem;
	}
	friend bool operator> (const Item& st1, const Item& st2) {
		return st1.numOfItem < st2.numOfItem;
	}

	Item& operator=(const Item& obj) {
		if (this != &obj) {
			this->numOfItem = obj.numOfItem;
			this->item = obj.item;
			this->amount = obj.amount;
		}
		return *this;
	}
	~Item() {}
};

class Category {
	string name;
	string conditions;
public:
	string getName() {
		return name;
	}
	string getConditions() {
		return conditions;
	}
	void setName(string name) {
		this->name = name;
	}
	void setConditions(string conditions) {
		this->conditions = conditions;
	}
	void addCategory() {
		cout << "������� �������� ��������� �������: ";
		cin >> this->name;
		cout << "������� ������� ��������: ";
		cin >> this->conditions;
	}
	void print() {
		cout << endl << "+==================================================+"
			<< endl << "�������� ���������: " << this->name << endl;
		cout << "������� ��������: " << this->conditions << endl;
		cout << "+==================================================+" << endl;
	}
	friend ostream& operator<<(ostream& os, Category& obj) {
		os << "�������� ���������: " << obj.getName() << endl;
		os << "������� ��������: " << obj.getConditions() << endl;
		return os;
	}
	Category& operator=(const Category& obj) {
		if (this != &obj) {
			this->name = obj.name;
			this->conditions = obj.conditions;
		}
		return *this;
	}
};

class Shop {
	Category category;
	stack<Item> items;
public:
	std::stack<Item> getItem() {
		return items;
	}
	Category getCategory() {
		return category;
	}
	void putItem(Item& item) {
		this->items.push(item);
	}
	void pop() {
		this->items.pop();
	}
	void setCategory(Category category) {
		this->category = category;
	}
	friend std::ostream& operator<<(std::ostream& os, Shop obj) {
		os << std::endl << "�������� ���������: " << obj.getCategory().getName() << std::endl;
		os << "������� ��������: " << obj.getCategory().getConditions() << std::endl;
		while (!obj.getItem().empty()) {
			os << obj.getItem().top() << std::endl;
			obj.getItem().pop();
		}
		return os;
	}
	void clear() {
		this->items.pop();
	}
	static void print(std::queue<Shop> shop) {
		while (!shop.empty()) {
			Shop _shop = shop.front();
			_shop.getCategory().print();
			Item::print(_shop.getItem());
			shop.pop();
		}
	}

	static void print(std::priority_queue<Shop> shop) {
		while (!shop.empty()) {
			Shop _shop = shop.top();
			_shop.getCategory().print();
			Item::print(_shop.getItem());
			shop.pop();
		}
	}
};

int input(int a, int b) {
	int n;
	while (!(cin >> n) || (cin.peek() != '\n') || (n < a || n > b)) {
		cin.clear();
		while (cin.get() != '\n');
		cout << endl << "������ �����, ��������� �������:" << endl << endl;
	}
	return n;
}

int menu()
{
	int choice;
	cout << setw(25) << "����: " << endl;
	cout << "1. ����������� ������" << endl;
	cout << "2. �������� ���������" << endl;
	cout << "3. �������� �����" << endl;
	cout << "4. ������� ��������� �����" << endl;
	cout << "5. �������� ���������� � ������� � ��������" << endl;
	cout << "6. �������� ��������� ���������� ����������" << endl;
	cout << "7. ����� �� ���������" << endl;
	choice = input(1, 7);
	system("cls");
	return choice;
}

int main(int argc, char* argv[]) {
	priority_queue<Shop, vector<Shop>, less<vector<Shop>::value_type>> shop;
	system("chcp 1251");
	system("cls");
	//queue<Shop> shop;
	Shop _shop;
	Item item;
	Category category;
	int choice = 0;
	while (choice != 7) {
		choice = menu();
		switch (choice) {
		case 1:
			Shop::print(shop);
			system("pause");
			break;
		case 2:
			category.addCategory();
			_shop.setCategory(category);
			shop.push(_shop);
			system("pause");
			break;
		case 3:
			item.addItem();
			//shop.back().putItem(item);
			system("pause");
			break;
		case 4:
			//shop.front().clear();
			system("pause");
			break;
		case 5:
			while (!shop.empty()) {
				shop.pop();
			}
			system("pause");
			break;
		case 6:
			shop.pop();
			system("pause");
			break;
		case 7:
			exit(0);
			break;
		}
	}
	return 0;
}