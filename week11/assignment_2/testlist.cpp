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
	int result = 0;
	{
		Number* a = new Float(3); 
		float x = 3;
		int y = 2;
		float z = x + y;
		a = a->add(new Integer(y));
		
		Float* res = dynamic_cast<Float*>(a);
		if(z != res->val()){
			result++;
		}
	}
	{
		Number* a = new Float(3);
		float x = 3;
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
		Number* a = new Float(3);
		float x = 3;
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
int test_float_sub(){
	int result = 0;
	{
		Number* a = new Float(3); 
		float x = 3;
		int y = 2;
		float z = x - y;
		a = a->sub(new Integer(y));
		
		Float* res = dynamic_cast<Float*>(a);
		if(z != res->val()){
			result++;
		}
	}
	{
		Number* a = new Float(3);
		float x = 3;
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
		Number* a = new Float(3);
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
int test_float_mul(){
	int result = 0;
	{
		Number* a = new Float(3); 
		float x = 3;
		int y = 2;
		float z = x * y;
		a = a->mul(new Float(y));

		Float* res = dynamic_cast<Float*>(a);
		if(z != res->val()){
			std::cout << "Float * Int" << std::endl;
			result++;
		}
	}
	{
		Number* a = new Float(3);
		float x = 3;
		float y = 2;
		float z = x * y;
		a = a->mul(new Float(y));
		Float* res = dynamic_cast<Float*>(a);
		if(z != res->val())
		{
			result++;
		}
	}
	{
		Number* a = new Float(3);
		float x = 3;
		float real = 3;
		float imag = 2;

		float res_real = x * real;
		float res_imag = x * imag;

		a = a->mul(new Complex(real,imag));
		Complex* res = dynamic_cast<Complex*>(a);
		if(res_real != res->real() || res_imag != res->imag())
		{
			result++;
		}
	}
	return result;
}
int test_float_div(){
	int result = 0;
	{
		Number* a = new Float(3); 
		float x = 3;
		int y = 2;
		float z = x / y;
		a = a->div(new Integer(y));
		Float* res = dynamic_cast<Float*>(a);
		if(z != res->val()){
			std::cout << "Float * Float" <<std::endl << z << ", " << res->val() << std::endl;
			std::cout << "Float / Int" << std::endl;
			result++;
		}
	}
	{
		Number* a = new Float(3);
		float x = 3;
		float y = 2;
		float z = x / y;
		a = a->div(new Float(y));
		Float* res = dynamic_cast<Float*>(a);
		if(z != res->val())
		{
			std::cout << "Float * Float" <<std::endl << z << ", " << res->val() << std::endl;
			result++;
		}
	}
	{
		// nothing to do
	}
	return result;
}


int test_comp_add(){
	int result = 0;
	{
		Number* a = new Complex(5,4);
		float real = 5, imag = 4;

		int y = 2;

		real += y;
		a = a->add(new Integer(y));

		Complex* res = dynamic_cast<Complex*>(a);
		if(real != res->real() || imag != res->imag()){
			result++;
		}
	}
	{
		Number* a = new Complex(5,4);
		float real = 5, imag = 4;

		float y = 2;

		real += y;
		a = a->add(new Float(y));
		
		Complex* res = dynamic_cast<Complex*>(a);
		if(real != res->real() || imag != res->imag()){
			result++;
		}
	}
	{
		Number* a = new Complex(5,4);
		float real = 5, imag = 4;

		float rhs_real = 2, rhs_imag = 3;

		
		real+=rhs_real; imag+=rhs_imag;
		a = a->add(new Complex(rhs_real,rhs_imag));
		
		Complex* res = dynamic_cast<Complex*>(a);
		if(real != res->real() || imag != res->imag()){
			result++;
		}
	}
	return result;
}

int test_comp_sub(){
	int result = 0;
	{
		Number* a = new Complex(5,4);
		float real = 5, imag = 4;

		int y = 2;

		real -= y;
		a = a->sub(new Integer(y));

		Complex* res = dynamic_cast<Complex*>(a);
		if(real != res->real() || imag != res->imag()){
			result++;
		}
	}
	{
		Number* a = new Complex(5,4);
		float real = 5, imag = 4;

		float y = 2;

		real -= y;
		a = a->sub(new Float(y));
		
		Complex* res = dynamic_cast<Complex*>(a);
		if(real != res->real() || imag != res->imag()){
			result++;
		}
	}
	{
		Number* a = new Complex(5,4);
		float real = 5, imag = 4;

		float rhs_real = 2, rhs_imag = 3;

		
		real-=rhs_real; imag-=rhs_imag;
		a = a->sub(new Complex(rhs_real,rhs_imag));
		
		Complex* res = dynamic_cast<Complex*>(a);
		if(real != res->real() || imag != res->imag()){
			result++;
		}
	}
	return result;
}

int test_comp_mul(){
	int result = 0;
	{
		Number* a = new Complex(5,4);
		float real = 5, imag = 4;

		int y = 2;

		real *= y; imag*= y;
		a = a->mul(new Integer(y));

		Complex* res = dynamic_cast<Complex*>(a);
		if(real != res->real() || imag != res->imag()){
			std::cout << "Complex * Int" << std::endl;
			result++;
		}
	}
	{
		Number* a = new Complex(5,4);
		float real = 5, imag = 4;

		float y = 2;

		real *= y; imag *= y;
		a = a->mul(new Float(y));
		
		Complex* res = dynamic_cast<Complex*>(a);
		if(real != res->real() || imag != res->imag()){
			std::cout << "Complex * Float" << std::endl;
			result++;
		}
	}
	{
		Number* a = new Complex(5,4);
		float real = 5, imag = 4;

		float rhs_real = 2, rhs_imag = 3;

		
		float res_real = (real * rhs_real) - (imag * rhs_imag);
		float res_imag = (real * rhs_imag) + (imag * rhs_real);
		a = a->mul(new Complex(rhs_real,rhs_imag));
		
		Complex* res = dynamic_cast<Complex*>(a);
		if(res_real != res->real() || res_imag != res->imag()){
			std::cout << "Complex * Complex" << std::endl;
			std::cout << real << " : " << res->real() << std::endl;
			std::cout << imag << " : " << res->imag() << std::endl;

			result++;
		}
	}
	return result;
}

int test_comp_div(){
	int result = 0;
	{
		Number* a = new Complex(5,4);
		float real = 5, imag = 4;

		int y = 2;

		real /= y; imag /= y;
		a = a->div(new Integer(y));

		Complex* res = dynamic_cast<Complex*>(a);
		if(real != res->real() || imag != res->imag()){
			std::cout << real << " : " << res->real() << std::endl;
			std::cout << imag << " : " << res->imag() << std::endl;


			result++;
		}
	}
	{
		Number* a = new Complex(5,4);
		float real = 5, imag = 4;

		float y = 2;

		real /= y; imag /= y;
		a = a->div(new Float(y));
		
		Complex* res = dynamic_cast<Complex*>(a);
		if(real != res->real() || imag != res->imag()){
			std::cout << real << " : " << res->real() << std::endl;
			std::cout << imag << " : " << res->imag() << std::endl;


			result++;
		}
	}

	return result;
}
