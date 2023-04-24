#include "header.h"

void vivod(fstream& p)
{
	p.clear();
	p.seekg(0, fstream::beg);
	// Вывести шапку с помощью сиаут
	while (read(p, zap))
	{
		out(zap);
	}
	cout << 
}

void write_new(fstream& p)
{
	p.clear(); // Чистка потока
	p.seekg(0, fstream::beg);
	Shop zap;
	zap = vvod(p);   // Ввыод записи
	p.write(p,zap);    // Записываем записаь в файл

}

Shop vvod(fstream& p)
{

}