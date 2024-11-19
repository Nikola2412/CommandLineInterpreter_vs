#include "Counter.h"


int WordCounter::count(const string& input) {
	int x = 0;
	istringstream stream(input);
	string token;
	while (stream >> token) {
		x++;
	}
	return x;
}

int CharCounter::count(const string& input) {
	return input.size();
}

int LineCounter::count(const string& input) {
	return 0;
}