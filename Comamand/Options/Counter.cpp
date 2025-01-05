#include "Counter.h"

#include <fstream>
#include <sstream>
#include <string>


int WordCounter::count(const string& input) {
	int x = 0;
	istringstream stream(input);
	string token;
	while (stream >> token) ++x;
	return x;
}

int CharCounter::count(const string& input) {
	size_t x = 0;
	for (char c : input)
		if (c != '\n')
			++x;
	return x;
}

int LineCounter::count(const string& input) {
	return 0;
}