#include "header.h"

ostream& shapka(ostream& stream)
{
	setlocale(LC_ALL, "rus");
	stream << setw(15) << "Сорт"
		<< setw(15) << "Цвет"
		<< setw(15) << "Высота"
		<< setw(25) << "Длительность роста"
		<< setw(25) << "Длительность цветения"
		<< setw(15) << "Марка" << endl;
	return stream;
}


ostream& dividing_line(ostream& stream) {
	stream << setfill('-') << setw(120) << ' ' << setfill(' ');
	return stream;
}
