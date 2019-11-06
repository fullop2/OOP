//
// Created by 김혁진 on 2019/10/28.
//

#include "weak_pointer.h"

#include <iostream>

namespace ptr {
ptr::weak_pointer::weak_pointer() {
    ptr = nullptr;
}

weak_pointer::weak_pointer(shared_ref &shared) {
        
    student* p = shared.get();
    
    if(ptr_map[p])
    {
	    ptr = p;
    }
    else{
	    ptr = nullptr;
    }
}

weak_pointer::weak_pointer(const weak_pointer &weak) {
    student*p = weak.ptr;

    ptr = ptr_map[p] != nullptr ? p : nullptr;
}

// ptr_map에 key ptr의 value가 nullptr가 아니라면 0, 맞다면 1을 리턴
int weak_pointer::is_expired() {
	return ptr_map[ptr] == nullptr ? 1 : 0;	
}

student *weak_pointer::get() {
	return ptr_map[ptr] == nullptr ? nullptr : ptr;
}

}
