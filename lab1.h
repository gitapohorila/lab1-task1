#pragma once 

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

struct Point {
	double x = 0;
	double y = 0;

	Point operator+(const Point& other) const {
		return (x + other.x, y + other.y);
	}

	Point operator/(double number) {
		return (x / number, y / number);
	}
};

class PointGeneration {
private: 
	Point initial_point;
	const vector<Point> base_points;

public:


};
void write_in_file(const string& output_path, const vector<Points> points);