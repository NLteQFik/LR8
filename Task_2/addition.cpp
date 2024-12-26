#include "header.h"

void addition() {
    std::cout << "Введите количество квитанций, которое вы хотите добавить:\n";
    
    int plus = posIntegerInput();
    tech = (radio*)realloc(tech, (n + plus) * sizeof(radio));
    std::string s;

    for (int i = n; i < n + plus; i++) {
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

        std::cout << "Состояние готовности заказа (Выполнен / Не выполнен):\n";
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
    n += plus;

    std::cout << '\n';

    writeWorkFile();
}