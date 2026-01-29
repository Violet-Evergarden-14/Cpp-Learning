#include <iostream>
using namespace std;

class Clock
{
private:
	int hour, minute, second;
public:
	Clock(int _hour = 0, int _minute = 0, int _second = 0);
	Clock(const Clock& now);

	void show_clock();
	void set_clock(int _hour, int _minute, int _second);
};

Clock::Clock(int _hour, int _minute, int _second):hour(_hour), minute(_minute), second(_second)   //这样效率更高
{}

Clock::Clock(const Clock& now):hour(now.hour), minute(now.minute), second(now.second)
{}

void Clock::show_clock()
{
	cout << hour << ":" << minute << ":" << second << endl;
}

void Clock::set_clock(int _hour, int _minute, int _second)
{
	hour = _hour;
	minute = _minute;
	second = _second;
}

int main()
{
	Clock my_clock;
	my_clock.show_clock();
	my_clock.set_clock(23, 59, 59);
	my_clock.show_clock();
}