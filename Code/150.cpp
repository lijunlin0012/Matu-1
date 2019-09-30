#include<cmath>
#include<iostream>
#include"CPoint.h"

const float PI = 3.14;
//mdΪʲô PI ֻȡ 3.14 ���滹û��˵��

Rectangle::Rectangle(float xx, float yy, float w, float h) :
	Point(xx, yy)
{
	width = w;
	high = h;
}

Circle::Circle(float xx, float yy, float r) :
	Point(xx, yy)
{
	radius = r;
}

float Rectangle::Area()
{
	return width * high;
}

float Circle::Area()
{
	return PI * radius * radius;
}

//int main()
//{
//	Rectangle rect(1, 2, 3, 4);
//	std::cout << rect.Area();     //12
//	Circle c(5, 6, 7);
//	std::cout << c.Area();      //153.86
//}