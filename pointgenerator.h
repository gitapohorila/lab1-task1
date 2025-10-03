#pragma once 

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <random>

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

void read_from_file(const string& file_path, int n, Point& initial_point, vector<Point>& base_points);

void write_in_file(const string& output_path, const vector<Point> points);