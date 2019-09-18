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

	std::cout << 	"code\tmain\t" << (void*)main << std::endl << 
			"rodata\tcopy+0\t" << (void*)copy << " " << copy[0] << std::endl <<
			"heap\tc[0]\t" << (void*)&c[0] << " " << c[0] << std::endl <<
			"heap\tc[602]\t" << (void*)&c[602] << " " << c[602] << std::endl << 
			"stack\ttarget\t" << &target << " "  << (long)&target << " " << target[0] << std::endl <<
			"stack\tb\t" << &b[0] << " " <<(long)&b[0] << " " << b[0] << std::endl <<
			"stack\tb+32\t" <<b+32 << " " << (long)(b+32) << " " << *(b+32) << std::endl <<
			"stack\ta\t"<< &a <<  " " << (long)&a << " " << a << std::endl <<
			"stack\ti\t"<< &i <<  " " << (long)&i << " " << i << std::endl <<
			"stack\tc\t"<< &c <<  " " << (long)&c << " " << c[0] << std::endl <<
			"stack\tcopy\t"<< &copy << " " << (long)&copy << " " << copy[0] << std::endl <<
			"stack\tname\t"<< (void*)&name <<  " "  << (long)&name << " " << name << std::endl;
	std::cout << &name + i << " " << i <<  std::endl;
	
	return 0;
}

