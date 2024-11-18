#include "Reader.h"
#include <iostream>
using namespace std;

Reader::Reader() {}

Reader::~Reader() {}


CommandReader::CommandReader() {};
CommandReader::~CommandReader() {};

string CommandReader::getNextLine(){
	string str;
	getline(cin, str);
	return str;
}
bool CommandReader::endOfRead(){
	return cin.eof();
}

FileReader::FileReader(string filepath) {
	m_input = new ifstream(filepath);
}

FileReader::~FileReader() { 
	m_input->close();
	delete m_input;
}


string FileReader::getNextLine() {
	string line;
	getline(*m_input, line);
	return line;
}

bool FileReader::endOfRead() {
	return m_input->eof();
}

