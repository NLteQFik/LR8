#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <limits>

#define NAME_SIZE 33
#define DATE_SIZE 9
#define STAT_SIZE 23

typedef struct radio {
    char name[NAME_SIZE] {'\0'};
    char mark[NAME_SIZE] {'\0'};
    char date[DATE_SIZE] {'\0'};
    char state[STAT_SIZE] {'\0'};
    union {
        float price;
        int weight;
    } details;
} radio;

extern bool choice;
extern int n;
extern radio *tech;

int posIntegerInput();
long long posLongLongInput();
float posFloatInput();
double posDoubleInput();
std::string dateInput();
std::string nameInput();
std::string statInput();

void writeWorkFile();
void readWorkFile();
void rewriteFile(int, int);
void writeFinalFile();

void input();

void output();

void addition();

void removal();

void change();

void sort();
void sortOutput();

void option();

void view();