#include "time.h"

gametime Time::getNowTime()
{
	return std::chrono::system_clock::now();
}

gameduration Time::getElapsed(gametime& beforetime)
{
	auto nowTime = getNowTime();
	gameduration dur = nowTime - beforetime;
	return dur;
}
