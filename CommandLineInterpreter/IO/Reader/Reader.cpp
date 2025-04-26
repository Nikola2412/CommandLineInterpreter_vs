#include "Reader.h"


Reader::Reader() {}
Reader::~Reader() {}

ConsoleReader::ConsoleReader() {};
ConsoleReader::~ConsoleReader() {};

string ConsoleReader::getNextLine() 
{
	string str;
	if (getline(cin, str))
		return str;
	return string();
}


bool ConsoleReader::endOfRead()
{
	return cin.eof();
}

FileReader::FileReader(const string filepath) : input(nullptr) 
{
	ifstream file(filepath);
	if (!file) {
		file.close();
		//cerr << "Input file does not exist" << '\n';
		return;
	}
	input = new ifstream(filepath);
}

FileReader::~FileReader() 
{
	delete input;
}

string FileReader::getNextLine() 
{
	string line;
	getline(*input, line);
	return line;
}

bool FileReader::endOfRead() 
{
	if (!exist()) return true;
	return input->eof();
}

bool FileReader::exist() 
{
	return input != nullptr;
}

