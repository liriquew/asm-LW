#include <iostream>

extern "C" void ODDWORDS(char*, char*);


int main() {
	char array1[] = "Hello world for i in range 10";
	char array2[20];

	ODDWORDS(array1, array2);

	char* p = array2;
	int a;
	while (*p != 0) {
		std::cout << (char)*p;
		p++;
	}
	std::cout << std::endl;
	p = array1;
	while (*p != 0) {
		std::cout << (char)*p;
		p++;
	}
}