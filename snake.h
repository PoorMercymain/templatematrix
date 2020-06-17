#pragma once

class snake
{
	int number=0;
	int xposition=0;
	int head=0;
	int tail=0;
	int time=0;
	
public:
	int getnumber();
	int getxposition();
	int gethead();
	int gettail();
	int gettime();
	
	void setnumber(int value);
	void setxposition(int value);
	void sethead(int value);
	void settail(int value);
	void settime(int value);
	
};

