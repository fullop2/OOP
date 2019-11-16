#include "Integer.h"
#include "Float.h"
#include "Complex.h"
#include "testlist.h"
#include <iostream>

int test_int_add(){
	int result = 0;
	{
		Number* a = new Integer(3); 
		int x = 3;
		int y = 2;
		int z = x + y;
		a = a->add(new Integer(y));
		
		Integer* res = dynamic_cast<Integer*>(a);
		if(z != res->val()){
			result++;
		}
	}
	{
		Number* a = new Integer(3);
		int x = 3;
		float y = 2;
		float z = x + y;
		a = a->add(new Float(y));

		Float* res = dynamic_cast<Float*>(a);
		if(z != res->val())
		{
			result++;
		}
	}
	{
		Number* a = new Integer(3);
		int x = 3;
		float real = 3;
		float imag = 2;

		float res_real = x + real;
		float res_imag = imag;

		a = a->add(new Complex(real,imag));

		Complex* res = dynamic_cast<Complex*>(a);
		if(res_real != res->real() || res_imag != res->imag())
		{
			result++;
		}
	}
	return result;
}
int test_int_sub(){
	int result = 0;
	{
		Number* a = new Integer(3); 
		int x = 3;
		int y = 2;
		int z = x - y;
		a = a->sub(new Integer(y));
		
		Integer* res = dynamic_cast<Integer*>(a);
		if(z != res->val()){
			result++;
		}
	}
	{
		Number* a = new Integer(3);
		int x = 3;
		float y = 2;
		float z = x - y;
		a = a->sub(new Float(y));

		Float* res = dynamic_cast<Float*>(a);
		if(z != res->val())
		{
			result++;
		}
	}
	{
		Number* a = new Integer(3);
		int x = 3;
		float real = 3;
		float imag = 2;

		float res_real = x - real;
		float res_imag = imag;

		a = a->sub(new Complex(real,imag));

		Complex* res = dynamic_cast<Complex*>(a);
		if(res_real != res->real() || res_imag != res->imag())
		{
			result++;
		}
	}
	return result;
}
int test_int_mul(){
	int result = 0;
	{
		Number* a = new Integer(3); 
		int x = 3;
		int y = 2;
		int z = x * y;
		a = a->mul(new Integer(y));

		Integer* res = dynamic_cast<Integer*>(a);
		if(z != res->val()){
			std::cout << "Int * Int" << std::endl;
			result++;
		}
	}
	{
		Number* a = new Integer(3);
		int x = 3;
		float y = 2;
		float z = x * y;
		a = a->mul(new Float(y));
		Float* res = dynamic_cast<Float*>(a);
		if(z != res->val())
		{
			std::cout << "Int * Float" << std::endl;
			result++;
		}
	}
	{
		Number* a = new Integer(3);
		int x = 3;
		float real = 3;
		float imag = 2;

		float res_real = x * real;
		float res_imag = x * imag;

		a = a->mul(new Complex(real,imag));
		Complex* res = dynamic_cast<Complex*>(a);
		if(res_real != res->real() || res_imag != res->imag())
		{
			std::cout << "Int * Complex" << std::endl;
			result++;
		}
	}
	return result;
}
int test_int_div(){
	int result = 0;
	{
		Number* a = new Integer(3); 
		int x = 3;
		int y = 2;
		int z = x / y;
		a = a->div(new Integer(y));
		Integer* res = dynamic_cast<Integer*>(a);
		if(z != res->val()){
			result++;
		}
	}
	{
		Number* a = new Integer(3);
		int x = 3;
		float y = 2;
		float z = x / y;
		a = a->div(new Float(y));
		Float* res = dynamic_cast<Float*>(a);
		if(z != res->val())
		{
			result++;
		}
	}
	{
		// nothing to do
	}
	return result;
}
//int test_int_rand()

int test_float_add(){

	return 0;
}
int test_float_sub(){
	return 0;
}
int test_float_mul(){

	return 0;
}
int test_float_div(){
	
	return 0;
}
//int test_int_rand();

int test_comp_add(){

	return 0;
}
int test_comp_sub(){

	return 0;
}
int test_comp_mul(){

	return 0;
}
int test_comp_div(){

	return 0;
}
//int test_comp_rand();
