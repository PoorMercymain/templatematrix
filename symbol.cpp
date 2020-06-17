#include "symbol.h"
#include <Windows.h>
#include "Color.h"
#include "window.h"

Color symbol::randomisingcolor(int str, int i)
{

	int randomisecolor = rand() % 15;

	switch (randomisecolor) {

	case 0: randomcolor = Blue;
		break;
	case 1: randomcolor = Green;
		break;
	case 2: randomcolor = Cyan;
		break;
	case 3: randomcolor = Red;
		break;
	case 4: randomcolor = Magenta;
		break;
	case 5: randomcolor = Brown;
		break;
	case 6: randomcolor = LightGray;
		break;
	case 7: randomcolor = DarkGray;
		break;
	case 8: randomcolor = LightBlue;
		break;
	case 9: randomcolor = LightGreen;
		break;
	case 10: randomcolor = LightCyan;
		break;
	case 11: randomcolor = LightRed;
		break;
	case 12: randomcolor = LightMagenta;
		break;
	case 13: randomcolor = Yellow;
		break;
	case 14: randomcolor = White;
		break;

	}
	return randomcolor;
}

Color symbol::fixedcolor(int str, int i, window table)
{
	switch (table.getchoosencolor()) {

	case 1: randomcolor = Blue;
		break;
	case 2: randomcolor = Green;
		break;
	case 3: randomcolor = Cyan;
		break;
	case 4: randomcolor = Red;
		break;
	case 5: randomcolor = Magenta;
		break;
	case 6: randomcolor = Brown;
		break;
	case 7: randomcolor = LightGray;
		break;
	case 8: randomcolor = DarkGray;
		break;
	case 9: randomcolor = LightBlue;
		break;
	case 10: randomcolor = LightGreen;
		break;
	case 11: randomcolor = LightCyan;
		break;
	case 12: randomcolor = LightRed;
		break;
	case 13: randomcolor = LightMagenta;
		break;
	case 14: randomcolor = Yellow;
		break;
	case 15: randomcolor = White;
		break;

	}
	return randomcolor;
}

void symbol::color(Color text, Color background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}




