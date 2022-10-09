// OOP2_3(SOLVING EXCEPTIONAL SITUATIONS).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PcSoftware.h"
#include <Windows.h>
#include "Validators.h"
#include <filesystem>
#include <fstream>



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    PcSoftware pc;
    while (1) {
        menu::menu();
        switch (checkInterval(1, 13)) {
        case 1: pc.SwitchPC(); break;
        case 2: pc.print_i(); break;
        case 3: pc.print_ifform(); break;
        case 4: Ex1(); break;
        case 5: Ex2(); break;
        case 6: {
            try
        {
            throw Exception("Сработал свой класс исключения..\n");
        }
              catch (Exception& e)
              {
                  std::cout << e.what() << std::endl;
              }
        } break;
        case 7: Ex10(); break;
        case 8: Ex8(); break;
        case 9: Ex9(); break;
        case 10: print_file(); break;
        case 11: delete_file(); break;
        case 12: search_in_file(); break;
        case 13: delete_inform(); break;
        case 14: return 0;

        }
    }
}
