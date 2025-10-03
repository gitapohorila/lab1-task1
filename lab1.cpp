#include <lab1.h>

std::ostream& operator<<(std::ostream& os, Point const& p) {
    os << std::fixed << std::setprecision(8); 
    return os << p.x << " " << p.y;
}

std::istream& operator>>(std::istream& is, Point& p) {
    return is >> p.x >> p.y;
}

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
		initial_point = y;
	}
	
	count++; 
	
	return y;
}


void write_in_file(const string& output_path, const vector<Point>& points) {
	ofstream f(output_path);

	if (!f.is_open()) {
		throw ios_base::failure("Couldn't open the file");
	}

	for (const auto p& : points) {
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
