// g++ compiler

#include "point.h"
#include "pointgenerator.h"

int main() {
    try {
    std::string input_file = "input.txt";
	std::string output_file = "output.txt";
    
	int n;
	Point initial_point;
	std::vector<Point> base_points;
	read_from_file(input_file, n, initial_point, base_points);

	PointGeneration generator(initial_point, base_points);
	std::vector<Point> output_points;
	for(int i = 0; i < n; i++) {
		output_points.push_back(generator());
	}

	write_in_file(output_file, output_points);

} catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
