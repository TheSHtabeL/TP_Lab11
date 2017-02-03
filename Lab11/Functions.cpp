#include "iostream"
#include "fstream"
#include "string"
#include "functions.h"

using namespace std;

ifstream* Func1(){//string fileName) {
	wstring fileName;
	//int offset;
	wstring testName;

	cout << "¬ведите название файла: ";
	getline(wcin, fileName);
	testName.assign(fileName.substr(0, 4));

	ifstream* file = new ifstream("fdfd");
	return file;
}

void FuncHandle() {
	Func1();
}