#pragma once 

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

struct Point {
	double x = 0;
	double y = 0;

	Point() = default;
	Point(double x, double y) : x(x), y(y){}

	Point operator+(const Point& other) const {
		return (x + other.x, y + other.y);
	}

	Point operator/(double number) const{
		return (x / number, y / number);
	}
};

std::ostream& operator<<(std::ostream& os, Point const& p) {
	return os << p.x << " " << p.y;
}

std::istream& operator>>(std::istream& is, Point& p) {
	return is >> p.x >> p.y;
}

class PointGeneration {
private: 
	Point initial_point;
	const vector<Point> base_points;

	mt19937 generator;
	uniform_int_distribution<> distribution;
	int count = 0;

public:
	PointGeneration(Point& x0, const vector<Point>& arr);
	~PointGeneration();
	Point operator()();

};
void write_in_file(const string& output_path, const vector<Point> points);
