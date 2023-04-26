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
#include <windows.h>

using namespace std;

extern int len;
extern const char fname[20];

// Структура магазина
struct Shop {
    char name[20];
    char color[20];
    int hight;
    int grow;
    int bloom;
    
    int start_bloom[6];
    int end_bloom[6];

    char marka[2];
};


// Заголовок(шапка) иразделяющая линия
ostream& shapka(ostream& stream);
ostream& dividing_line(ostream& stream);



//Прототипы
int menu();

void write_new(fstream& p);
void write(fstream& p, Shop zap, int num = 0);

void vivod(fstream& p);
void print(Shop zap);
void print_res_bloom(fstream& p, int start_bloom[], int end_bloom[]);
int perevod_dat(int array[]);


fstream& read(fstream& p, Shop& zap, int num = 0);
Shop vvod(fstream& p);

void metka_for_delete(fstream& p, char* sort);
void delete_marks(fstream& p);
void delet_who_with_mark(fstream& p);

