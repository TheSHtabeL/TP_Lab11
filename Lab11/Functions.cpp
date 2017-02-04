#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"
#include "Exceptions.h"

using namespace std;
using namespace exceptions;

ifstream* functions::Func1() {
	/*Функция открытия файла в директории программы. Проверка на корректные название файла (!="name")
	и расширение (!=".xml")*/
	wstring fileName;
	wstring testName;
	ifstream* file;

	wcout << L"Введите название файла: ";
	getline(wcin, fileName);
	if (fileName.length() >= 5) {
		testName.assign(fileName.substr(0, 5));
		if (testName.compare(L"name.") == 0) {
			throw CMyException(0,"Func1()");
		}
		testName.assign(fileName.substr(fileName.size() - 4, fileName.size() - 1));
		if (testName.compare(L".xml") == 0) {
			throw CMyException1(1, "Func1()");
		}
	}
	else if(fileName.length() == 4){
		testName.assign(fileName.substr(0, 4));
		if (testName.compare(L"name") == 0) {
			throw CMyException(0, "Func1()");
		}
	}

	file = new ifstream(fileName);
	if (file->fail()) {
		throw CMyException(2, "Func1()");
	}
	
	return file;
}

ifstream* functions::Func2(ifstream* file) {
	char* byte = new char[1];
	
	while (!file->eof()) {
		file->read(byte, 1);
		if ((*byte >= 0x10) || (*byte <= 0x20)) {
			throw CMyException2(3, "Func2()");
		}
	}

	return file;
}

void functions::Func3(ifstream* file) {
	if (file->tellg() > 0x400) {
		throw CMyException(4, "Func3()");
	}

	file->close();
	delete file;
}

void functions::FuncHandle() {
	ifstream* file;

	try {
		file = Func1();
		file = Func2(file);
		Func3(file);
	}
	catch (CMyException1 Exc1) {
		Exc1.output();
	}
	catch (CMyException2 Exc2) {
		Exc2.output();
	}
	catch (CMyException Exc) {
		Exc.output();
	}
}