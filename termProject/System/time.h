#pragma once
#include <chrono>

typedef std::chrono::system_clock::time_point gametime;
typedef std::chrono::duration<double> gameduration;
typedef std::chrono::milliseconds gamemilliseconds;
class Time
{
public:
	static gametime getNowTime();
	static gameduration getElapsed(gametime& prevTime);
};

