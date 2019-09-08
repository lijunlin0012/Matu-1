#include<iostream>

using namespace std;

class Date {
public:
	Date(int y = 1996, int m = 1, int d = 1) {
		day = d;
		month = m;
		year = y;
		if (m > 12 || m < 1)
		{
			month = 1;
		}
		if (d > days(y, m))
		{
			cout << "Invalid day!" << endl;
			day = 1;
		}
	};
	int days(int y, int m)
	{
		const int monthPerDay[] = { 0,31,0,31,30,31,30,31,31,30,31,30,31 };
		if (m != 2)
			return monthPerDay[m];
		if (y % 4 != 0 || (y % 100 == 0 && y % 400 != 0))
			return 28;
		else
			return 29;
	}
	void display() {
		cout << year << "-" << month << "-" << day << endl;
	}
private:
	int year;
	int month;
	int day;
};

ostream & operator << (ostream & out, Date dt)
{
	dt.display();
	return out;
}

int main() {
	int y, m, d;
	cin >> y >> m >> d;
	Date dt(y, m, d);
	cout << dt;
	return 0;
}