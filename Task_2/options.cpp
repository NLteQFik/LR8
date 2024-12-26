#include "header.h"

void option() {
    std::cout << "\nВыберите тип шестого поля:\n";
    std::cout << "1. Цена\n";
    std::cout << "2. Вес\n";

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
                    std::cout << "\nИзделие " << i + 1;
                    std::cout << "\nВведите цену:\n";
                    tech[i].details.price = posFloatInput();
                    rewriteFile(6, i);
                }
                break;
            case 2:
                choice = 0;
                rewriteFile(0, 0);
                for (int i = 0; i < n; i++) {
                    std::cout << "\nИзделие " << i + 1;
                    std::cout << "\nВведите вес:\n";
                    tech[i].details.weight = posIntegerInput();
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

    writeWorkFile();
}