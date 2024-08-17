#include <string.h>
#include <windows.h>

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

extern int len;
extern const char fname[20];

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

ostream& shapka(ostream& stream);
ostream& dividing_line(ostream& stream);

char menu();

void write_new(fstream& p);
void write(fstream& p, Shop zap, int num = 0);

void vivod(fstream& p);
void print(Shop zap);
void print_res_bloom(fstream& p, int start_bloom[], int end_bloom[]);
int perevod_dat(int array[]);
void vivod_opr_zap(fstream& p, char* sort);

fstream& read(fstream& p, Shop& zap, int num = 0);
Shop vvod(fstream& p);

void metka_for_delete(fstream& p, char* sort);
void delete_marks(fstream& p);
void delet_who_with_mark(fstream& p);

void vivod_spravki();
