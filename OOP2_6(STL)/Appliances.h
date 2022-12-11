#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include "ShowTable.h"

using namespace std;

class Shoe
{
public:
	Shoe(){}
	Shoe(int id,string type, string name, float price, int qua) : type_of_shoe(type),id_product(id) , name(name), price(price), quantity(qua){}
private:
	int id_product = 0; 
	int quantity = 0;
	float price = 0;
	const string name_file = "Product.txt";
	const string map_file = "Type.txt";
	string type_of_shoe;
	string name;
	ShowTable table;
private:
	vector<Shoe> arr_product;
	map<int, string> arr_type;
public:
	void print_shop();
	void add_product();
	void add_map();
	void sort_product();
	void edit_product();
	void del_product();
	void print_map();
	void choose_type(int key);
private:
	void write_end_file();
	void write_end_file_type();
	void load_from_file(vector<Shoe>& v);
	void load_from_file(map<int, string>& arr_type);
	void upload_id();
private:
	friend istream& operator>>(istream& stream, Shoe& v) {
		stream >> v.id_product;
		stream >> v.type_of_shoe;
		stream >> v.name;
		stream >> v.price;
		stream >> v.quantity;
		return stream;
	}
	friend ostream& operator<<(ostream& stream, const Shoe& v) {
		stream << v.id_product << " " << v.type_of_shoe << " " << v.name << " " << v.price<< " "<< v.quantity;
		return stream;
	}
	Shoe& operator=(const Shoe&) = default;

	class comp_data {
		int what;
		bool compare(class Shoe* f, class Shoe* s) {
			switch (abs(what)) {
			case 1: return f->id_product < s->id_product; break;
			case 2: return int(f->price) < int(s->price); break;
			case 3: return int(f->quantity) > int(s->quantity); break;
			default: return false;
			}
		}
	public:
		comp_data(int what) : what(what) {}
		bool operator()(class Shoe* f, class Shoe* s) {
			bool ret = compare(f, s);
			return what >= 0 ? ret : !ret;
		}
	};
};

