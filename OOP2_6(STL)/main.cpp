#include <iostream>
#include "Appliances.h"
#include "Validators.h"


int main()
{
	setlocale(0, "rus");
	Shoe shop;
	while (1) {
		cout << "\t\t---->  Меню Программы  <----" << endl;
		cout << "\t1.Вывести весь ассортимент" << endl;
		cout << "\t2.Вывести категории" << endl;
		cout << "\t3.Добавить товар" << endl;
		cout << "\t4.Добавить категорию" << endl;
		cout << "\t5.Редактирвать товар" << endl;
		cout << "\t6.Удалить товар" << endl;
		cout << "\t7.Выход" << endl;
		cout << "Ваш Выбор:";
		switch (checkInterval(1, 7)) {
		case 1: shop.print_shop(); shop.sort_product(); system("pause"); system("cls"); break;
		case 2: shop.print_map(); system("pause"); system("cls"); break;
		case 3: shop.add_product(); system("pause"); system("cls"); break;
		case 4: shop.add_map(); system("pause"); system("cls"); break;
		case 5: shop.edit_product(); system("pause"); system("cls"); break;
		case 6: shop.del_product(); system("pause"); system("cls"); break;
		case 7: return 0;
		}
	}
}