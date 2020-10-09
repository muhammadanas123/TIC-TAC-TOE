#include<iostream>
using namespace std;
char matrix[3][3]={'-','-','-','-','-','-','-','-','-'};
char Owins()
{
	for(int i=0;i<3;i++)
	{
		if(matrix[i][0]=='O' and matrix[i][1]=='O'and matrix[i][2]=='O')
	{
         return 'O';
	}
	else if(matrix[0][i]=='O' and matrix[1][i]=='O' and matrix[2][i]=='O')
	{
		return 'O';
	}
	else if(matrix[0][0]=='O' and matrix[1][1]=='O' and matrix[2][2]=='O')
	{
		return 'O';
	}
	else if(matrix[0][2]=='O' and matrix[1][1]=='O' and matrix[2][0]=='O')
	{
		return 'O';
	}
} 

	return 'D';

}

char Xwins()
{
	for(int i=0;i<3;i++)
	{
		if(matrix[i][0]=='X' and matrix[i][1]=='X'and matrix[i][2]=='X')
	{
         	return 'X';
	}
	else if(matrix[0][i]=='X' and matrix[1][i]=='X' and matrix[2][i]=='X')
	{
			return 'X';
	}
	else if(matrix[0][0]=='X' and matrix[1][1]=='X' and matrix[2][2]=='X')
	{
			return 'X';
	}
	else if(matrix[0][2]=='X' and matrix[1][1]=='X' and matrix[2][0]=='X')
	{
			return 'X';
	}
	
	}
			return 'D';
}
