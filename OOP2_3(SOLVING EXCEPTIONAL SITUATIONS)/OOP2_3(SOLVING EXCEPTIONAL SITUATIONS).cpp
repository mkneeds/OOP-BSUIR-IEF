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
        switch (checkInterval(1, 15)) {
        case 1: pc.SwitchPC(); break;
        case 2: pc.print_i(); break;
        case 3: pc.print_ifform(); break;
        case 4: First_exp(); break;
        case 5: Twice_exp(); break;
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
        case 7: Three_exp(); break;
        case 8: Four_exp(); break;
        case 9: Five_exp(); break;
        case 10: print_file(); break;
        case 11: delete_file(); break;
        case 12: search_in_file(); break;
        case 13: delete_inform(); break;
        case 14: add_inform(); break;
        case 15: return 0;

        }
    }
}
