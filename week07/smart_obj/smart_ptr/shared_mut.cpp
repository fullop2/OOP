//
// Created by 김혁진 on 14/10/2019.
//

#include "shared_mut.h"

namespace ptr {
shared_mut::shared_mut() {
    _mgr = new mgr();
}

shared_mut::shared_mut(Object* _obj) {
    _mgr = new mgr(_obj);
}
shared_mut::shared_mut(const shared_mut& shared) {
	release();
	_mgr = shared._mgr;
	increase();
}
shared_mut::~shared_mut() {
    release();
}

void shared_mut::increase()
{
	if(_mgr != nullptr)
		_mgr->count++;
}

Object* shared_mut::get() const{
    return _mgr == nullptr ? nullptr : _mgr->ptr;
}
void shared_mut::release()
{
    if(_mgr != nullptr){
		if (--_mgr->count == 0)
		{
			delete _mgr;
		}
		_mgr = nullptr;
    }
}

int shared_mut::count()
{
    return _mgr == nullptr ?  0 : _mgr->count;
}

shared_mut shared_mut::operator+(const shared_mut &shared)
{
	Object* obj = new Object(get()->get() + shared.get()->get());
    return shared_mut(obj);
}
shared_mut shared_mut::operator-(const shared_mut &shared)
{
	Object* obj = new Object(get()->get() - shared.get()->get());
	return shared_mut(obj);
}
shared_mut shared_mut::operator*(const shared_mut &shared)
{
	Object* obj = new Object(get()->get() * shared.get()->get());
	return shared_mut(obj);
}
shared_mut shared_mut::operator/(const shared_mut &shared)
{
	Object* obj = new Object(get()->get() / shared.get()->get());
	return shared_mut(obj);
}
Object* shared_mut::operator->(){
	return _mgr == nullptr ? nullptr : _mgr->ptr;
}
shared_mut& shared_mut::operator=(const shared_mut &r)
{
	if (_mgr != r._mgr) {
		release();
		_mgr = r._mgr;
		increase();
	}

    return *this;
}

} // end of namespace ptr
