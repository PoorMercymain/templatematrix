#include<Windows.h>
#include<ctime>
#include "Color.h"
#include "column.h"
#include "symbol.h"
#include "window.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(0));

	window table;
	symbol actualsymbol;
	column actualcolumn;

	actualsymbol.color(White, Black);
	int figure = 0;
firstinput:
	table.setlength(table.getparameter("Введите длину змейки\n", "Некорректный ввод. Длина змейки должна быть целым числом от 1 до 30 и введено только одно значение\n", figure, 30, 1));


secondinput:
	figure = 0;
	table.setcolumnfrequency(table.getparameter("Введите частоту появления змеек\n", "Некорректный ввод. Частота появления змеек должна быть целым числом от 1 до 30 и введено только одно значение\n", figure, 30, 1));

thirdinput:
	figure = 0;
	table.setsymbolfrequency(table.getparameter("Введите частоту перемещения символов\n", "Некорректный ввод. Частота перемещения символов должна быть целым числом от 1 до 30 и введено только одно значение\n", figure, 30, 1));

fourthinput:
	table.setcolorscheme(table.getparameter("Выберите цветовую схему\n[1]одноцветная\n[2]случайные цвета\n", "Некорректный ввод. Нужно ввести 1 или 2 и только одно значение\n", figure, 2, 1));

fifthinput:
	if (table.getcolorscheme() == 1) {
		table.setchoosencolor(table.getparameter("Выберите цвет\n[1]синий\n[2]зеленый\n[3]голубой\n[4]красный\n[5]пурпурный\n[6]коричневый\n[7]светло-серый\n[8]темно-серый\n[9]светло-синий\n[10]светло-зеленый\n[11]светло-голубой\n[12]светло-красный\n[13]светло-пурпурный\n[14]желтый\n[15]белый\n", "Некорректный ввод. Должно быть введено целое число от 1 до 15 и только одно\n", figure, 15, 1));
	}

	system("cls");

	table.getconsolesize();

	table.matrixfunction(actualsymbol, actualcolumn, table);


	return 0;
}