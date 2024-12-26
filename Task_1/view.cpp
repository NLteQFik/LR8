#include "header.h"

void view() {
    std::cout << '\n' << "Вид структуры:\n";
    std::cout << "1. Наименование товара:\n"; 
    std::cout << "2. Количество единиц товара:\n";
    std::cout << "3. Цена единицы:\n";
    std::cout << "4. Вес единицы:\n";
    std::cout << "5. Дата поступления:\n";
    std::cout << "6. Cтоимость / масса товара. Сейчас ";
    if (choice) {
        std::cout << "стоимость\n"; 
    }
    else {
        std::cout << " масса товара\n";
    }
    std::cout << '\n';
}