
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
		cout << "\t\t---->  ���� ���������  <----" << endl;
		cout << "\t1.������� ���� �����������" << endl;
		cout << "\t2.������� ���������" << endl;
		cout << "\t3.������� �������" << endl;
		cout << "\t4.�������� ������� � �������" << endl;
		cout << "\t5.�������� �����" << endl;
		cout << "\t6.�������� ���������" << endl;
		cout << "\t7.������������ �����" << endl;
		cout << "\t8.������� �����" << endl;
		cout << "\t9.�����" << endl;
		cout << "��� �����:";
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

