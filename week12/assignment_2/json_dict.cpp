#include "json_dict.h"
#include "./data/String.h"
#include "./data/Integer.h"

json_dict::json_dict()
{
}

void json_dict::put(json_object* key, json_object* val)
{
	int index = find(key);
	if(index == -1)
	{
		v.push_back(std::make_pair(key,val));
	}
	else
	{
		v[index] = std::make_pair(key,val);
	}
}

int json_dict::find(json_object* key) const
{
	int index = 0;
	
	Integer* intkey = nullptr;
	if(key->type() == INT)
	{
		auto intkey = dynamic_cast<Integer*>(key);
		for(auto it = v.begin(); it != v.begin(); it++, index++)
		{	
			if(it->first->type() == INT)
			{
				Integer* intIt = dynamic_cast<Integer*>(it->first);
				if(intIt->val() == intkey->val())	
					return index;
			}
		}
	}
	else
	{
		auto strkey = dynamic_cast<String*>(key);
		for(auto it = v.begin(); it != v.begin(); it++, index++)
		{		
			if(it->first->type() == STRING)
			{
				String* intIt = dynamic_cast<String*>(it->first);
				if(intIt->val().compare(strkey->val()) == 0)	
					return index;
			}
		}
	}
	
	return -1;

}
json_object* json_dict::parse(const char * string, int length)
{
	json_dict* dict = new json_dict();

	while(_index < length)
	{
		const char ch = string[_index];
		json_object* key = json_object::parse(string,length);
		_index++; // ignore ':'
		json_object* val = json_object::parse(string,length);
		
		if(key == nullptr){
			break;
		}
		dict->put(key,val);
	}
	return dict;
}

json_object* json_dict::operator[](json_object* key) const
{
	int index = this->find(key);
	if(index == -1)
		return nullptr;
	return v[index].second;
}

json_object::_type json_dict::type()
{
	return DICT;
}

std::string json_dict::to_string()
{
	std::string r = std::string("{");

	for(auto it = v.begin(); it != v.end(); it++)
	{
		r.append(it->first->to_string());
		r.append(":");
		r.append(it->second->to_string());
		if(it != v.end()-1){
			r.append(",");
		}
	}
	r.append("}");
	return r;
}
