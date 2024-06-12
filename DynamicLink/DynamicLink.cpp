#include <stdlib.h>
#include <iostream>
#include <windows.h>

using namespace std;
typedef void(*LibraryFunction)(char*, char*);

// 11.	Сформировать строку из нечётных слов исходной строки

void main() {
	setlocale(LC_ALL, "rus");
	HINSTANCE hLib;
	LibraryFunction f;
	hLib = LoadLibrary(TEXT("..\\LW5\\algorithm.dll"));
	if (hLib == NULL) {
		std::cout << "Библиотека не найдена!\n";
		return;
	}
	f = (LibraryFunction)GetProcAddress(hLib, "ODDWORDS");
	if (!f)
		std::cout << "Функция ODDWORDS не найдена\n\n";
	else {
		char str[256], res[256];
		cout << "Программа, динамически подключающая библиотеку\n";
		cout << "Строка : ";
		cin.get(str, 256);
		if (strlen(str) == 0) { cout << "Пустая строка!\n"; }
		else {
			f(str, res);
			cout << "Строка из нечетных слов: ";
			char* p = res;

			while (*p != 0) {
				cout << *p;
				p++;
			}
			cout << '\n';
		}
	}
	system("pause");
	FreeLibrary(hLib);
	return;
}