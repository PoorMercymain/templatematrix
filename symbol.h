#pragma once

class symbol
{
	char character = ' ';
	enum Color randomcolor;
	int currenttimesym = 0;
public:
	char getcharacter() { return character; }
	enum Color getrandomcolor() { return randomcolor; }
	int getcurrenttimesym() { return currenttimesym; }
	void setcharacter(char value) { character = value; }
	void setrandomcolor(enum Color value) { randomcolor = value; }
	void setcurrenttimesym(int value) { currenttimesym = value; }
	enum Color randomisingcolor(int str, int i);
	enum Color fixedcolor(int str, int i, class window table);
	void color(enum Color text, enum  Color background);
	
};

