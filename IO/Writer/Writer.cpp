#include "Writer.h"

Writer::Writer(){}
Writer::~Writer() {}

ConsoleWriter::ConsoleWriter() {}

ConsoleWriter::~ConsoleWriter() {}

void ConsoleWriter::writeLine(const string s) {
	cout << s << endl;
}

FileWriter::FileWriter(const string filepath) : m_output(nullptr), path(filepath) {
	std::ifstream file(filepath);
	if (!file) {
		file.close();
		cerr << "File not found" << endl;
		return;
	}
	m_output = new ofstream(filepath);
	m_output->close();
	delete m_output;
}

FileWriter::~FileWriter() {
	m_output->close();
	delete m_output;
}

void FileWriter::writeLine(const string s) {
	m_output = new ofstream();
	m_output->open(path, ios::app);
	(*m_output) << s << endl;
	(*m_output).close();
}

bool FileWriter::exist(){
	return m_output != nullptr;
}
