#include "header.h"

void sort() {
    for (int i = 0; i < n; i++) {
        product key = goods[i];
        int j = i - 1;
        while (j >= 0 && goods[j].details.cost < key.details.cost) {
            goods[j + 1] = goods[j];
            j--;
        }
        goods[j + 1] = key;
    }
}

