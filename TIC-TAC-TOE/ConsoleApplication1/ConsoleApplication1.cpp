#include "stdafx.h"
#include<iostream>
using namespace System;
using namespace std;
using namespace Threading;
char board[3][3];
int rowno = 0;
int colno = 0;
char sym;
int turns = 0;
void resetboard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = '-';
		}
	}
}
void box(int x,int y,int size)
{
		for (int i = 0; i < size; i++)
		{
			Console::SetCursorPosition(x+i, y);
			putchar('*');
		}
		for (int i = 0; i < size; i++)
		{
			Console::SetCursorPosition(x, y + i);
			putchar('*');
			putchar('\n');
		}
		for(int i=0;i<size;i++)
		{
			Console::SetCursorPosition(x+size,y + i);
			putchar('*');
			putchar('\n');
		}
		for (int i = 0; i < size; i++)
		{
			Console::SetCursorPosition(x+i, y + size);
			putchar('*');
		}
		putchar('*');
}
void drawboard(int x, int y, int size, int rows,int cols)
{
	Console::Clear();
	int cx = x + size / 2;
	int cy = y + size / 2;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			box(x + (j*size - 1), y + (i*size - 1), size);
			Console::SetCursorPosition(cx + (i*size - 1), cy + (j*size - 1));
			putchar(board[i][j]);
		}
	}
	Console::SetCursorPosition(x, y + (size * 4));
}
void getinput(int x, int y, int size)
{
	Console::SetCursorPosition(x, y + (size * 4));
	cout << "enter row no:-";
	cin >> colno;
	colno--;
	Console::SetCursorPosition(x, y + (size * 4)+1);
	cout << "enter coloumn no:-";
	cin >> rowno;
	rowno--;
	Console::SetCursorPosition(x, y + 30);
}
int r1(char sym)
{
	if(board[0][0]==sym&&board[0][1]==sym&&board[0][2]==sym)
	{
		turns = 100;
		Console::SetCursorPosition(25,25);
		Console::Clear();
		cout << "Player " << sym << " WINS" << endl;
		return 1;
	}
	else return 0;
}
int r2(char sym)
{
	if (board[1][0] == sym && board[1][1] == sym && board[1][2] == sym)
	{
		turns = 100;
		Console::SetCursorPosition(25, 25);
		Console::Clear();
		cout << "Player " << sym << " WINS" << endl;
		return 1;
	}
	else return 0;
}
int r3(char sym)
{
	if (board[2][0
] == sym && board[2][1] == sym && board[2][2] == sym)
	{
		turns = 100;
		Console::SetCursorPosition(25, 25);
		Console::Clear();
		cout << "Player " << sym << " WINS" << endl;
		return 1;
	}
	else return 0;
}
int c1(char sym)
{
	if (board[0][0] == sym && board[1][0] == sym && board[2][0]==sym)
	{
		turns = 100;
		Console::SetCursorPosition(25, 25);
		Console::Clear();
		cout << "Player " << sym << " WINS" << endl;
		return 1;
	}
	else return 0;
}
int c2(char sym)
{
	if (board[0][1] == sym && board[1][1] == sym && board[2][1] == sym)
	{
		turns = 100;
		Console::SetCursorPosition(25, 25);
		Console::Clear();
		cout << "Player " << sym << " WINS" << endl;
		return 1;
	}
	else return 0;
}
int c3(char sym)
{
	if (board[0][2] == sym && board[1][2] == sym && board[2][2] == sym)
	{
		turns = 100;
		Console::SetCursorPosition(25, 25);
		Console::Clear();
		cout << "Player " << sym << " WINS" << endl;
		return 1;
	}
	else return 0;
}
int d1(char sym)
{
	if (board[0][0] == sym && board[1][1] == sym && board[2][2] == sym)
	{
		turns = 100;
		Console::SetCursorPosition(25, 25);
		Console::Clear();
		cout << "Player " << sym << " WINS" << endl;
		return 1;
	}
	else return 0;
}
int d2(char sym)
{
	if (board[0][2] == sym && board[1][1] == sym && board[2][0] == sym)
	{
		turns = 100;
		Console::SetCursorPosition(25, 25);
		Console::Clear();
		cout << "Player " << sym << " WINS" << endl;
		return 1;
	}
	else return 0;
}
int test(char sym)
{
	int p1 = 0;
	int p2 = 0;
	int p3 = 0;
	int p4 = 0;
	int p5 = 0;
	int p6 = 0;
	int p7 = 0;
	int p8 = 0;
	p1=r1(sym);
	p2=r2(sym);
	p3=r3(sym);
	p4=c1(sym);
	p5=c2(sym);
	p6=c3(sym);
	p7=d1(sym);
	p8=d2(sym);
	if (p1 == 1 || p2 == 1 || p3 == 1 || p4 == 1 || p5 == 1 || p6 == 1 || p7 == 1 || p8 == 1)
	{
		return 1;
	}
	else return 0;
}
char menu()
{
	char a;
	Console::ForegroundColor = ConsoleColor::Yellow;
	Console::SetCursorPosition(5, 5);
	cout << "WELCOME TO TIC-TAC-TOE" << endl;
	Console::ResetColor();
	Thread::Sleep(500);
	cout << "press y to continue & n to exit:-";
	cin >> a;
	Thread::Sleep(100);
	Console::Clear();
	return a;
	
}
int main()
{
	char a=menu();
	while (a != 'n')
	{
		resetboard();
		drawboard(5, 5, 5, 3, 3);
		getinput(5, 5, 5);
		while (turns < 8)
		{
			if (rowno >= 0 && rowno <= 2 && colno >= 0 && colno <= 2)
			{
				if (board[rowno][colno] == '-')
				{
					if (turns % 2 == 0)
					{
						sym = 'x';
					}
					else
					{
						sym = 'o';
					}
					board[rowno][colno] = sym;
					drawboard(5, 5, 5, 3, 3);
					if (test(sym) == 1)
					{
						break;
					}
					getinput(5, 5, 5);
					turns++;
				}
				else
				{
					Console::ForegroundColor = ConsoleColor::Red;
					cout << "invalid move";
					Console::ResetColor();
					Thread::Sleep(500);
					Console::SetCursorPosition(19, 25);
					putchar(' ');
					Console::SetCursorPosition(23, 26);
					putchar(' ');
					getinput(5, 5, 5);
				}
			}
			else
			{
				Console::ForegroundColor = ConsoleColor::Red;
				cout << "out of bounds";
				Console::ResetColor();
				Thread::Sleep(500);
				Console::SetCursorPosition(19, 25);
				putchar(' ');
				Console::SetCursorPosition(23, 26);
				putchar(' ');
				getinput(5, 5, 5);
			}
		}
		Thread::Sleep(500);
		Console::Clear();
		Console::SetCursorPosition(15, 15);
		Console::ForegroundColor = ConsoleColor::DarkCyan;
		cout << "GAME OVER" << endl;
		Console::ResetColor();
		Thread::Sleep(2000);
		Console::Clear();
		a = menu();
	}

}
