#include "header.h"

void output() {
    for (int i = 0; i < n; i++) {
        std::cout << '\n' << "Информация о квитанции " << i + 1 << " :\n";
        std::cout << "Наименование группы изделий:\n" << tech[i].name << '\n';
        std::cout << "Марка изделия:\n" << tech[i].mark << '\n';
        std::cout << "Дата поступления в ремонт:\n" << tech[i].date << '\n';
        std::cout << "Состояние готовности заказа:\n" << tech[i].state << '\n';
        if (choice) {
            std::cout << "Цена:\n" << tech[i].details.price;
        }
        else {
            std::cout << "Вес:\n" << tech[i].details.weight;
        }
        std::cout << '\n';
    }

    if (n == 0) {
        std::cout << '\n' << "Информации о квитанциях нет\n" << '\n';
    }

    std::cout << '\n';
}

void sortOutput() {
    sort();

    if (n == 0) {
        std::cout << "\nСортировка невозможна! Нет изделий\n\n";
        return;
    }

    std::cout << "\nИнформация о состоянии заказов по группам изделий\n\n";

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            std::cout << "\nНаименование группы изделий:\n" << tech[i].name << '\n';
        }
        else if (strcmp(tech[i].name, tech[i - 1].name) != 0){
            std::cout << "\nНаименование группы изделий:\n" << tech[i].name << '\n';
        }
        std::cout << '\n' << "Информация о квитанции " << i + 1 << " :\n";
        std::cout << "Марка изделия:\n" << tech[i].mark << '\n';
        std::cout << "Дата поступления в ремонт:\n" << tech[i].date << '\n';
        std::cout << "Состояние готовности заказа:\n" << tech[i].state << '\n';
        if (choice) {
            std::cout << "Цена:\n" << tech[i].details.price;
        }
        else {
            std::cout << "Вес:\n" << tech[i].details.weight;
        }
        std::cout << '\n';
    }

    free(tech);
    readWorkFile();

}