#include <Windows.h>
#include <iostream>
#include <ctime>
#include "window.h"
#include "symbol.h"
#include "column.h"
#include "Color.h"
#include "snake.h"
#include "container.h"
#include "exception.h"

int** window::sizing()
{
	int** array = new int* [height];
	for (int i = 0; i < height; i++) {
		array[i] = new int[width];
	}
	return array;
}

int* window::sizingwidth()
{
	int* array = new int[width];
	return array;
}

int* window::sizingheight()
{
	int* array = new int[height];
	return array;
}

void window::gotoxy(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}









void window::unsizing(int** array)
{
	for (int i = 0; i < height; i++) {
		delete[] array[i];
	}
	delete[] array;
}

void window::unsizing(int* array)
{
	delete[] array;
}

void window::unsizeall(int* int3, int* int4, int** int5, int** int9, int* int10)
{
	unsizing(int5);
	unsizing(int9);
	unsizing(int3);
	unsizing(int4);
	unsizing(int10);
}

void window::getconsolesize()
{
	HANDLE hWndConsole;
	if (hWndConsole = GetStdHandle(-12)) {
		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
		if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo)) {
			width = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
			height = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
		}
	}
}

void window::push(int i, int& dropelement, container<snake> snakes, container<snake>* snakesadress, symbol actualsymbol, column actualcolumn, window tab)
{
	
	
	if (snakes.getelement(i).gethead() < (length - 1)) {
		snakesadress->modifyelement(i)->sethead(snakes.getelement(i).gethead()+1);
		if(snakes.getelement(i).gethead() <= (height-1)){
		function(snakes.getelement(i), actualsymbol, actualcolumn, tab);
		
		}
	}
	else if ((snakes.getelement(i).gethead() < (height - 1)) && (snakes.getelement(i).gethead() >= (length - 1))) {
		
			

			snakesadress->modifyelement(i)->settail(snakes.getelement(i).gethead() - (length - 1));
			actualsymbol.setcharacter(' ');
			
			gotoxy(snakes.getelement(i).getxposition(), snakes.getelement(i).gettail());
			actualsymbol.color(White, Black);
			std::cout << actualsymbol.getcharacter();
			snakesadress->modifyelement(i)->sethead(snakes.getelement(i).gethead() + 1);
			function(snakes.getelement(i), actualsymbol, actualcolumn, tab);
			
			snakesadress->modifyelement(i)->settail(snakes.getelement(i).gethead() - (length - 1));
		}
	
	else if (snakes.getelement(i).gethead() >= (height - 1)) {
		
			int tailcheck = snakes.getelement(i).gettail();

			actualsymbol.setcharacter(' ');
			gotoxy(snakes.getelement(i).getxposition(), snakes.getelement(i).gettail());
			actualsymbol.color(White, Black);
			std::cout << actualsymbol.getcharacter();
			snakesadress->modifyelement(i)->settail(snakes.getelement(i).gettail() + 1);
			tailcheck = snakes.getelement(i).gettail();
			
			if (snakes.getelement(i).gettail() == height) {
				dropelement = 0;
			
			/*for (int ii = i; ii < snakes.getlengthofarray(); ii++) {
				snakesadress->modifyelement(ii)->setnumber(ii);
			}*/


			}

		}
	
}


void window::matrixfunction(symbol actualsymbol, column actualcolumn, window tab)
{
	int dropelement=-1;
	
	container <snake> snakes;
	container <snake> *snakesadress = &snakes;
	int** head = sizing();
	int* dis_length = sizingwidth();
	int** time_head = sizing();
	int* he = sizingheight();
	int* time_he = sizingheight();
	int* freecolumnscoordinates = sizingwidth();
/*
	for (int k = 0; k < height; k++) {
		for (int f = 0; f < width; f++) {
			symbols[k][f] = ' ';
		}
	}*/

	/*for (int i = 0; i < height; i++) {

		for (int j = 0; j < width; j++) {
			head[i][j] = -1;
			time_head[i][j] = -1;
			dis_length[j] = -1;
		}
	}
*/



	
	actualcolumn.setcurrenttimecol(1000 / columnfrequency);
	actualsymbol.setcurrenttimesym(actualcolumn.getcurrenttimecol());

	int del_T_frequency = 2*1000 / columnfrequency;
	for (;;) {

		
		if ((clock() - actualcolumn.getcurrenttimecol()) >= del_T_frequency) { 
			snake newelement;
			int dt = rand() % (del_T_frequency + 1);

			actualcolumn.setcurrenttimecol(clock() + dt);
			
			int newcolumn = -1;
			
			freecolumns = width;
			for (int i = 0; i < width; i++) {
			freecolumnscoordinates[i] = 1;
				for (int j = 0; j < snakes.getlengthofarray(); j++) {
					if ((snakes.getelement(j).getxposition() == i) && (snakes.getelement(j).gethead() < 2)) {
						freecolumnscoordinates[i] = 0;
						freecolumns--;
					}
					
			}
			}


			if (freecolumns) {

				int randomnumber = (rand() % freecolumns);
				newcolumn = freecolumnscoordinates[randomnumber];
				int ii = 0;
				for (int i = 0; i < width; i++) {
					ii = ii + freecolumnscoordinates[i];
					if (ii == randomnumber) {
						newcolumn = i;
						break;
					}
				}
				addnewcolumn(newelement, newcolumn, snakesadress);
				
				

				actualsymbol.setcharacter(' ');
				while (((actualsymbol.getcharacter() < 33) && (actualsymbol.getcharacter() > -1)) || (actualsymbol.getcharacter() == 127)) {
					actualsymbol.setcharacter(rand() % 256);
				}
				
				gotoxy(newcolumn, 0);
				if (colorscheme == 2) {
					
					actualsymbol.color(actualsymbol.randomisingcolor(0, newcolumn), Black);
				}
				else {
					actualsymbol.color(actualsymbol.fixedcolor(0, newcolumn, tab), Black);
				}

				std::cout << actualsymbol.getcharacter();
				
				
			}
		}
		for (int i = 0; i < snakes.getlengthofarray(); i++) {
			

			
			int a = 1000 / symbolfrequency;
				if ((clock() - snakes.getelement(i).gettime()) > (1000 / symbolfrequency))
				{
				snakesadress->modifyelement(i)->settime(clock());
                push(i, dropelement, snakes, snakesadress, actualsymbol, actualcolumn, tab);
					if (!dropelement) {
						snakesadress->droparrayelement("first");
						dropelement = -1;
					}
					for (int ii = i; ii < snakes.getlengthofarray(); ii++) {
						snakesadress->modifyelement(ii)->setnumber(ii);
					}
				}

			
		}
	}




	unsizeall(freecolumnscoordinates, he, head, time_head, time_he/*, colors*/);
	unsizing(dis_length);
	snakesadress->droparray();
}

int window::getparameter(const char whattoinput[], const char wrongvalue[], int parameter, int max, int min)
{
	while (1) {
		
		try {
			std::cout << whattoinput;
			std::cin >> parameter;
			if (std::cin.fail()) {

				std::cin.clear();

				while (std::cin.get() != '\n');
				throw exception(wrongvalue);
			}
			else if ((std::cin.peek() != '\n') || (parameter > max) || (parameter < min)) {
				while (std::cin.get() != '\n');
				throw exception(wrongvalue);
			}
			break;
		}
		catch (exception& inputexception) {
			std::cout << inputexception.what();
		}
	}
	return parameter;
}

void window::function(snake i, symbol actualsymbol, column actualcolumn, window tab)
{
	

	

	actualsymbol.setcharacter(' ');
	while (((actualsymbol.getcharacter() < 33) && (actualsymbol.getcharacter() > -1)) || (actualsymbol.getcharacter() == 127)) {
		actualsymbol.setcharacter(rand() % 256);
	}
	
	gotoxy(i.getxposition(), i.gethead());
	if (colorscheme == 2) {

		actualsymbol.color(actualsymbol.randomisingcolor(actualcolumn.gethead_position(), actualcolumn.getcurrent_column()), Black);
	}
	else {
		actualsymbol.color(actualsymbol.fixedcolor(actualcolumn.gethead_position(), actualcolumn.getcurrent_column(), tab), Black);
	}

	std::cout << actualsymbol.getcharacter(); 

}

void window::addnewcolumn(snake newelement, int newcolumn, container<snake> *snakesadress)
{
	newelement.settime(clock());
	newelement.sethead(0);
	newelement.settail(0);
	
	newelement.setxposition(newcolumn);
	newelement.setnumber(snakesadress->getlengthofarray() + 1);
	int num = newelement.getnumber();
	snakesadress->addelement("last", newelement);
}










