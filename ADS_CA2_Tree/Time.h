#pragma once
#include <iomanip>
#include <ostream>
#include <string>

class Time
{
	int hour;
	int minute;

public:
	Time(int hour, int minute);
	Time();
	Time(const std::string& timeAsString);

	int getHour() const;
	int getMinute() const;

	void setHour(int hour);
	void setMinute(int minute);

	bool operator==(const Time& time) const;

	friend std::ostream& operator<<(std::ostream& out, const Time& time);
};