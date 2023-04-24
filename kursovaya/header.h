/*
70
Цветочная фирма «Красная лилия» заказала программу обработки информации об
однолетних цветах. О каждом сорте летника в файл записываются следующие данные:
название сорта, цветовая гамма, высота взрослого растения, время в днях от дня посадки
до начала цветения, продолжительность цветения. Программа составляет список сортов,
которые, будучи высажены в день запроса, обеспечивают цветение в заданный временной
интервал (дата начала цветения, и дата конца цветения задаются с клавиатуры). Сорта в
списке расположить в порядке уменьшения высоты растений.
*/

// Библиотеки
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib> // Для функции exit()
#include <cstring>
#include <string.h>
#include <algorithm>
#include <iomanip>

using namespace std;

// Структура магазина
struct Shop {
    char name[20];
    char color[20];
    int hight;
    int grow;
    int bloom;
    
    int start_bloom[6];
    int end_bloom[6];
};


void write_new(fstream& p);
void vivod(fstream& p);
Shop vvod(fstream& p);