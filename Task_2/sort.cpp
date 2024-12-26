#include "header.h"

void sort() {
    for (int i = 0; i < n; i++) {
        radio key = tech[i];
        int j = i - 1;
        while (j >= 0 && strcmp(tech[j].name, key.name) < 0) {
            tech[j + 1] = tech[j];
            j--;
        }
        tech[j + 1] = key;
    }
}

