#include <cstdio>
#include <iostream>
#include "windows.h"

using namespace std;

#pragma comment(lib, "..\\LW5\\algorithm.lib")

extern "C" __declspec(dllimport) void ODDWORDS(char*, char*);

// 11.	Сформировать строку из нечётных слов исходной строки

int main() {
	setlocale(LC_ALL, "ru");
	char str[256], res[256];
	cout << "Программа, статически подключающая библиотеку\n";
	cout << "Строка : ";
	cin.get(str, 256);
	if (strlen(str) == 0) { cout << "Пустая строка!\n"; }
	else {
		ODDWORDS(str, res);
		cout << "Строка из нечетных слов: ";
		char* p = res;

		while (*p != 0) {
			cout << *p;
			p++;
		}
		cout << '\n';
	}
	system("pause");
	return 0;
}