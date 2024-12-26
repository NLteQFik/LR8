#include "header.h"

void change() {

    if (n == 0) {
        std::cout << "\nИзменение невозможно! Нет квитанций\n\n";
        return;
    }

    std::cout << "Выберите признак:\n";
    std::cout << "1. Наименование группы изделий\n";
    std::cout << "2. Марка изделия\n";
    std::cout << "3. Дата поступления в ремонт\n";
    std::cout << "4. Состояние готовности заказа\n";
    if (choice) {
        std::cout << "5. Цена\n";
    }
    else {
        std::cout << "5. Вес\n";
    }

    int type;
    while (true) {
        type = posIntegerInput();

        std::cout << '\n';

        if (type > 5) {
            std::cout << "Неверный формат ввода!";
            continue;
        }
        break;
    }

    std::cout << "Введите информацию о признаке:\n" << '\n';

    std::string name, mark, date, state, new_name, new_mark, new_date, new_state;
    int weight, new_weight;
    float price, new_price;
    int counter = 0;

    switch (type) {
        case 1:
            std::cout << "Наименование группы изделий:\n";
            name = nameInput();
            std::cout << "\nВведите новое наименование:\n";
            new_name = nameInput();

            for (int i = 0; i < n; i++) {
                if (strcmp(name.c_str(), tech[i].name) == 0) {
                    strcpy(tech[i].name, new_name.c_str());
                    rewriteFile(type, i);
                    counter++;
                }
            }
            break;

        case 2:
            std::cout << "Марка изделия:\n";
            mark = nameInput();
            std::cout << "Введите новое марку:\n";
            new_mark = nameInput();

            for (int i = 0; i < n; i++) {
                if (strcmp(mark.c_str(), tech[i].mark) == 0) {
                    strcpy(tech[i].mark, new_mark.c_str());
                    rewriteFile(type, i);
                    counter++;
                }                   
            }
            break;
        case 3:
            std::cout << "Дата поступления в ремонт:\n";
            date = dateInput();
            std::cout << "Введите новое дату:\n";
            new_date = dateInput();

            for (int i = 0; i < n; i++) {
                if (strcmp(date.c_str(), tech[i].date) == 0) {
                    strcpy(tech[i].date, new_date.c_str());
                    rewriteFile(type, i);
                    counter++;
                }                   
            }
            break;
        case 4:
            std::cout << "Cостояние готовности заказа:\n";
            state = statInput();
            std::cout << "Введите новое состояние:\n";
            new_state = statInput();

            for (int i = 0; i < n; i++) {
                if (strcmp(state.c_str(), tech[i].state) == 0) {
                    strcpy(tech[i].state, new_state.c_str());
                    rewriteFile(type, i);
                    counter++;
                }                   
            }
            break;
        case 5:
            if (choice) {
                std::cout << "Цена:\n";
                price = posFloatInput();
                std::cout << "Новая цена:\n";
                new_price = posFloatInput();

                for (int i = 0; i < n; i++) {
                    if (price == tech[i].details.price) {
                        tech[i].details.price = price;
                        rewriteFile(type, i);
                        counter++;
                    }
                }
                break;
            }
            else {
                std::cout << "Вес:\n";
                weight = posIntegerInput();
                std::cout << "Вес:\n";
                new_weight = posIntegerInput();

                for (int i = 0; i < n; i++) {
                    if (weight == tech[i].details.weight) {
                        tech[i].details.weight = weight;
                        rewriteFile(type, i);
                        counter++;
                    }
                }
                break;
            }
            
    }
     
    if (counter) {
        std::cout << '\n' << "Характеристики квитанций изменены\n" << '\n';
        writeWorkFile();
    }
    else {
        std::cout << '\n' << "Квитанций не найдено\n" << '\n';
    }
}