#include "stdio.h"
#include "functions.h"
#include <locale>
#include <iostream>
#include <conio.h>

void main() {
	locale::global(locale("Russian"));
	do {
		cout << "-----------------------" << endl;
		functions::FuncHandle();
		wcout << endl << L"Нажмите любую клавишу для продолжения или Esc для выхода..." << endl << endl;
	} while (_getch() != 27); //Wait 'Esc' button
}