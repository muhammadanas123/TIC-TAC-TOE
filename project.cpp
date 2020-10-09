#include<iostream>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<string>
#include<windows.h>
#include <graphics.h>
#include<dos.h>
#include "TICTACK.h"
#include "gotoxy.h"
#include "wins.h"
using namespace std;
void TICTACK::declare()
{
	player='X';
}
void TICTACK::initializing()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			matrix[i][j]='-';
		}
	}
}
void TICTACK::toggleplayer()
{
	if(player=='X')
	{
		gotoxy(0,16);
		cout<<"Player O  Turns";
		player='O';
	}
	else
	{
	gotoxy(0,16);
	cout<<"Player X  Turns";
		player='X';
	}
}
void TICTACK::fileX(int x)
{
	ofstream file;
	file.open("fileX.txt",ios::trunc);
	file<<x<<endl;
	file.close();
}
void TICTACK::fileO(int x)
{
	ofstream file;
	file.open("fileO.txt",ios::trunc);
	file<<x<<endl;
	file.close();
}
void TICTACK::fileD(int x)
{
	ofstream file;
	file.open("fileD.txt",ios::trunc);
	file<<x<<endl;
	file.close();
}
void TICTACK::fileDopen()
{
	ifstream file;
	file.open("fileD.txt",ios::out);
	int count=0;
	int data;
	while(file>>data)
	{
		count=count+data;
	}
	gotoxy(0,13);
	cout<<"Number of games Drawn    : "<<count;
}

void TICTACK::fileXopen()
{
	ifstream file;
	file.open("fileX.txt",ios::out);
	int count=0;
	int data;
	while(file>>data)
	{
		count=count+data;
	}
	gotoxy(0,11);
	cout<<"Number of games X   wins : "<<count;
}
void TICTACK::fileOopen()
{
	ifstream file;
	file.open("fileO.txt",ios::out);
	int count=0;
	int data;
	while(file>>data)
	{
		count=count+data;
	}
	gotoxy(0,12);
	cout<<"Number of games O   wins : "<<count;
}

void TICTACK::displaystructure()
{
	gotoxy(40,14);
	cout<<"Tic Tac Toe Game";
	for(int i=0;i<3;i++)
	{
		
		gotoxy(40,15+i);
		cout<<"  ";
		for(int j=0;j<3;j++)
		{
			if(j==2)
			{
				cout<<matrix[i][j]<<"   ";
			}
			else{
			
			cout<<matrix[i][j]<<" | ";}
		}
		cout<<endl;
		cout<<endl;
	}
}
void TICTACK:: Gamemangment()
{
	fileXopen();
	fileOopen();
	fileDopen();
	gotoxy(0,16);
	cout<<"Player X  Turns";
	int x;
	for(int i=0;i<9;i++)
	{
	L1:
	gotoxy(40,20);
	cout<<"Enter position : ";
	cin>>x;
	gotoxy(41,20);
	cout<<" ";
	
	if(x>9)
	{
		goto L1;
	}
	if(x==1)
	{
		if(matrix[0][0]=='X' or matrix[0][0]=='O')
		{
			goto L1;
		}
		else
		{
		matrix[0][0]=player;
	}
	}
	else if(x==2)
	{
		if(matrix[0][1]=='X' or matrix[0][1]=='O')
		{
			goto L1;
		}
		else
		{
		matrix[0][1]=player;}
	}
	else if(x==3)
	{
		if(matrix[0][2]=='X' or matrix[0][2]=='O')
		{
			goto L1;
		}
		else
		{
		matrix[0][2]=player;
	}
	}
	else if(x==4)
	{
		if(matrix[1][0]=='X' or matrix[1][0]=='O')
		{
			goto L1;
		}
		else
		{
		matrix[1][0]=player;
	}
	}
	else if(x==5)
	{
		if(matrix[1][1]=='X' or matrix[1][1]=='O')
		{
			goto L1;
		}
		else
		{
		matrix[1][1]=player;
	}
	}
	else if(x==6)
	{
		if(matrix[1][2]=='X' or matrix[1][2]=='O')
		{
			goto L1;
		}
		else
		{
		matrix[1][2]=player;
	}
	}
	else if(x==7)
	{
		if(matrix[2][0]=='X' or matrix[2][0]=='O')
		{
			goto L1;
		}
		else
		{
		matrix[2][0]=player;
	}
	}
	else if(x==8)
	{
		if(matrix[2][1]=='X' or matrix[2][1]=='O')
		{
			goto L1;
		}
		else
		{
		matrix[2][1]=player;
	}
	}
	else if(x==9)
	{
		if(matrix[2][2]=='X' or matrix[2][2]=='O')
		{
			goto L1;
		}
		else
		{
		matrix[2][2]=player;
	}
	}
	displaystructure();
	toggleplayer();
	if(Xwins()=='X')
	{
		countX++;
		fileX(countX);
		gotoxy(0,16);
		cout<<"X  wins .        ";
		break;
	}
	else if(Owins()=='O')
	{
		countO++;
		fileO(countO);
		gotoxy(0,16);
		cout<<"O wins .        ";
		break;
	}
}
	if(Owins()=='D' and Xwins()=='D')
	{
		countD++;
		fileD(countD);
		gotoxy(0,16);
		cout<<"Match Drawn!!  ";
	}
}
	
int main(void)
{
	char x;
	system("color 2");
	TICTACK t1;
	gotoxy(47,6);
	cout<<"TICTACK TOE";
	gotoxy(50,2);
	cout<<"PLAY";
	gotoxy(49,3);
	cout<<"******";
	gotoxy(49,1);
	cout<<"******";
	gotoxy(49,2);
	cout<<"*";
	gotoxy(54,2);
	cout<<"*";
	HANDLE hout= GetStdHandle(STD_OUTPUT_HANDLE);
        HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
        INPUT_RECORD InputRecord;
        DWORD Events;
        COORD coord;
        CONSOLE_CURSOR_INFO cci;
        cci.dwSize = 25;
        cci.bVisible = FALSE;
        SetConsoleCursorInfo(hout, &cci);
        SetConsoleMode(hin, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
        bool EXITGAME = false;
        int buttonX=0, buttonY=1;


        
    while( !EXITGAME )
    {
        ReadConsoleInput(hin, &InputRecord, 1, &Events);
        switch ( InputRecord.EventType ){
                case KEY_EVENT: // keyboard input 
               
                case MOUSE_EVENT: // mouse input 

                    if(InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
                    {
                        coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
                        coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
                        SetConsoleCursorPosition(hout,coord);
                        SetConsoleTextAttribute(hout,rand() %7+9);
						
                        if ( (InputRecord.Event.MouseEvent.dwMousePosition.X == buttonX ) && 
                            ( InputRecord.Event.MouseEvent.dwMousePosition.Y == buttonY) ){

                           
                 
                           
                        }

                        //cout<<"Hello Iam here! "<< InputRecord.Event.MouseEvent.dwMousePosition.X <<" x "<< InputRecord.Event.MouseEvent.dwMousePosition.Y<<" ";
for(int i=50;i<=53;i++)
{
						
if(InputRecord.Event.MouseEvent.dwMousePosition.Y == 2 and  InputRecord.Event.MouseEvent.dwMousePosition.X==i)
					{
						do
{
    system ("cls");
	t1.initializing();
	t1.declare();
	t1.displaystructure();
	t1.Gamemangment();
	t1.displaystructure();
	cout<<"Restart game : ";
	cin>>x;
}while(x!='N');
system("pause");
}
					
					}
                    }// mouse 

                    //break; 
		}
}
	return 0;
}
