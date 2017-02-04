#include "string"
#include "Exceptions.h"
#include "iostream"

using namespace std;

exceptions::CMyException::CMyException(int errorCode = (-1), string funcName = "none") {
	this->errorCode = errorCode;
	this->funcName = funcName;
	this->definition.assign(L"В ходе работы программы произошла ошибка.");
}

wstring exceptions::CMyException::getDefinition() {
	return definition;
}

string exceptions::CMyException::getFuncName() {
	return funcName;
}

int exceptions::CMyException::getErrorCode() {
	return errorCode;
}

void exceptions::CMyException::output() {
	wcout << endl << L"Код ошибки: " << errorCode
		<< endl << L"Функция-источник ошибки: " << funcName.data()
		<< endl << L"Описание: '" << definition
		<< L"'" << endl;
}

exceptions::CMyException1::CMyException1(int errorCode, string funcName, wstring alertName) {
	this->errorCode = errorCode;
	this->funcName = funcName;
	this->name = alertName;
	definition.assign(L"Ошибка: Недопустимое имя файла");
}

void exceptions::CMyException1::output() {
	CMyException::output();
	wcout << L"Непрошедшая проверку комбинация символов: " << name << endl;
}

exceptions::CMyException2::CMyException2(int errorCode, string funcName, wchar_t value) {
	this->errorCode = errorCode;
	this->funcName = funcName;
	this->value = value;
	definition.assign(L"Ошибка: Чтение по смещению в файле в диапазоне 0x10 – 0x20.");
}
void exceptions::CMyException2::output() {
	CMyException::output();
	wcout << L"Значение, попавшее в диапазон: '" << value << "'"<< endl;
}