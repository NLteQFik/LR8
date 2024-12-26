#include "header.h"

void output() {
    for (int i = 0; i < n; i++) {
        std::cout << '\n' << "Информация о товаре " << i + 1 << " :\n";
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
    }

    if (n == 0) {
        std::cout << '\n' << "Информации о товарах нет\n" << '\n';
    }

    std::cout << '\n';
}

void sortOutput() {
    if (!choice) {
        std::cout << "\nСортировка невозможна! Измените шестое поле структуры\n\n";
        return;
    }
    else {
        sort();

        if (n == 0) {
            std::cout << "\nСортировка невозможна! Нет товаров\n\n";
            return;
        }

        std::cout << "\nПродукты со стоимостью более 100.341 рублей, отсортированные по убыванию\n\n";
        int i = 0;
        while (goods[i].details.cost > 100.341) {
            std::cout << '\n' << "Информация о товаре " << i + 1 << " :\n";
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
            std::cout << '\n' << '\n';
            i++;
        }

        if (i == 0) {
            std::cout << "Таких товаров нет\n\n";
        }

        free(goods);
        readFile();
    }
}