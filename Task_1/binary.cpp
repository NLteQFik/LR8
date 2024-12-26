#include "header.h"

void writeFile() {
    std::ofstream file;
    file.open("save.bin", std::ios::out | std::ios::binary);

    int size;
    file.write((char*)&n, sizeof(n));
    file.write((char*)&choice, sizeof(choice));

    for (int i = 0; i < n; i++) {
        size = NAME_SIZE;
        file.write(&goods[i].name[0], size * sizeof(goods[i].name[0]));

        file.write((char*)&goods[i].quantity, sizeof(goods[i].quantity));

        file.write((char*)&goods[i].price, sizeof(goods[i].price));

        file.write((char*)&goods[i].weight, sizeof(goods[i].weight));

        size = DATE_SIZE;
        file.write(&goods[i].date[0], size * sizeof(goods[i].date[0]));

        file.write((char*)&goods[i].details, sizeof(goods[i].details));
    }

    file.close();
}

void readFile() {
    std::ifstream file;
    file.open("save.bin", std::ios::in | std::ios::binary);

    size_t size;
    file.read((char*)&n, sizeof(n));
    file.read((char*)&choice, sizeof(choice));
    goods = (product*)malloc(n * sizeof(product));

    for (int i = 0; i < n; i++) {
        size = NAME_SIZE;
        file.read(&goods[i].name[0], size * sizeof(goods[i].name[0]));

        file.read((char*)&goods[i].quantity, sizeof(goods[i].quantity));

        file.read((char*)&goods[i].price, sizeof(goods[i].price));

        file.read((char*)&goods[i].weight, sizeof(goods[i].weight));

        size = DATE_SIZE;      
        file.read(&goods[i].date[0], size * sizeof(goods[i].date[0]));

        file.read((char*)&goods[i].details, sizeof(goods[i].details));
    }

    file.close();
}

void rewriteFile(int type, int i) {
    std::fstream file;
    file.open("save.bin", std::ios::in | std::ios::out | std::ios::binary);

    int size;
    int position = sizeof(n) + sizeof(choice) + i * (sizeof(product) - 8); //спасибо char и float за 8 лишних байтов
    
    position += 0;
    size = NAME_SIZE;

    if (type == 0) {
        file.seekp(sizeof(n));
        file.write((char*)&choice,sizeof(choice));
    }

    if (type == 1) {
        file.seekp(position);
        file.write(&goods[i].name[0], size * sizeof(goods[i].name[0]));
    }

    position += size * sizeof(goods[i].name[0]);

    if (type == 2) {
        file.seekp(position);
        file.write((char*)&goods[i].quantity, sizeof(goods[i].quantity));
    }

    position += sizeof(goods[i].quantity);

    if (type == 3) {
        file.seekp(position);
        file.write((char*)&goods[i].price, sizeof(goods[i].price));
    }

    position += sizeof(goods[i].price);

    if (type == 4) {
        file.seekp(position);
        file.write((char*)&goods[i].weight, sizeof(goods[i].weight));
    }

    position += sizeof(goods[i].weight);
    size = DATE_SIZE;

    if (type == 5) {
        file.seekp(position);
        file.write(&goods[i].date[0], size * sizeof(goods[i].date[0]));
    }

    position += size * sizeof(goods[i].date[0]);

    if (type == 6) {
        file.seekp(position);
        file.write((char*)&goods[i].details, sizeof(goods[i].details));
    }

    file.close();
}