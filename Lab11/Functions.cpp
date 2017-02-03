#include "iostream"
#include "fstream"
#include "string"
#include "functions.h"

using namespace std;

ifstream* functions::Func1() {
	wstring fileName;
	//int offset;
	wstring testName;

	wcout << L"¬ведите название файла: ";
	getline(wcin, fileName);
	if (fileName.length() >= 4) {
		testName.assign(fileName.substr(0, 4));
		if (testName.compare(L"name") == 0) {
			throw 0; //TO DO: добавить вызов классов - исключений
		}
		testName.assign(fileName.substr(fileName.size() - 4, fileName.size() - 1));
		if (testName.compare(L".xml") == 0) {
			throw 0; //TO DO: добавить вызов классов-исключений
		}
	}

	ifstream* file = new ifstream(fileName);
	if (file->fail()) {
		throw 1; //TO DO: добавить вызов классов-исключений
	}
	return file;
}

ifstream* functions::Func2(ifstream* file) {
	return file;
}

void functions::Func3(ifstream* file) {

}

void functions::FuncHandle() {
	ifstream* file;

	file = Func1();

	delete file;
}