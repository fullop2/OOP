#include "json_list.h"

json_list::json_list()
{
}

json_object* json_list::parse(const char * string, int length)
{
	json_list* list = new json_list();
	_index++; // '['
	while(_index < length && string[_index] != ']')
	{
		json_object* object = json_object::parse(string,length);
		list->v.push_back(object);
		if(string[_index] == ']') {break;}
		_index++; // ',' or ']'
	}
	_index++;
	return list;
}

json_object* json_list::operator[](int key) const
{
	return v[key];
}

json_object::_type json_list::type()
{
	return LIST;
}

std::string json_list::to_string()
{
	std::string r = std::string("[");

	for(auto it = v.begin(); it != v.end(); it++)
	{
		r.append((*it)->to_string());

		if(it != v.end()-1)
		{
			r.append(", ");
		}
	}
	r.append("]");

	return r;
}

