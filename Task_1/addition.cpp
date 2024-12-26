#include "header.h"

void addition() {
    std::cout << "Введите количество товаров, которое вы хотите добавить:\n";
    
    int plus = posIntegerInput();
    goods = (product*)realloc(goods, (n + plus) * sizeof(product));
    std::string s;

    for (int i = 0; i < plus; i++) {
        std::cout << '\n' << "Введите информацию о товаре " << n + i + 1 << " :\n" << '\n';

        std::cout << "Наименование товара:\n";
        s = nameInput();
        for (int j = 0; j < s.size(); j++) {
            goods[n + i].name[j] = s[j];
        }

        std::cout << "Количество единиц товара:\n";
        goods[n + i].quantity = posIntegerInput();

        std::cout << "Цена единицы:\n";
        goods[n + i].price = posFloatInput();

        std::cout << "Вес единицы:\n";
        goods[n + i].weight = posIntegerInput();

        std::cout << "Дата поступления:\n";
        s = dateInput();
        for (int j = 0; j < s.size(); j++) {
            goods[n].date[j] = s[j];
        }

        if (choice) {
            goods[n + i].details.cost = goods[n + i].quantity * goods[n + i].price;
        }
        else {
            goods[n + i].details.mass = goods[n + i].quantity * goods[n + i].weight;
        }

        n++;
    }

    std::cout << '\n';

    writeFile();
}