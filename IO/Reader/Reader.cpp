#include "Reader.h"

using namespace std;

Reader::Reader() {}
Reader::~Reader() {}

ConsoleReader::ConsoleReader() {};
ConsoleReader::~ConsoleReader() {};

string ConsoleReader::getNextLine(){
	string str;
	getline(cin, str);
	return str;
}
bool ConsoleReader::endOfRead(){
	return cin.eof();
}

FileReader::FileReader(string filepath) : m_input(nullptr) {
	std::ifstream file(filepath);
	if (!file) {
		file.close();
		//cerr << "Input file does not exist" << endl;
		return;
	}
	m_input = new ifstream(filepath);
}

FileReader::~FileReader() {
	delete m_input;
}

string FileReader::getNextLine() {
	string line;
	getline(*m_input, line);
	return line;
}

bool FileReader::endOfRead() {
	if (!exist()) return true;
	return m_input->eof();
}

bool FileReader::exist() {
	return m_input != nullptr;
}

