#include "Reader.h"

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

FileReader::FileReader(string filepath) : m_input(nullptr) {
	std::ifstream file(filepath);
	if (!file) {
		file.close();
		cerr << "File not found" << endl;
		return;
	}
	m_input = new ifstream(filepath);
}

FileReader::~FileReader() {
	if (!m_input) return;
	m_input->close();
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

