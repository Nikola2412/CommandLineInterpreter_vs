#include "Writer.h"

Writer::Writer(){}
Writer::~Writer() {}

ConsoleWriter::ConsoleWriter() {

}

ConsoleWriter::~ConsoleWriter() {

}

void ConsoleWriter::writeLine(const string s) {
	cout << s << endl;
}

FileWriter::FileWriter(const string filepath) : m_output(nullptr) {
	std::ifstream file(filepath);
	if (!file) {
		file.close();
		cerr << "File not found" << endl;
		return;
	}
	m_output = new ofstream(filepath);
}

FileWriter::~FileWriter() {
	if (!m_output) return;
	m_output->close();
	delete m_output;
}

void FileWriter::writeLine(const string s) {
	(*m_output) << s << endl;
}

bool FileWriter::exist()
{
	return m_output != nullptr;
}
