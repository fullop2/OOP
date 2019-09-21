#include <iostream>

int main()
{
	char * a = "ABC";
	char b[] = "ABC";

	*(a+1) = 'x';
	b[1] = 'b';
	std::cout <<  a << std::endl;
	std::cout << b << std::endl;

	return 0;
}
