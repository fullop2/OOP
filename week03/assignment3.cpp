#include <iostream>

// sizeof long 8, int 4, char 1
// sizeof ptr 8

int main()
{
	char target[] = "Park Taehyun"; // char 13
	long b[4]; // long 4
	int a = 17; // int 1
	int i = 0; // int 1
	int *c = new int[602]; // int ptr 1
	char *copy = "is no no"; // char ptr 1
	char name = 'a'; // char 1
	
	i = (long)&target - (long)(void*)&name;

	std::cout << &name + i << " " << std::endl;
	
	return 0;
}

