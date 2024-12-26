#include "header.h"

void view() {
    std::cout << '\n' << "Вид структуры:\n";
    std::cout << "1. Наименование группы изделий:\n"; 
    std::cout << "2. Марка изделия:\n";
    std::cout << "3. Дата поступления в ремонт:\n";
    std::cout << "4. Состояние готовности:\n";
    std::cout << "5. Цена / вес изделия. Сейчас ";
    if (choice) {
        std::cout << "цена\n"; 
    }
    else {
        std::cout << "вес\n";
    }
    std::cout << '\n';
}