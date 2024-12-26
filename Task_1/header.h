#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>

#define NAME_SIZE 35
#define DATE_SIZE 9

typedef struct product {
    char name[NAME_SIZE] {'\0'};
    int quantity;
    float price;
    int weight;
    char date[DATE_SIZE] {'\0'};
    union {
        long long mass;
        double cost;
    } details;
} product;

extern bool choice;
extern int n;
extern product *goods;

int posIntegerInput();
long long posLongLongInput();
float posFloatInput();
double posDoubleInput();
std::string dateInput();
std::string nameInput();

void writeFile();
void readFile();
void rewriteFile(int, int);

void input();
void firstInput();
void secondInput();
void thirdInput();

void output();
void sortOutput();

void addition();

void search();

void removal();

void change();

void sort();

void option();

void view();