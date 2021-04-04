// Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

/*
Реализовать внутренности функции (каждому по 1) в среде разработки Microsoft Visual C++.
Описания функций брать в Microsoft Solution Developers Network(MSDN).
18.memset
*/


#include <iostream>
#include <sstream>
#include <string>
#include <memory.h>

void msdn_example(char string[]) {

	printf("Before: %s\n", string);
	memset(string, '*', 1);
	printf("After: %s\n", string);

}

void *my_memset(void *dest, int c, size_t count) {

	int i;
	unsigned char* p = (unsigned char*)dest;
	i = 0;
	while (count > 0)
	{
		*p = c;
		p++;
		count--;
	}
	return dest;

}

void my_example(int val) {
	
	my_memset(&val, 0, 4);
	printf("%d\n", val);

}

void my_example(int arr[]) {
	//два первых элемента -> 0
	memset(arr, 0, 8);
	for (int i = 0; i < sizeof(arr); i++)
		printf("%d ", arr[i]);
}

int main()
{

	std::cout << "Enter string\n";
	char string[255];
	int i;
	char c;
	std::cin.getline(string, 255);
	std::cin >> c;
	std::cin >> i;
	my_memset(string, c, i);
	std::cout << string;
}