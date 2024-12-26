#include "header.h"

void removal() {

    if (n == 0) {
        std::cout << "\nУдаление невозможно! Нет квитанций\n\n";
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

    std::string name, mark, date, state;
    int weight;
    float price;
    int counter = 0;
    short *wrong = new short[n]{0};

    switch (type) {
        case 1:
            std::cout << "Наименование группы изделий:\n";
            name = nameInput();

            for (int i = 0; i < n; i++) {
                if (strcmp(name.c_str(), tech[i].name) == 0) {
                    wrong[i] = 1;
                    counter++;
                }
            }
            break;

        case 2:
            std::cout << "Марка изделия:\n";
            mark = nameInput();

            for (int i = 0; i < n; i++) {
                if (strcmp(mark.c_str(), tech[i].mark) == 0) {
                    wrong[i] = 1;
                    counter++;
                }
            }
            break;

        case 3:
            std::cout << "Дата поступления в ремонт:\n";
            date = dateInput();

            for (int i = 0; i < n; i++) {
                    if (strcmp(date.c_str(), tech[i].date) == 0) {
                    wrong[i] = 1;
                    counter++;
                }
            }
            break;

        case 4:
            std::cout << "Состояние готовности заказа:\n";
            state = statInput();

            for (int i = 0; i < n; i++) {
                if (strcmp(state.c_str(), tech[i].state) == 0) {
                    wrong[i] = 1;
                    counter++;
                }
            }
            break;

        case 5:
            if (choice) {
                std::cout << "5. Цена:\n";
                price = posFloatInput();

                for (int i = 0; i < n; i++) {
                    if (tech[i].details.price == price) {
                        wrong[i] = 1;
                        counter++;
                    }
                }
                break;                
            }
            else {
                std::cout << "5. Вес:\n";
                weight = posIntegerInput();

                for (int i = 0; i < n; i++) {
                    if (tech[i].details.weight == weight) {
                        wrong[i] = 1;
                        counter++;
                    }
                }
                break;                
            }                
    }

    if (counter == 0) {
        std::cout << '\n' << "Квитанций не найдено\n" << '\n';
        delete[] wrong; 
        return;
    }

    int j = 0;

    for (int i = 0; i < n; i++) {
        if (!wrong[i]) {
            tech[j] = tech[i];
            j++;
        }
    }

    n -= counter;
    tech = (radio*)realloc(tech, n * sizeof(radio));
    delete[] wrong; 

    std::cout << '\n' << "Квитанции удалены\n" << '\n';

    writeWorkFile();
}