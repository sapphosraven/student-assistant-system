
#include "colorprint.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>

void printred(char *col)
{
	 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,
    FOREGROUND_RED);
  	printf("%s", col);
  	SetConsoleTextAttribute(hConsole,
    FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	
}

void printblue(char *col)
{
	 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,
    FOREGROUND_BLUE);
  	printf("%s", col);
  	SetConsoleTextAttribute(hConsole,
    FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	
}
void printgreen(char *col)
{
	 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,
    FOREGROUND_GREEN);
  	printf("%s", col);
  	SetConsoleTextAttribute(hConsole,
    FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	
}
void printyellow(char *col)
{
	 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,
    FOREGROUND_RED | FOREGROUND_GREEN);
  	printf("%s", col);
  	SetConsoleTextAttribute(hConsole,
    FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	
}
void printpurple(char *col)
{
	 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,
    FOREGROUND_RED | FOREGROUND_BLUE);
  	printf("%s", col);
  	SetConsoleTextAttribute(hConsole,
    FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	
}

void printHighRed(char *col)
{
	 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,
    BACKGROUND_RED);
  	printf("%s", col);
  	SetConsoleTextAttribute(hConsole,
    FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	
}

