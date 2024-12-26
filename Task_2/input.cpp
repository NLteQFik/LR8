#include "header.h"

void input() {
    n = 0;
    free(tech);
    tech = NULL;

    std::cout << "Введите количество квитанций:\n";

    n = posIntegerInput();
    tech = (radio*)malloc(n * sizeof(radio));
    std::string s;

    std::cout << '\n';

    for (int i = 0; i < n; i++) {
        std::cout << "Введите информацию о квитанции " << i + 1 << " :\n" << '\n';

        std::cout << "Наименование группы изделий:\n";
        s = nameInput();
        strcpy(tech[i].name, s.c_str());

        std::cout << "Марка изделия:\n";
        s = nameInput();
        strcpy(tech[i].mark, s.c_str());

        std::cout << "Дата поступления в ремонт:\n";
        s = dateInput();
        strcpy(tech[i].date, s.c_str());

        std::cout << "Состояние готовности заказа (Выполнен / Невыполнен):\n";
        s = statInput();
        strcpy(tech[i].state, s.c_str());

        if (choice) {
            std::cout << "Введите цену:\n";
            tech[i].details.price = posFloatInput();
        }
        else {
            std::cout << "Введите вес:\n";
            tech[i].details.price = posFloatInput();
        }

        std::cout << '\n';
    }

    std::cout << '\n';

    writeWorkFile();
}