#include "vehicle.h"

vehicle::vehicle(){
	set_has_name(false);
}
vehicle::vehicle(int wheel_number, int max_speed){
	set_wheel_number(wheel_number);
	set_max_speed(max_speed);
	//set_has_name(true);
}
vehicle::vehicle(int wheel_number, int max_speed, bool has_name){
	set_wheel_number(wheel_number);
	set_max_speed(max_speed);
	set_has_name(has_name);
}

int vehicle::get_wheel_number() const{
	return wheel_number;
}
int vehicle::get_max_speed() const{
	return max_speed;
}
bool vehicle::get_has_name() const{
	return has_name;
}
const char* vehicle::get_class_name() const{
	return "vehicle";
}

void vehicle::set_wheel_number(int wheel_number){
	this->wheel_number = wheel_number;
}
void vehicle::set_max_speed(int max_speed){
	this->max_speed = max_speed;
}
void vehicle::set_has_name(bool has_name){
	this->has_name = has_name;
}



