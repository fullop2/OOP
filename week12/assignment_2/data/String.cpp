#include "String.h"

#include <iostream>

String::String(const std::string& str)
{
	set_val(str);
}

std::string String::val()
{
	return _val;
}

void String::set_val(const std::string& str)
{
	_val = str;
}

json_object* String::parse(const char * string, int length, char base)
{
	int startIndex = _index;
	while(base != string[_index]){_index++;}
	int endIndex = _index++;

	std::string r = std::string(string).substr(startIndex,endIndex-startIndex);
 	return new String(r);
}

json_object::_type String::type()
{
	return STRING;
}

std::string String::to_string()
{
	std::string r = std::string("'");
	r.append(_val);
	r.append("'");
	return r;
}
