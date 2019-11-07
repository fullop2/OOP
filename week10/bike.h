#ifndef __BIKE__
#define __BIKE__

#include "vehicle.h"

class bike
:public vehicle
{
	private:
		char* bike_name;
		int bike_number;
	public:
		bike();
		bike(int,int);
		bike(int,int,char*,int);
		bike(int, int, char*, int, bool);

		int get_bike_number() const;
		char* get_bike_name() const;
		const char* get_class_name() const override;

		void set_bike_name(char*);
		void set_bike_number(int);
};

#endif // __BIKE__
