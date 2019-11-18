#include "Clock.h"
Clock::Clock(int h, int m, int s)
{
	if (h < 0 || h >= 24)
		h = 0;
	hour = h;
	if (m < 0 || m >= 60)
		m = 0;
	minute = m;
	if (s < 0 || s >= 60)
		s = 0;
	second = s;
}
void Clock::SetAlarm(int h, int m, int s) 
{
	if (h < 0 || m < 0 || s < 0)
	{
		Ahour = -1;
		return;
	}
	if (h < 0 || h >= 24)
		h = 0;
	Ahour = h;
	if (m < 0 || m >= 60)
		m = 0;
	Aminute = m;
	if (s < 0 || s >= 60)
		s = 0;
	Asecond = s;
}

void Clock::run() 
{
	second++;
	if (second == 60)
	{
		second = 0;
		minute++;
		if (minute == 60)
		{
			minute = 0;
			hour++;
			if (hour == 24)
				hour = 0;
		}
	}
	if (hour == Ahour && Aminute == minute && Asecond == second)
		std::cout << "Plink!plink!plink!..." << endl;
}


int main() {
	Clock c(23, 59, 59);
	c.ShowTime();
	c.SetAlarm(0, 0, 0);
	c.run();
}
