#include "header.h"

void writeWorkFile() {
    std::ofstream file;
    file.open("work.txt", std::ios::out);

    int size;
    file << n << '\n';
    file << choice << '\n';

    for (int i = 0; i < n; i++) {
        file << tech[i].name << '\n'; 
        file << tech[i].mark << '\n';
        file << tech[i].date << '\n';
        file << tech[i].state << '\n';
        if (choice) {
            file << tech[i].details.price << '\n';
        }
        else {
            file << tech[i].details.weight << '\n';
        }
    }

    file.close();
}

void readWorkFile() {
    std::ifstream file;
    file.open("work.txt", std::ios::in);

    std::string s;
    file >> n;
    tech = (radio*)malloc(n * sizeof(radio));
    file >> choice;

    for (int i = 0; i < n; i++) {
        file >> tech[i].name;
        file >> tech[i].mark;
        file >> tech[i].date;
        file >> tech[i].state;
        if (choice) {
            file >> tech[i].details.price;
        }
        else {
            file >> tech[i].details.weight;
        }
    }

    file.close();
}

void rewriteFile(int type, int i) {
}

void writeFinalFile() {
    std::ofstream file;
    file.open("text.txt", std::ios::out);

    for (int i = 0; i < n; i++) {
        file << "Содержание квитанции " << i + 1 << '\n';
        file << "Наименование группы изделий: " << tech[i].name << '\n'; 
        file << "Марка изделия: " << tech[i].mark << '\n';
        file << "Дата поступления в ремонт: " << tech[i].date << '\n';
        file << "Состояние готовности заказа: " << tech[i].state << '\n';
        if (choice) {
            file << "Цена: " << tech[i].details.price << '\n';
        }
        else {
            file << "Вес: " << tech[i].details.weight << '\n';
        }
        file << '\n';
    }
    file.close();
}