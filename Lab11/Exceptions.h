#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

using namespace std;

namespace exceptions {
	class CMyException {
	public:
		CMyException(int, string);
		int getErrorCode();
		string getFuncName();
		wstring getDefinition();
		void output();
	protected:
		int errorCode;
		string funcName;
		wstring definition;
	};

	class CMyException1 : public CMyException {
	public:
		CMyException1(int, string, wstring);
		void output();
	private:
		wstring name;
	};

	class CMyException2 : public CMyException {
	public:
		CMyException2(int, string, wchar_t);
		void output();
	private:
		wchar_t value;
	};
}

#endif