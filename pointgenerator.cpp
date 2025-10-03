#include "pointgenerator.h"

PointGeneration::PointGeneration(Point& x0, const vector<Point>& arr) 
	: initial_point(x0), base_points(arr)
{
	if (base_points.empty()) {
		throw invalid_argument("Input array cannot be empty");
	}
	
	random_device rd;
	generator.seed(rd());
	distribution = uniform_int_distribution<>(0, base_points.size() - 1);
}

PointGeneration::~PointGeneration()
{}

Point PointGeneration::operator()()
{
	int rnd = distribution(generator);
	Point b_i = base_points[rnd];
	
	Point y;

	if (count == 0) {
		y = initial_point;
	}
	else {
		y = (initial_point + b_i) / 2.0; 
		
	}
	initial_point = y;
	count++; 
	
	return y;
}

void read_from_file(const string& file_path, int n, Point& initial_point, vector<Point>& base_points){
    ifstream is(file_path);

    if (!is.is_open()) {
		throw ios_base::failure("Couldn't open the file");
	}

    is >> n;
    is >> initial_point.x >> initial_point.y;

    Point p;
    while(is >> p.x >> p.y){
        base_points.push_back(p);
    }
    is.close();
    if (is.fail()) {
		throw ios_base::failure("An error occured");
	}
    
}

void write_in_file(const string& output_path, const vector<Point>& points) {
	ofstream f(output_path);

	if (!f.is_open()) {
		throw ios_base::failure("Couldn't open the file");
	}

	for (const auto& p : points) {
		f << p << endl;
	}

	if (f.fail()) {
		throw ios_base::failure("An error occured");
	}
	f.close();
	if (f.fail()) {
		throw ios_base::failure("An error occured");
	}


}
