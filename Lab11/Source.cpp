#include "stdio.h"
#include "functions.h"
#include <locale>
#include <iostream>
#include <conio.h>

void wait();

void main() {
	locale::global(locale("Russian"));
	functions::FuncHandle();
	wait();
}

void wait() {
	wcout << endl << L"Нажмите любую клавишу для продолжения..." << endl;
	_getch();
}