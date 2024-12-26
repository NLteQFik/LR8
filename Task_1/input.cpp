#include "header.h"

void input() {
    std::cout << "Режимы ввода:\n";
    std::cout << "1. Ввод заранее заданного количества товаров\n";
    std::cout << "2. Ввод до появления заданного признака\n";
    std::cout << "3. Ввод с диалогом о необходимости продолжать ввод\n";
    std::cout << "Выберите режим ввода:\n";

    n = 0;
    free(goods);
    goods = NULL;

    int type;
    bool b;
    while (true) {
        b = 0;
        type = posIntegerInput();

        std::cout << '\n';

        switch (type) {
            case 1:
                firstInput();
                break;
            case 2:
                secondInput();
                break;
            case 3:
                thirdInput();
                break;
            default:
                std::cout << "Неверный формат ввода!\n";
                b = 1;
        }
        if (b) {
            continue;
        }
        break;
    }
}

void firstInput() {
    std::cout << "Введите количество товаров:\n";

    n = posIntegerInput();
    goods = (product*)malloc(n * sizeof(product));
    std::string s;

    std::cout << '\n';

    for (int i = 0; i < n; i++) {
        std::cout << "Введите информацию о товаре " << i + 1 << " :\n" << '\n';

        std::cout << "Наименование товара:\n";
        s = nameInput();
        for (int j = 0; j < NAME_SIZE; j++) {
            goods[i].name[j] = s[j];
        }

        std::cout << "Количество единиц товара:\n";
        goods[i].quantity = posIntegerInput();

        std::cout << "Цена единицы:\n";
        goods[i].price = posFloatInput();

        std::cout << "Вес единицы:\n";
        goods[i].weight = posIntegerInput();

        std::cout << "Дата поступления:\n";
        s = dateInput();
        for (int j = 0; j < DATE_SIZE; j++) {
            goods[i].date[j] = s[j];
        }

        if (choice) {
            goods[i].details.cost = goods[i].quantity * goods[i].price;
        }
        else {
            goods[i].details.mass = goods[i].quantity * goods[i].weight;
        }

        std::cout << '\n';
    }

    std::cout << '\n';

    writeFile();
}

void secondInput() { 
    std::cout << "Выберите признак:\n";
    std::cout << "1. Наименование товара\n";
    std::cout << "2. Количество единиц товара\n";
    std::cout << "3. Цена единицы\n";
    std::cout << "4. Вес единицы\n";
    std::cout << "5. Дата поступления\n";

    std::string name, date;
    int quantity, weight;
    float price;

    int type;
    bool b;
    while (true) {
        b = 0;
        std::cout << '\n';
        type = posIntegerInput();
        switch (type) {
            case 1:
                name = nameInput();
                break;
            case 2:
                quantity = posIntegerInput();
                break;
            case 3:
                price = posFloatInput();
                break;
            case 4:
                weight = posIntegerInput();
                break;
            case 5:
                date = dateInput();
                break;
            default:
                std::cout << "Неверный формат ввода!\n";
                b = 1;
        }
        if (b) {
            continue;
        }
        break;
    }
    
    std::string s;

    std::cout << '\n';

    while (true) {
        b = 0;
        goods = (product*)realloc(goods, (n + 1) * sizeof(product));
        std::cout << "Введите информацию о товаре " << n + 1 << " :\n" << '\n';

        std::cout << "Наименование товара:\n";
        s = nameInput();
        for (int j = 0; j < s.size(); j++) {
            goods[n].name[j] = s[j];
        }
        if (type == 1 && s == name) {
            b = 1;
        }

        std::cout << "Количество единиц товара:\n";
        goods[n].quantity = posIntegerInput();
        if (type == 2 && goods[n].quantity == quantity) {
            b = 1;
        }

        std::cout << "Цена единицы:\n";
        goods[n].price = posFloatInput();
        if (type == 3 && goods[n].price == price) {
            b = 1;
        }

        std::cout << "Вес единицы:\n";
        goods[n].weight = posIntegerInput();
        if (type == 4 && goods[n].weight == weight) {
            b = 1;
        }

        std::cout << "Дата поступления:\n";
        s = dateInput();
        for (int j = 0; j < s.size(); j++) {
            goods[n].date[j] = s[j];
        }
        if (type == 5 && s == date) {
            b = 1;
        }

        if (choice) {
            goods[n].details.cost = goods[n].quantity * goods[n].price;
        }
        else {
            goods[n].details.mass = goods[n].quantity * goods[n].weight;
        }

        n++;
        if (b) {
            break;
        }

        std::cout << '\n';
    }

    std::cout << '\n';

    writeFile();
}

void thirdInput() { 
    bool b;
    std::string s;

    while(true) {
        b = 0;
        goods = (product*)realloc(goods, (n + 1) * sizeof(product));

        std::cout << "Введите информацию о товаре " << n + 1 << " :\n" << '\n';

        std::cout << "Наименование товара:\n";
        s = nameInput();
        for (int j = 0; j < s.size(); j++) {
            goods[n].name[j] = s[j];
        }

        std::cout << "Количество единиц товара:\n";
        goods[n].quantity = posIntegerInput();

        std::cout << "Цена единицы:\n";
        goods[n].price = posFloatInput();

        std::cout << "Вес единицы:\n";
        goods[n].price = posIntegerInput();

        std::cout << "Дата поступления:\n";
        s = dateInput();
        for (int j = 0; j < s.size(); j++) {
            goods[n].date[j] = s[j];
        }

        if (choice) {
            goods[n].details.cost = goods[n].quantity * goods[n].price;
        }
        else {
            goods[n].details.mass = goods[n].quantity * goods[n].weight;
        }

        std::cout << '\n' << "Введитие 1, если хотите продолжить ввод и 2, если не хотите:\n";
        int type;
        bool c;
        while (true) {
            c = 0;
            type = posIntegerInput();

            switch (type) {
                case 1:
                    b = 1;
                    break;
                case 2:
                    b = 0;
                    break;
                default:
                    std::cout << "Неверный формат ввода!\n";
                    c = 1;
            }
            if (c) {
                continue;
            }
            break;
        }

        n++;

        if (b) {
            continue;
        }
        break;
    }

    std::cout << '\n';

    writeFile();
}