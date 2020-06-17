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
	table.setlength(table.getparameter("������� ����� ������\n", "������������ ����. ����� ������ ������ ���� ����� ������ �� 1 �� 30 � ������� ������ ���� ��������\n", figure, 30, 1));


secondinput:
	figure = 0;
	table.setcolumnfrequency(table.getparameter("������� ������� ��������� �����\n", "������������ ����. ������� ��������� ����� ������ ���� ����� ������ �� 1 �� 30 � ������� ������ ���� ��������\n", figure, 30, 1));

thirdinput:
	figure = 0;
	table.setsymbolfrequency(table.getparameter("������� ������� ����������� ��������\n", "������������ ����. ������� ����������� �������� ������ ���� ����� ������ �� 1 �� 30 � ������� ������ ���� ��������\n", figure, 30, 1));

fourthinput:
	table.setcolorscheme(table.getparameter("�������� �������� �����\n[1]�����������\n[2]��������� �����\n", "������������ ����. ����� ������ 1 ��� 2 � ������ ���� ��������\n", figure, 2, 1));

fifthinput:
	if (table.getcolorscheme() == 1) {
		table.setchoosencolor(table.getparameter("�������� ����\n[1]�����\n[2]�������\n[3]�������\n[4]�������\n[5]���������\n[6]����������\n[7]������-�����\n[8]�����-�����\n[9]������-�����\n[10]������-�������\n[11]������-�������\n[12]������-�������\n[13]������-���������\n[14]������\n[15]�����\n", "������������ ����. ������ ���� ������� ����� ����� �� 1 �� 15 � ������ ����\n", figure, 15, 1));
	}

	system("cls");

	table.getconsolesize();

	table.matrixfunction(actualsymbol, actualcolumn, table);


	return 0;
}