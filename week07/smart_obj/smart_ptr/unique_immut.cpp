//
// Created by 김혁진 on 14/10/2019.
//

#include "unique_immut.h"

namespace ptr {
unique_immut::unique_immut() {
    _mgr = new mgr();
}

unique_immut::unique_immut(Object *obj) {
    _mgr = new mgr(obj);
}

unique_immut::unique_immut(const unique_immut &immut) {
    _mgr = new mgr(immut.get());
}

unique_immut::~unique_immut() {
    release();
}

Object* unique_immut::get() const{
    return _mgr == nullptr ? nullptr : _mgr->ptr;
}
void unique_immut::release(){
    delete _mgr;
    _mgr = nullptr;
}

unique_immut unique_immut::operator+(unique_immut &unique){
	int res = get()->get() + unique.get()->get();
	release();
	unique.release();
	Object* obj = new Object(res);
	return unique_immut(obj);
}
unique_immut unique_immut::operator-(unique_immut &unique){
	int res = get()->get() - unique.get()->get();
	release();
	unique.release();
	Object* obj = new Object(res);
	return unique_immut(obj);
}
unique_immut unique_immut::operator*(unique_immut &unique){
	int res = get()->get() * unique.get()->get();
	release();
	unique.release();
	Object* obj = new Object(res);
	return unique_immut(obj);
}
unique_immut unique_immut::operator/(unique_immut &unique){
	int res = get()->get() / unique.get()->get();
	release();
	unique.release();
	Object* obj = new Object(res);
	return unique_immut(obj);
}
Object* unique_immut::operator->(){
    return _mgr->ptr;
}

unique_immut& unique_immut::operator=(unique_immut& r){
	unique_immut rhs = r;

    if(get() != rhs.get()){
        release();
		_mgr->ptr = new Object(r->get());
		r.release();
    }
    return *this;
}
} // end of namespace ptr
