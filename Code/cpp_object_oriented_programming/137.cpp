#include<iostream>
#include<cmath>
using namespace std;

struct Ctriangle {
	int a;
	int b;
	int c;
	Ctriangle(int _a, int _b, int _c) :a(_a), b(_b), c(_c) {};
	void display()
	{
		cout << "Ctriangle:a=" << a << ",b=" << b << ",c=" << c << endl;
	}
	int GetPerimeter()
	{
		return a + b + c;
	}
	int GetArea()
	{
		double p = (a + b + c)/ 2;
		return sqrt(p*(p - a)*(p - b)*(p - c));
	}
};

int main() {
	double a, b, c;
	cin >> a >> b >> c;
	Ctriangle T(a, b, c);
	T.display();
	cout << "Perimeter:" << T.GetPerimeter() << endl;
	cout << "Area:" << T.GetArea() << endl;
	return 0;
}
