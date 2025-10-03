#pragma once 

#include <fstream>
#include <iostream>

struct Point {
	double x = 0;
	double y = 0;

	Point() = default;
	Point(double x, double y) : x(x), y(y){}

	Point operator+(const Point& other) const {
		return Point(x + other.x, y + other.y);
	}

	Point operator/(double number) const{
		return Point(x / number, y / number);
	}

	friend std::ostream& operator<<(std::ostream& os, Point const& p);

	friend std::istream& operator>>(std::istream& is, Point& p);

};


