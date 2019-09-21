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

void printLine()
{
	std::cout << "-----------------------------------------------------"<<std::endl;
}
void printAddr(const char* type,const void* ptr)
{
	std::cout << type << "\t" << ptr << "\t" << (long)ptr << std::endl;
}


foo* f(int b)
{
	foo a;
	a.bar = b;
	return &a;
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

	foo stack_localClass = foo();
	int stack_localInt = 1;
	foo* stack_localClassOtherFunction = f(3);

	printAddr("code",(void*)code_print);
	printLine();
	printAddr("rodata",rodata_ptrChar);
	printAddr("rodata",&rodata_int);
	printLine();
	printAddr("data",&data_globalFloat);
	printAddr("data",&data_localStaticFloat);
	printLine();
	printAddr("bss",&bss_globalDouble);
	printAddr("bss",&bss_localStaticInt);
	printLine();
	printAddr("heap",&heap_ptrInt[0]);
	printLine();
	printAddr("stack",&stack_localClassOtherFunction);
	printAddr("stack",&stack_localClass);
	printAddr("stack",&stack_localInt);



	delete[] heap_ptrInt;
	return 0;
}
