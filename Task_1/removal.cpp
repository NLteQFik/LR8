#include "header.h"

void removal() {

    if (n == 0) {
        std::cout << "\nУдаление невозможно! Нет товаров\n\n";
        return;
    }

    std::cout << "Выберите признак:\n";
    std::cout << "1. Наименование товара\n";
    std::cout << "2. Количество единиц товара\n";
    std::cout << "3. Цена единицы\n";
    std::cout << "4. Вес единицы\n";
    std::cout << "5. Дата поступления\n";
    if (choice) {
        std::cout << "6. Cтоимость товара\n";
    }
    else {
        std::cout << "6. Масса товара\n";
    }

    int type;
    while (true) {
        type = posIntegerInput();

        std::cout << '\n';

        if (type > 6) {
            std::cout << "Неверный формат ввода!";
            continue;
        }
        break;
    }

    std::cout << "Введите информацию о признаке:\n" << '\n';

    std::string name, date;
    int quantity, weight;
    float price;
    long long mass;
    double cost;
    int counter = 0;
    short *wrong = new short[n]{0};

    switch (type) {
        case 1:
            std::cout << "Наименование товара:\n";
            name = nameInput();

            for (int i = 0; i < n; i++) {
                if (strcmp(name.c_str(), goods[i].name) == 0) {
                    wrong[i] = 1;
                    counter++;
                }
            }
            break;

        case 2:
            std::cout << "Количество единиц товара:\n";
            quantity = posIntegerInput();

            for (int i = 0; i < n; i++) {
                if (goods[i].quantity == quantity) {
                    wrong[i] = 1;
                    counter++;
                }
            }
            break;

        case 3:
            std::cout << "Цена единицы:\n";
            price = posFloatInput();

            for (int i = 0; i < n; i++) {
                if (goods[i].price == price) {
                    wrong[i] = 1;
                    counter++;
                }
            }
            break;

        case 4:
            std::cout << "Вес единицы:\n";
            weight = posIntegerInput();

            for (int i = 0; i < n; i++) {
                if (goods[i].weight == weight) {
                    wrong[i] = 1;
                    counter++;
                }
            }
            break;

        case 5:
            std::cout << "Дата поступления:\n";
            date = dateInput();

            for (int i = 0; i < n; i++) {
                if (strcmp(goods[i].date, date.c_str()) == 0) {
                    wrong[i] = 1;
                    counter++;
                }
            }
            break;  

        case 6:
            if (choice) {
                std::cout << "6. Cтоимость товара:\n";
                cost = posDoubleInput();

                for (int i = 0; i < n; i++) {
                    if (goods[i].details.cost == cost) {
                        wrong[i] = 1;
                        counter++;
                    }
                }
                break;                
            }
            else {
                std::cout << "6. Масса товара:\n";
                mass = posLongLongInput();

                for (int i = 0; i < n; i++) {
                    if (goods[i].details.mass == mass) {
                        wrong[i] = 1;
                        counter++;
                    }
                }
                break;                
            }                
    }

    if (counter == 0) {
        std::cout << '\n' << "Товаров не найдено\n" << '\n';
        delete[] wrong; 
        return;
    }

    int j = 0;

    for (int i = 0; i < n; i++) {
        if (!wrong[i]) {
            goods[j] = goods[i];
            j++;
        }
    }

    n -= counter;
    goods = (product*)realloc(goods, n * sizeof(product));
    delete[] wrong; 

    std::cout << '\n' << "Товары удалены\n" << '\n';

    writeFile();
}