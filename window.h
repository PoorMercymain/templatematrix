#pragma once

#include "container.h"
#include "snake.h"

class window
{
	int width, height;
	char numberchar;
	enum Color numbercolor;
	
	int** sizing();
	int* sizingwidth();
	int* sizingheight();
	int freecolumns, colorscheme, choosencolor, columnfrequency, symbolfrequency;
	int length = -1;
public:

	void gotoxy(int xpos, int ypos);
	
	void unsizing(int** array);
	void unsizing(int* array);
	void unsizeall(int* int3, int* int4, int** int5, int** int9, int* int10);
	int getwidth() { return width; }
	int getheight() { return height; }
	void getconsolesize();
	void push(int i, int& dropelement, container<snake> snakes, container<snake>* snakesadress, class symbol actualsymbol, class column actualcolumn, class window tab);
	void matrixfunction(class symbol actualsymbol, class column actualcolumn, class window table);

	int getfreecolumns() { return freecolumns; }
	void setfreecolumns(int value) { freecolumns = value; }
	int getcolorscheme() { return colorscheme; }
	void setcolorscheme(int value) { colorscheme = value; }
	int getchoosencolor() { return choosencolor; }
	void setchoosencolor(int value) { choosencolor = value; }
	int getcolumnfrequency() { return columnfrequency; }
	void setcolumnfrequency(int value) { columnfrequency = value; }
	int getsymbolfrequency() { return symbolfrequency; }
	void setsymbolfrequency(int value) { symbolfrequency = value; }
	int getparameter(const char whattoinput[], const char wrongvalue[], int parameter, int max = 30, int min = 1);
	int getlength() { return length; }
	void setlength(int value) { length = value; }
	void function(snake i, class symbol actualsymbol, class column actualcolumn, class window tab);
	void addnewcolumn(snake newelement, int newcolumn, container<snake> *snakesadress);
};

