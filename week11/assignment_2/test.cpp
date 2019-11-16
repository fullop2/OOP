//
// Created by 김혁진 on 2019/11/12.
//

#include "Integer.h"
#include "Float.h"
#include "Complex.h"
#include "testlist.h"
#include <iostream>
#include <assert.h>

int main() {

	{
		assert(test_int_add() == 0);
		assert(test_int_sub() == 0);
		assert(test_int_mul() == 0);
		assert(test_int_div() == 0);
	}
    {
        Number *a = new Integer(13);
        Number *result = a->add(new Float(3.14));

        std::cout << dynamic_cast<Float *>(result)->val() << std::endl; // 16.14
    }
	{
		Number *a = new Integer(1);

		for(auto i = 2; i < 11; i++){
			a = a->add(new Integer(i));
		}
		std::cout << dynamic_cast<Integer*>(a)->val() << std::endl;
	} // Integer addition test
	{
		Number *a = new Float(1);

		for(auto i = 2; i < 11; i++){
			a = a->add(new Float(i));
		}
		std::cout << dynamic_cast<Float*>(a)->val() << std::endl;
	}
	{
		Number *a = new Integer(3);
		Number *res = a->add(new Float(3.14))
               		->sub(new Integer(1))
                	->mul(new Integer(7))
					->sub(new Complex(11,5));
		std::cout << dynamic_cast<Complex*>(res)->to_string() << std::endl;
	} 
    // 테스트 코드 작성해보고 확인해보세요
    // 채점은 임의의 테스트코드로 진행할 예정입니다

    return 0;
}
