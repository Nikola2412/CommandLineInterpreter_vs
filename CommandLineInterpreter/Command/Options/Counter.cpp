#include "Counter.h"

//Counter::Counter() {}

size_t WordCounter::count(const string& input) 
{
	size_t x = 0;
	stringstream stream(input);
	string token;
	while (stream >> token) x++;
	return x;
}

size_t CharCounter::count(const string& input) 
{
	size_t x = 0;
	for (char c : input)
		if (c != '\n')
			x++;
	return x;
}

size_t LineCounter::count(const string& input) 
{
	size_t x = 1;
	for (char c : input)
		if (c == '\n')
			x++;
	return x;
}
