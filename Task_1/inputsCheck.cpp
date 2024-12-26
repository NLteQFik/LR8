#include "header.h"

int posIntegerInput() {
    int n;
    while (true) {
        std::cin >> n;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            std::cout << "Неверный формат ввода!\n";
            continue; 
        }
        if (std::cin.peek() != '\n') {
            std::cin.ignore(100000, '\n');
            std::cout << "Неверный формат ввода!\n";
            continue; 
        }
        if (n <= 0) {
            std::cout << "Неверный формат ввода!\n";
            continue; 
        }
        break;
    }
    return n;
}

long long posLongLongInput() {
    long long n;
    while (true) {
        std::cin >> n;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            std::cout << "Неверный формат ввода!\n";
            continue; 
        }
        if (std::cin.peek() != '\n') {
            std::cin.ignore(100000, '\n');
            std::cout << "Неверный формат ввода!\n";
            continue; 
        }
        if (n <= 0) {
            std::cout << "Неверный формат ввода!\n";
            continue; 
        }
        break;
    }
    return n;
}

float posFloatInput() {
    float n;
    while (true) {
        std::cin >> n;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            std::cout << "Неверный формат ввода!\n";
            continue; 
        }
        if (std::cin.peek() != '\n') {
            std::cin.ignore(100000, '\n');
            std::cout << "Неверный формат ввода!\n";
            continue; 
        }
        if (n <= 0) {
            std::cout << "Неверный формат ввода!\n";
            continue; 
        }
        break;
    }
    return n;
}

double posDoubleInput() {
    double n;
    while (true) {
        std::cin >> n;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            std::cout << "Неверный формат ввода!\n";
            continue; 
        }
        if (std::cin.peek() != '\n') {
            std::cin.ignore(100000, '\n');
            std::cout << "Неверный формат ввода!\n";
            continue; 
        }
        if (n <= 0) {
            std::cout << "Неверный формат ввода!\n";
            continue; 
        }
        break;
    }
    return n;
}

std::string dateInput() {
    std::string s;
    while (true) {
        bool b = 0;
        std::cin >> s; // дд,мм,гг
        if (s.size() != DATE_SIZE - 1) {
            std::cout << "Неверный формат ввода!\n";
            continue; 
        }
        if (s[2] != '.' || s[5] != '.') {
            std::cout << "Неверный формат ввода!\n";
            continue;
        }
        for (int i = 0; i < 8; i++) {
            if (i == 2 || i == 5) {
                continue;
            }
            if (s[i] >= '0' && s[i] <= '9') {
                continue;
            }
            else {
                b = 1; 
                break;
            }
        }

        int n = (s[0] - '0') * 10 + (s[1] - '0');
        int m = (s[3] - '0') * 10 + (s[4] - '0');
        if (n == 0) {
            b = 1;
        }
        if (m > 12 || m == 0) {
            b = 1;
        }

        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
            if (n > 31) {
                b = 1;
            }
        }
        else if (m == 2) {
            if (n > 28) { //29 февраля склад не работает - традиция
                b = 1;
            }
        }
        else {
            if (n > 30) {
                b = 1;
            }
        }

        if (b) {
            std::cout << "Неверный формат ввода!\n";
            continue;
        }
        break;
    }
    s += '\0';
    return s;
}

std::string nameInput() {
    std::string s;

    while (true) {
        std::cin >> s;

        if (s.size() >= NAME_SIZE - 1) {
            std::cout << "Неверный формат ввода!\n";
            continue;
        }
        break;
    }

    while (s.size() != NAME_SIZE) {
        s += '\0';
    }

    return s;
}
