#include <lab1.h>

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