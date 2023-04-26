#include "header.h"

// Меню выбора действий
int menu()
{
	setlocale(LC_ALL, "Russian");
	int choise;
	cout << endl << endl << "Выберите действия (введите цифру,соответствующую вашему выбору): " << endl;
	cout << "1 - Покатать таблицу растений " << endl;
	cout << "2 - Добавить новое растение " << endl;
	cout << "3 - Узнать какие растения будут цвести в определенный промежуток времени" << endl;
	cout << "4 - Отметить для удаления" << endl;
	cout << "5 - Снять маркер на удаление" << endl;
	cout << "6 - Удалить отмеченных" << endl;
	cout << "7 - Выход" << endl;

	cin >> choise;
	return choise;
}




// Блок ввода
void write_new(fstream& p)
{
	SetConsoleCP(1251);   // Для русского языка
	
	p.clear();
	p.seekg(0, fstream::end);
	Shop zap;
	zap = vvod(p);   // Ввод записи
	write(p, zap, 0);    // Записываем запись в файл
}


Shop vvod(fstream& p)
{
	Shop zap;
	setlocale(LC_ALL, "rus");
	cout << "Введите название сорта:  "; cin >> zap.name;
	cout << "Введите цвет растения:  "; cin >> zap.color;
	cout << "Введите высоту взрослого растения:  "; cin >> zap.hight;
	cout << "Введите кол-во дней от посадки до начала цветения:  "; cin >> zap.grow;
	cout << "Введите сколько дней продолжнается цветение:  ";  cin >> zap.bloom;
	strcpy(zap.marka, "+");
	return zap;
}


// Запись в файл
void write(fstream& p, Shop zap, int num)
{
	p.clear();
	if (num)
	{
		p.seekg((num - 1) * len, ios::beg);
	}
	p.write((char*)&zap, len);
}






// Блок вывода
void vivod(fstream& p)
{
	SetConsoleCP(1251);   // Для русского языка
	p.clear();    // Чистим поток
	p.seekg(0, ios::beg);
	Shop zap;
	cout << dividing_line << endl;
	cout<< shapka;
	cout << dividing_line << endl;
	while (read(p, zap))
	{
		print(zap);
	}
	cout << endl << dividing_line << endl;
}

void print(Shop zap) 
{
	setlocale(LC_ALL, "ru");
	cout << endl
		<< setw(15) << zap.name
		<< setw(15) << zap.color
		<< setw(15) << zap.hight
		<< setw(25) << zap.grow
		<< setw(25) << zap.bloom
		<< setw(15) << zap.marka;
}



// Чтение файла
fstream& read(fstream& p, Shop& zap, int num)
{
	p.clear();
	if (num)
		p.seekg((num - 1) * len, ios::beg);
	p.read((char*)&zap, len);
	return p;
}






// Функция, обеспечивающая индивидуальное задание
void print_res_bloom(fstream& p, int start_bloom[], int end_bloom[])
{
	p.clear();
	Shop zap;
	p.seekp(0, ios::beg);


	// ДЛЯ ОТЛАДКИ ЗАКОММЕНТИРОВАТЬ 123-128 СТРОКИ, РАССКОММЕНТИРОВАТЬ 132	
	// Узнаем какая сейчас дата
	SYSTEMTIME st;
	GetLocalTime(&st);
	int array_now_date[2];
	array_now_date[0] = st.wDay;
	array_now_date[1] = st.wMonth;
	int now_date = perevod_dat(array_now_date);
	

	// Отладочная переменная для сегодняшней даты
	//int now_date = 145;
	
	
	// Переменные счетчики
	int count = 0; int count_index = 0;

	// Промежуток необходимого цветения в днях
	int start_otr;
	int end_otr;
	start_otr = perevod_dat(start_bloom);
	end_otr = perevod_dat(end_bloom);
	
	// Массив значений высоты и номеров строк
	int array[2][100];

	// Узнаем подходит ли растение, заносим в этот список
	while (read(p, zap))
	{
		if (((now_date + zap.grow) <= (start_otr)) && ((end_otr) <= (now_date + zap.grow + zap.bloom)))
		{
			array[0][count_index] = count;
			array[1][count_index] = zap.hight;
			count_index++;
		}
		count++;
	}

	// Одномерный массив со значениями для записей под нужными номерами
	int* array_max_to_min = new int[count_index];
	int ind = 0;
	for (int i = 0; i < count_index; i++)
	{
		// Находим максимальную высоту
		int not_main_znach = array[1][0];
		for (int j = 0; j < count_index; j++)
		{
			if (array[1][j] >= not_main_znach)
			{
				not_main_znach = array[1][j];
				array_max_to_min[i] = array[0][j];
				ind = j;
			}
		}

		// Меняем макс на мин чтобы оно не мешалось
		array[1][ind] = -100;
	}

	// Выводим
	cout << dividing_line << endl;
	cout << shapka;
	cout << dividing_line << endl;
	for (int i = 0; i < count_index; i++)

	{
		if (read(p, zap, array_max_to_min[i] +1))
		{
			print(zap);
		}	
	}
	cout << endl << dividing_line << endl;
}




// Фунция,переводящая дату в кол-во дней от начала года
int perevod_dat(int array[])
{
	// Массив с кол-вом дней в каждом месяце
	int days_in_maonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int count = 0;

	int day = array[0];
	int month = array[1];

	for (int i = 0; i < month; i++)
	{
		count += days_in_maonth[i];
	}
	count += day;
	return count;
}





// Блок для меток
// Отметка на удаление
 void metka_for_delete(fstream& p, char* sort)
{
	 p.clear();
	 Shop zap;
	 p.seekp(0, ios::beg);

	 for (int i = 1; read(p, zap, i); i++)
	 {
		 if (strcmp(zap.name, sort) == 0)
		 {
			 strcpy_s(zap.marka, "-");
			 write(p, zap, i);
			 break;
		 }
	 }
}




// Снять отметки на удаление
void delete_marks(fstream& p)
{
	p.clear();
	Shop zap;
	p.seekp(0, fstream::beg);
	for (int i = 1; read(p, zap, i); i++)
	{
		if (strcmp(zap.marka, "-") == 0)
		{
			strcpy_s(zap.marka, "+");
			write(p, zap, i);
		}
	}
}




// Удалить отмеченные записи
void delet_who_with_mark(fstream& p)
{
	fstream p2("dop.txt", fstream::app);
	p.clear();
	Shop zap;
	p.seekp(0, fstream::beg);
	for (int i = 1; read(p, zap, i); i++)
	{
		if (strcmp(zap.marka, "+") == 0)
		{
			write(p2, zap);
		}
	}
	p2.close();
	p.close();
	remove(fname);
	rename("dop.txt", fname);
	p.open(fname, fstream::in | fstream::out | fstream::binary);
}