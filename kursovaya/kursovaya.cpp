#include "header.h"
using namespace std;


const char* fname = "file.bin";  //Путь до файла
int len = sizeof(Shop);

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
                cout << "Таблица растений:" << endl << endl;
                vivod(p);
                break;
            }
            case(2):
            {
                cout << "Добавление нового растения: " << endl << endl;
                write_new(p);
                break;
            }
            case(3):
            {
                cout << "В какой период вам необходимо, чтобы растение цвело? " << endl << endl;
                cout << "Введите дату начала цветения (дату введите в формате <дд мм гг> через пробел НАПРИМЕР: 12 12 12)  ";
                int start_bloom[3];
                for (int i = 0; i < 3; i++)
                {
                    cin >> start_bloom[i];
                }
                cout << "Введите дату конца цветения (дату введите в формате <дд мм гг> через пробел НАПРИМЕР: 12 12 12)  ";
                int end_bloom[3];
                for (int i = 0; i < 3; i++)
                {
                    cin >> end_bloom[i];
                }
                cout << endl << endl;

                print_res_bloom(p, start_bloom, end_bloom);
               
                break;
            }
            case(4):
            {
                // Отметить для удаления
                cout << "Введите сорт чтобы отметить для удаления: " << endl;
                char sort[30];
                cin >> sort;
                int numb = metka_for_delete(p, sort);
                break;
            }
            case(5):
            {
                // Снять маркер на удаление
                cout << "Снимаем маркер на удаление" << endl;
                delete_marks(p);
                break;
            }
            case(6):
            {
                // Удалить отмеченных
                cout << "Удаляем отмеченных" << endl;
                delet_who_with_mark(p);
                cout << "Чтобы проверить удаление, используйте команду 1" << endl;
                break;
            }
            case(7):
            {
                cout << "Вы выбрали команду выхода! До встречи!" << endl;
                exit(0);
                break;
            }
        }
    }
    p.close();
}

