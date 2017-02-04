#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"
#include "Exceptions.h"

using namespace std;
using namespace exceptions;

wifstream* functions::Func1() {
	/*Функция открытия файла в директории программы. Проверка на корректные название файла (!="name")
	и расширение (!=".xml")*/
	wstring fileName;
	wstring testName;
	wifstream* file;

	wcout << L"Введите название файла: ";
	getline(wcin, fileName);
	if (fileName.length() >= 5) {
		testName.assign(fileName.substr(0, 5));
		if (testName.compare(L"name.") == 0) {
			throw CMyException(0,"Func1()");
		}
		testName.assign(fileName.substr(fileName.size() - 4, fileName.size() - 1));
		if (testName.compare(L".xml") == 0) {
			throw CMyException1(1, "Func1()", fileName);
		}
	}
	else if(fileName.length() == 4){
		testName.assign(fileName.substr(0, 4));
		if (testName.compare(L"name") == 0) {
			throw CMyException(0, "Func1()");
		}
	}

	file = new wifstream(fileName);
	if (file->fail()) {
		throw CMyException(2, "Func1()");
	}
	
	return file;
}

wifstream* functions::Func2(wifstream* file) {
	wchar_t* byte = new wchar_t[1];
	wstring buffer = L"";

	while (file->read(byte, 1)) {
		buffer.push_back(*byte); //Чтение одного символа из файла
		if ((*byte >= 0x10) && (*byte <= 0x20)) {
			file->close();
			delete file;
			throw CMyException2(3, "Func2()", *byte);
		}
	}
	cout << endl << "Чтение прошло успешно. Прочитанные данные:" << endl;
	wcout << buffer << endl;

	return file;
}

void functions::Func3(wifstream* file) {
	file->clear(); //Очищаем флаги потока, чтобы получить доступ к курсору
	if (file->tellg() > 0x400) {
		file->close();
		delete file;
		throw CMyException(4, "Func3()");
	}

	file->close();
	delete file;
}

void functions::FuncHandle() {
	wifstream* file;

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