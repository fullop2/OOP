#include "Input.h"
#include "sys.h"

int Input::key = 0;

int Input::getKeyDown()
{
	return key;
}

void Input::update()
{
	if (_kbhit())
	{
		key = _getch();
	}
	else
	{
		key = 0;
	}
}