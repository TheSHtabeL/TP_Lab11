#include "string"
#include "Exceptions.h"

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

exceptions::CMyException1::CMyException1(int errorCode, string funcName) {
	CMyException(errorCode, funcName);
	definition.assign(L"Ошибка: Недопустимое имя файла");
}