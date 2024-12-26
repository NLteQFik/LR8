#include "header.h"

void change() {

    if (n == 0) {
        std::cout << "\nИзменение невозможно! Нет товаров\n\n";
        return;
    }

    std::cout << "Выберите признак:\n";
    std::cout << "1. Наименование товара\n";
    std::cout << "2. Количество единиц товара\n";
    std::cout << "3. Цена единицы\n";
    std::cout << "4. Вес единицы\n";
    std::cout << "5. Дата поступления\n";

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

    std::string name, date, new_name, new_date;
    int quantity, weight, new_quantity, new_weight;
    float price, new_price;
    long long mass, new_mass;
    double cost, new_cost;
    int counter = 0;

    switch (type) {
        case 1:
            std::cout << "Наименование товара:\n";
            name = nameInput();
            std::cout << "\nВведите новое наименование:\n";
            new_name = nameInput();

            for (int i = 0; i < n; i++) {
                if (strcmp(name.c_str(), goods[i].name) == 0) {
                    strcpy(goods[i].name, new_name.c_str());
                    rewriteFile(type, i);
                    counter++;
                }
            }
            break;

        case 2:
            std::cout << "Количество единиц товара:\n";
            quantity = posIntegerInput();
            std::cout << "Введите новое количество:\n";
            new_quantity = posIntegerInput();

            for (int i = 0; i < n; i++) {
                if (goods[i].quantity == quantity) {
                    goods[i].quantity = new_quantity;
                    rewriteFile(type, i);
                    counter++;                    

                    if (choice) {
                        goods[i].details.cost = goods[i].quantity * goods[i].price;
                        rewriteFile(6, i);
                    }                
                    else {
                        goods[i].details.mass = goods[i].quantity * goods[i].weight;
                        rewriteFile(6, i);               
                    }
                }
            }
            break;
        case 3:
            std::cout << "Цена единицы:\n";
            price = posFloatInput();
            std::cout << "Новая цена:\n";
            new_price = posFloatInput();

            for (int i = 0; i < n; i++) {
                if (goods[i].price == price) {
                    goods[i].price = new_price;
                    rewriteFile(type, i);
                    counter++;

                    if (choice) {
                        goods[i].details.cost = goods[i].quantity * goods[i].price;
                        rewriteFile(6, i);
                    }    
                }
            }
            break;
        case 4:
            std::cout << "Вес единицы:\n";
            weight = posIntegerInput();
            std::cout << "Новый вес:\n";
            new_weight = posIntegerInput();
            
            for (int i = 0; i < n; i++) {
                if (goods[i].weight == weight) {
                    goods[i].weight = new_weight;
                    rewriteFile(type, i);
                    counter++;

                    if (!choice) {
                        goods[i].details.mass = goods[i].quantity * goods[i].weight;
                        rewriteFile(6, i);
                    }    
                }
            }
            break;
        case 5:
            std::cout << "Дата поступления:\n";
            date = dateInput();
            std::cout << "Новая дата поступления:\n";
            new_date = dateInput();

            for (int i = 0; i < n; i++) {
                if (strcmp(date.c_str(), goods[i].date) == 0) {
                    strcpy(goods[i].date, new_date.c_str());
                    rewriteFile(type, i);
                    counter++;
                }
            }
            break;
    }
     
    if (counter) {
        std::cout << '\n' << "Характеристики товаров изменены\n" << '\n';
    }
    else {
        std::cout << '\n' << "Товаров не найдено\n" << '\n';
    }
}