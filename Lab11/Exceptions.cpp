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

exceptions::CMyException1::CMyException1(int errorCode, string funcName, wstring alertName) {
	this->errorCode = errorCode;
	this->funcName = funcName;
	this->name = alertName;
	definition.assign(L"������: ������������ ��� �����");
}

void exceptions::CMyException1::output() {
	CMyException::output();
	wcout << L"����������� �������� ���������� ��������: " << name << endl;
}

exceptions::CMyException2::CMyException2(int errorCode, string funcName, wchar_t value) {
	this->errorCode = errorCode;
	this->funcName = funcName;
	this->value = value;
	definition.assign(L"������: ������ �� �������� � ����� � ��������� 0x10 � 0x20.");
}
void exceptions::CMyException2::output() {
	CMyException::output();
	wcout << L"��������, �������� � ��������: '" << value << "'"<< endl;
}