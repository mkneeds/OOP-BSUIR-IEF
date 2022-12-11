#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include "ShowTable.h"
#include <queue>
#include <stack>

using namespace std;

class Shop { //Абстрактный класс
public:
	virtual void add_product() {};
	virtual void add_map() {};
	virtual void print_shop() {};
	virtual void print_map() {};
	virtual void load_from_file() {};
};


class OnlineShop : public Shop
{
public:
	OnlineShop() {}
	OnlineShop(string type, int id, string name, float price, int qua) : type(type), id_product(id), name(name), price(price), quantity(qua) {}
private:
	int id_product = 0;
	int quantity = 0;
	float price = 0;
	const string name_file = "Product.txt";
	const string map_file = "Type.txt";
	string type;
	string name;
	int schet = 0;
private:
	ShowTable label;
	vector<OnlineShop> arr_product;
	map<int, string> arr_type;
	queue <string> que;
	stack<int> stac;
	priority_queue<string>prior;
public:
	void print_shop();
	void add_product();
	void add_map();
	void sort_product();
	void edit_product();
	void del_product();
	void print_map();
	void choose_type(int key);
	void buy_product(int balance);
	int get_schet() { return schet; }
	void add_people();
	void write_end_file_q(string name, string number,string prior);
	void print_que();
private:
	void write_end_file();
	void write_end_file_type();
	void load_from_file(vector<OnlineShop>& v);
	void load_from_file(map<int, string>& arr_type);
	void upload_id();
private:
	friend istream& operator>>(istream& stream, OnlineShop& v) {
		stream >> v.id_product;
		stream >> v.type;
		stream >> v.name;
		stream >> v.price;
		stream >> v.quantity;
		return stream;
	}

	friend ostream& operator<<(ostream& stream, const OnlineShop& v) {
		stream << v.id_product << " " << v.type << " " << v.name << " " << v.price << " " << v.quantity;
		return stream;
	}
	
	OnlineShop& operator=(const OnlineShop&) = default;

	class comp_data {
		int what;
		bool compare(class OnlineShop* f, class OnlineShop* s) {
			switch (abs(what)) {
			case 1: return f->id_product < s->id_product; break;
			case 2: return f->price < s->price; break;
			case 3: return f->quantity < s->quantity; break;
			default: return false;
			}
		}
	public:
		comp_data(int what) : what(what) {}
		bool operator()(class OnlineShop* f, class OnlineShop* s) {
			bool ret = compare(f, s);
			return what >= 0 ? ret : !ret;
		}
	};
};

class StationeryDepartment : public Shop {
private:
	int id_product = 0;
	int quantity = 0;
	float price = 0;
	const string name_file = "Product.txt";
	const string map_file = "Type_Stationery.txt";
	string type_of_stationery;
	string name;
private:
	ShowTable label;
	vector<StationeryDepartment> arr_product;
	map<int, string> arr_type;
};

