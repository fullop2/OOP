#ifndef __CAR__
#define __CAR__

#include "vehicle.h"

class car 
: public vehicle
{
	private:
		char* car_name;
	public:
		car();
		explicit car(int,int);
		explicit car(int,int,char*);
		explicit car(int,int,char*,bool);

		//getter
		char* get_car_name() const;
		const char* get_class_name() const override;
		
		// setter
		void set_car_name(char*);
};

#endif // __CAR__
