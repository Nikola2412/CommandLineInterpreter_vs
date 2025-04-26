#include "Writer.h"


Writer::Writer() {}
Writer::~Writer() {}

ConsoleWriter::ConsoleWriter() {}
ConsoleWriter::~ConsoleWriter() {}

void ConsoleWriter::writeLine(const string s) 
{
	//removes last new line character created by ctrl + z;
	if ('\n' == s.back()) cout << (s.substr(0,s.size() - 1)) << '\n';
	else cout << s << '\n';
}

FileWriter::FileWriter(const string filepath, bool append) : output(nullptr), path(filepath) 
{
	ifstream file(filepath);
	if (!file.good()) {
		file.close();
		cerr << "Output file does not exist" << '\n';
		return;
	}
	if (append) return;
	//to reset file content
	output = new ofstream(filepath);
	output->close();
	delete output;
}

FileWriter::~FileWriter() 
{
	delete output;
}

void FileWriter::writeLine(const string s) 
{
	if (!exist()) return;
	output = new ofstream();
	output->open(path, ios::app);//append
	(*output) << s << '\n';
	(*output).close();
}

bool FileWriter::exist() const 
{
	ifstream file(path);
	return file.good();
}
