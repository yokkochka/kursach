
#include "header.h"

using namespace std;

int menu();

const char fname[20] = "file.bin";  //Путь до файла

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Здравствуйте!" << endl;

    //Инициализация файла
    fstream p("file.bin"); // app используется для записи в конец файла

    //открываем файл
    if (p)
    {
        p.close();
        p.open(fname, fstream::in | fstream::out | fstream::app | fstream::ate | fstream::binary);
    }
    while (true)
    {
        int choise = menu();
        switch (choise)
        {
            case(1):
            {
                cout << "Вы выбрали команду, которая показывает таблицу растений" << endl;
                vivod(p);
                break;
            }
            case(2):
            {
                cout << "Вы выбрали команду, которая добавляет новое растение" << endl;
                write_new(p);
                break;
            }
            case(3):
            {
                cout << "Вы выбрали команду, которая покажет какие растения будут цвести в заданный промежуток врмени" << endl;
                cout << "Введите дату начала цветения (дату введите в формате дд мм гг ЧЕРЕЗ ПРОБЕЛ)";
                int start_bloom[3];
                for (int i = 0; i < 3; i++)
                {
                    cin >> start_bloom[i];
                }
                cout << "Введите дату конца цветения (дату введите в формате дд мм гг ЧЕРЕЗ ПРОБЕЛ)";
                int end_bloom[3];
                for (int i = 0; i < 3; i++)
                {
                    cin >> end_bloom[i];
                }
                // Вызов функции, которая определит все и выведет результат
                break;
            }
            case(4):
            {
                cout << "Вы выбрали команду выхода! До встречи!" << endl;
                exit(0);
                break;
            }
        }
    }

    p.close();

}

int menu()
{
    setlocale(LC_ALL, "Russian");
    int choise;
    cout << "Выберите действия (введите цифру,соответствующую вашему выбору): " << endl;
    cout << "1 - Покатать таблицу растений" << endl;
    cout << "2 - Добавить новое растение" << endl;
    cout << "3 - Узнать какие растения будут цвести в определенный промежуток времени" << endl;
    cout << "4 - Выход" << endl;

    cin >> choise;
    return choise;

}




/*
int value;
        cin >> value;
        string msg;
        if (value == 1)
        {
            cin >> msg;
            p << msg << "\n";

        }
        else if(value == 2)
        {
            while (!p.eof())
            {
                msg = "";
                p >> msg;
                cout << msg << endl;
            }
        }
*/