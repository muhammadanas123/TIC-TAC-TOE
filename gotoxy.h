#include<iostream>
#include<windows.h>
using namespace std;
void gotoxy(int x,int y)
{
	COORD coord={3,3};
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);         
}
