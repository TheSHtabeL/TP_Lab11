#include "string"
#include "Exceptions.h"
#include "iostream"

using namespace std;

exceptions::CMyException::CMyException(int errorCode = (-1), string funcName = "none") {
	this->errorCode = errorCode;
	this->funcName = funcName;
	this->definition.assign(L"� ���� ������ ��������� ��������� ������.");
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
	wcout << endl << L"��� ������: " << errorCode
		<< endl << L"�������-�������� ������: " << funcName.data()
		<< endl << L"��������: '" << definition
		<< L"'" << endl;
}

exceptions::CMyException1::CMyException1(int errorCode, string funcName) {
	this->errorCode = errorCode;
	this->funcName = funcName;
	definition.assign(L"������: ������������ ��� �����");
}

exceptions::CMyException2::CMyException2(int errorCode, string funcName) {
	this->errorCode = errorCode;
	this->funcName = funcName;
	definition.assign(L"������: ������ �� �������� � ����� � ��������� 0x10 � 0x20.");
}