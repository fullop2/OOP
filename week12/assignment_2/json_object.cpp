#include "json_object.h"
#include "json_dict.h"
#include "json_list.h"
#include "./data/Integer.h"
#include "./data/String.h"


int json_object::_index = 0;

json_object* json_object::parse(const char * string, int length)
{
	while(_index < length){
		const char ch = string[_index]; // get now char and go next
		_index++;
		if('\0' == ch || '}' == ch || ']' == ch){ // end of json,dict,list
			return nullptr;
		}
		else if(',' == ch){ // continue traverse (if dict or list)
			continue;
		}
		else if(ch == '{'){ // start of dict
			return json_dict::parse(string,length);			
		}
		else if(ch == '['){ // start of list
			return json_list::parse(string,length);
		}
		else if('0' <= ch && ch <= '9'){ // start of number
			return Integer::parse(string,length);
		}
		else if('\'' == ch || '\"' == ch) { // start of string
			return String::parse(string,length,ch);
		}
		else { // error (not reachable)
			return nullptr;
		}
	}
}

json_object* json_object::parse(const std::string& str)
{
	json_object::_index = 0;
	return parse(str.c_str(),str.length());
}
