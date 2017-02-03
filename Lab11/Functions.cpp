#include "iostream"
#include "fstream"
#include "string"
#include "functions.h"
#include "Exceptions.h"

using namespace std;
using namespace exceptions;

ifstream* functions::Func1() {
	wstring fileName;
	//int offset;
	wstring testName;

	wcout << L"¬ведите название файла: ";
	getline(wcin, fileName);
	if (fileName.length() >= 4) {
		testName.assign(fileName.substr(0, 4));
		if (testName.compare(L"name") == 0) {
			//throw 0; //TO DO: добавить вызов классов - исключений
			throw CMyException(0,"Func1()");
		}
		testName.assign(fileName.substr(fileName.size() - 4, fileName.size() - 1));
		if (testName.compare(L".xml") == 0) {
			//throw 0; //TO DO: добавить вызов классов-исключений
			throw CMyException1(0, "Func1()");
		}
	}

	ifstream* file = new ifstream(fileName);
	if (file->fail()) {
		throw 1; //TO DO: добавить вызов классов-исключений
	}
	return file;
}

ifstream* functions::Func2(ifstream* file) {
	char* byte;

	while (!file->eof()) {
		file->read(byte, 1);
		if ((*byte >= 0x10) || (*byte <= 0x20)) {
			throw CMyException2(1, "Func2()");
		}
	}

	return file;
}

void functions::Func3(ifstream* file) {
	if (file->seekg > 0x400) {
		throw CMyException2(2, "Func3()");
	}
	file->close();
	
	delete file;
}

void functions::FuncHandle() {
	ifstream* file;

	file = Func1();
	//file = Func2(file);
	//Func3(file);

	delete file;
}