#include <iostream>

void code_print(int x)
{
	std::cout << "I got " << x << std::endl;
}

class foo
{
	public:
		int bar;
};

int* localVariableAddress;

foo f(int b)
{
	foo a;
	a.bar = b;
	localVariableAddress = &b;
	return a;
}

float data_globalFloat = 2.71;
double bss_globalDouble;
int main()
{
	const char* rodata_ptrChar = "hello world";
	static const int rodata_int = 2;
	static float data_localStaticFloat = 3.14f;
	static int bss_localStaticInt;
	
	int* heap_ptrInt = new int[3];
	for(auto i = 0; i < 3; ++i)
		*(heap_ptrInt+i)=i*3+1;

	foo stack_localClass = f(3);
	int stack_localInt = 1;
	
	std::cout << "code\t" << (void*)code_print << std::endl;
	std::cout << "rodata\t" << (void*)rodata_ptrChar << std::endl;
	std::cout << "rodata\t" << (void*)&rodata_int << std::endl;
	std::cout << "data\t" << &data_globalFloat << std::endl;
	std::cout << "data\t" << &data_localStaticFloat << std::endl;
	std::cout << "bss\t" << &bss_globalDouble << std::endl;
	std::cout << "bss\t" << &bss_localStaticInt << std::endl;
	std::cout << "heap\t" << heap_ptrInt << std::endl;
	std::cout << "stack\t" << localVariableAddress << std::endl;
	std::cout << "stack\t" << &stack_localClass << std::endl;
	std::cout << "stack\t" << &stack_localInt << std::endl;
	
	delete[] heap_ptrInt;
	return 0;
}
