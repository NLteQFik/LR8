#include "header.h"

void search() {

    if (n == 0) {
        std::cout << "\nПоиск невозможен! Нет товаров\n\n";
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

    switch (type) {
        case 1:
            std::cout << "Наименование товара:\n";
            name = nameInput();

            std::cout << '\n' << "Найденные результаты:\n" << '\n';

            for (int i = 0; i < n; i++) {
 
                if (strcmp(name.c_str(), goods[i].name) == 0) {
                    std::cout << "Наименование товара:\n" << goods[i].name << '\n';
                    std::cout << "Количество единиц товара:\n" << goods[i].quantity << '\n';
                    std::cout << "Цена единицы:\n" << goods[i].price << '\n';
                    std::cout << "Вес единицы:\n" << goods[i].weight << '\n';
                    std::cout << "Дата поступления:\n" << goods[i].date << '\n';
                    if (choice) {
                        std::cout << "Cтоимость товара:\n" << goods[i].details.cost;
                    }
                    else {
                        std::cout << "Масса товара:\n" << goods[i].details.mass;
                    }
                    std::cout << '\n';

                    counter++;
                }
            }

            if (counter == 0) {
                std::cout << '\n' << "Информации о товарах нет\n" << '\n';;
            }
            break;

        case 2:
            std::cout << "Количество единиц товара:\n";
            quantity = posIntegerInput();

            std::cout << '\n' << "Найденные результаты:\n" << '\n';

            for (int i = 0; i < n; i++) {
                if (goods[i].quantity == quantity) {
                    std::cout << "Наименование товара:\n" << goods[i].name << '\n';
                    std::cout << "Количество единиц товара:\n" << goods[i].quantity << '\n';
                    std::cout << "Цена единицы:\n" << goods[i].price << '\n';
                    std::cout << "Вес единицы:\n" << goods[i].weight << '\n';
                    std::cout << "Дата поступления:\n" << goods[i].date << '\n';
                    if (choice) {
                        std::cout << "Cтоимость товара:\n" << goods[i].details.cost;
                    }
                    else {
                        std::cout << "Масса товара:\n" << goods[i].details.mass;
                    }
                    std::cout << '\n';

                    counter++;
                }
            }

            if (counter == 0) {
                std::cout << '\n' << "Информации о товарах нет\n" << '\n';;
            }
            break;
        case 3:
            std::cout << "Цена единицы:\n";
            price = posFloatInput();

            std::cout << '\n' << "Найденные результаты:\n" << '\n';

            for (int i = 0; i < n; i++) {
                if (goods[i].price == price) {
                    std::cout << "Наименование товара:\n" << goods[i].name << '\n';
                    std::cout << "Количество единиц товара:\n" << goods[i].quantity << '\n';
                    std::cout << "Цена единицы:\n" << goods[i].price << '\n';
                    std::cout << "Вес единицы:\n" << goods[i].weight << '\n';
                    std::cout << "Дата поступления:\n" << goods[i].date << '\n';
                    if (choice) {
                        std::cout << "Cтоимость товара:\n" << goods[i].details.cost;
                    }
                    else {
                        std::cout << "Масса товара:\n" << goods[i].details.mass;
                    }
                    std::cout << '\n';

                    counter++;
                }
            }

            if (counter == 0) {
                std::cout << '\n' << "Информации о товарах нет\n" << '\n';
            }
            break;
        case 4:
            std::cout << "Вес единицы:\n";
            weight = posIntegerInput();

            std::cout << '\n' << "Найденные результаты:\n" << '\n';

            for (int i = 0; i < n; i++) {
                if (goods[i].weight == weight) {
                    std::cout << "Наименование товара:\n" << goods[i].name << '\n';
                    std::cout << "Количество единиц товара:\n" << goods[i].quantity << '\n';
                    std::cout << "Цена единицы:\n" << goods[i].price << '\n';
                    std::cout << "Вес единицы:\n" << goods[i].weight << '\n';
                    std::cout << "Дата поступления:\n" << goods[i].date << '\n';
                    if (choice) {
                        std::cout << "Cтоимость товара:\n" << goods[i].details.cost;
                    }
                    else {
                        std::cout << "Масса товара:\n" << goods[i].details.mass;
                    }
                    std::cout << '\n';

                    counter++;
                }
            }

            if (counter == 0) {
                std::cout << '\n' << "Информации о товарах нет\n" << '\n';
            }
            break;            
        case 5:
            std::cout << "Дата поступления:\n";
            date = dateInput();

            std::cout << '\n' << "Найденные результаты:\n" << '\n';

            for (int i = 0; i < n; i++) {
                if (strcmp(goods[i].date, date.c_str()) == 0) {
                    std::cout << "Наименование товара:\n" << goods[i].name << '\n';
                    std::cout << "Количество единиц товара:\n" << goods[i].quantity << '\n';
                    std::cout << "Цена единицы:\n" << goods[i].price << '\n';
                    std::cout << "Вес единицы:\n" << goods[i].weight << '\n';
                    std::cout << "Дата поступления:\n" << goods[i].date << '\n';
                    if (choice) {
                        std::cout << "Cтоимость товара:\n" << goods[i].details.cost;
                    }
                    else {
                        std::cout << "Масса товара:\n" << goods[i].details.mass;
                    }
                    std::cout << '\n';

                    counter++;
                }
            }

            if (counter == 0) {
                std::cout << '\n' << "Информации о товарах нет\n" << '\n';
            }
            break;            
        case 6:
            if (choice) {
                std::cout << "6. Cтоимость товара:\n";
                cost = posDoubleInput();

                std::cout << '\n' << "Найденные результаты:\n" << '\n';

                for (int i = 0; i < n; i++) {
                    if (goods[i].details.cost == cost) {
                        std::cout << "Наименование товара:\n" << goods[i].name << '\n';
                        std::cout << "Количество единиц товара:\n" << goods[i].quantity << '\n';
                        std::cout << "Цена единицы:\n" << goods[i].price << '\n';
                        std::cout << "Вес единицы:\n" << goods[i].weight << '\n';
                        std::cout << "Дата поступления:\n" << goods[i].date << '\n';
                        if (choice) {
                            std::cout << "Cтоимость товара:\n" << goods[i].details.cost;
                        }
                        else {
                            std::cout << "Масса товара:\n" << goods[i].details.mass;
                        }
                        std::cout << '\n';

                        counter++;
                    }
                }

                if (counter == 0) {
                    std::cout << '\n' << "Информации о товарах нет\n" << '\n';
                }
                break;                
            }
            else {
                std::cout << "6. Масса товара:\n";
                mass = posLongLongInput();

                std::cout << '\n' << "Найденные результаты:\n" << '\n';

                for (int i = 0; i < n; i++) {
                    if (goods[i].details.mass == mass) {
                        std::cout << "Наименование товара:\n" << goods[i].name << '\n';
                        std::cout << "Количество единиц товара:\n" << goods[i].quantity << '\n';
                        std::cout << "Цена единицы:\n" << goods[i].price << '\n';
                        std::cout << "Вес единицы:\n" << goods[i].weight << '\n';
                        std::cout << "Дата поступления:\n" << goods[i].date << '\n';
                        if (choice) {
                            std::cout << "Cтоимость товара:\n" << goods[i].details.cost;
                        }
                        else {
                            std::cout << "Масса товара:\n" << goods[i].details.mass;
                        }
                        std::cout << '\n';

                        counter++;
                    }
                }

                if (counter == 0) {
                    std::cout << '\n' << "Информации о товарах нет\n" << '\n';
                }
                break;                
            }                
    }

    std::cout << '\n';    
}