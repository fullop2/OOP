#ifndef __VEHICLE__
#define __VEHICLE__

class vehicle
{
	private:
		bool has_name;
		int wheel_number;
		int max_speed;

	public:
		vehicle();
		explicit vehicle(int,int);
		explicit vehicle(int,int,bool);
		
		// getter
		int get_wheel_number() const;
		int get_max_speed() const;
		bool get_has_name() const;
		virtual const char* get_class_name() const;
		// setter
		void set_wheel_number(int);
		void set_max_speed(int);
		void set_has_name(bool);
};

#endif // __VEHICLE__
