#include "header.h"

void option() {
    std::cout << "\nВыберите тип шестого поля:\n";
    std::cout << "1. Стоимость товара\n";
    std::cout << "2. Масса товара\n";

    bool b;
    int sel;

    while (true) {
        sel = posIntegerInput();
        b = 0;

        std::cout << '\n';

        switch (sel) {
            case 1:
                choice = 1;
                rewriteFile(0, 0);
                for (int i = 0; i < n; i++) {
                    goods[i].details.cost = goods[i].quantity * goods[i].price;
                    rewriteFile(6, i);
                }
                break;
            case 2:
                choice = 0;
                rewriteFile(0, 0);
                for (int i = 0; i < n; i++) {
                    goods[i].details.mass = goods[i].quantity * goods[i].weight;
                    rewriteFile(6, i);
                } 
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