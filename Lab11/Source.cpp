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
		wcout << endl << L"������� ����� ������� ��� ����������� ��� Esc ��� ������..." << endl << endl;
	} while (_getch() != 27); //Wait 'Esc' button
}