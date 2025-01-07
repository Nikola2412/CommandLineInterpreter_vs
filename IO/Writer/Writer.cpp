#include "Writer.h"


Writer::Writer() {}

Writer::~Writer() {}

ConsoleWriter::ConsoleWriter() {}

ConsoleWriter::~ConsoleWriter() {}

void ConsoleWriter::writeLine(const string s) {
	//removes last new line character created by ctrl + z;
	if ('\n' == s.back()) cout << (s.substr(0,s.size() - 1)) << endl;
	else cout << s << endl;
}

FileWriter::FileWriter(const string filepath,bool append) : m_output(nullptr), path(filepath) {
	ifstream file(filepath);
	if (!file.good()) {
		file.close();
		cerr << "Output file does not exist" << endl;
		return;
	}
	if (append) return;
	//to reset file content
	m_output = new ofstream(filepath);
	m_output->close();
	delete m_output;
}

FileWriter::~FileWriter() {
	m_output->close();
	delete m_output;
}

void FileWriter::writeLine(const string s) {
	if (!exist()) return;
	m_output = new ofstream();
	m_output->open(path, ios::app);//append
	(*m_output) << s << endl;
	(*m_output).close();
}

bool FileWriter::exist() const {
	ifstream file(path);
	return file.good();
}
