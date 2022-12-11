
#include <iostream>
#include "Shop.h"
#include "Validator.h"
#include <Windows.h>


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	OnlineShop shop;
	while (1) {
		cout << "\t\t---->  Меню Программы  <----" << endl;
		cout << "\t1.Вывести весь ассортимент" << endl;
		cout << "\t2.Вывести категории" << endl;
		cout << "\t3.Вывести очередь" << endl;
		cout << "\t4.Добавить клиента в очередь" << endl;
		cout << "\t5.Добавить товар" << endl;
		cout << "\t6.Добавить категорию" << endl;
		cout << "\t7.Редактирвать товар" << endl;
		cout << "\t8.Удалить товар" << endl;
		cout << "\t9.Выход" << endl;
		cout << "Ваш Выбор:";
		switch (checkInterval(1, 7)) {
		case 1: shop.print_shop(); shop.sort_product(); system("pause"); system("cls"); break;
		case 2: shop.print_map(); system("pause"); system("cls"); break;
		case 3: shop.print_que(); system("pause"); break;
		case 4:shop.add_people(); system("pause"); break; system("cls");
		case 5: shop.add_product(); system("pause"); system("cls"); break;
		case 6: shop.add_map(); system("pause"); system("cls"); break;
		case 7: shop.edit_product(); system("pause"); system("cls"); break;
		case 8: shop.del_product(); system("pause"); system("cls"); break;
		case 9: return 0;
		}
	}
}

