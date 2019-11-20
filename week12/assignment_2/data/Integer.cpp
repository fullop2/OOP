#include "Integer.h"

Integer::Integer(int value)
{
	_val = value;
}

int Integer::val()
{
	return _val;
}

void Integer::set_val(const int& value)
{
	_val = value;
}

json_object* Integer::parse(const char * string, int length)
{
	int startIndex = _index;
	while('0' <= string[_index] && string[_index] <= '9'){_index++;}
	std::string str = std::string(string);
	return new Integer(std::stoi(str.substr(startIndex, _index-startIndex)));
}

json_object::_type Integer::type()
{
	return INT;
}

std::string Integer::to_string()
{
	return std::to_string(_val);
}
