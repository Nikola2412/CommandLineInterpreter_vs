#ifndef WRITER_H
#define WRITER_H

#include <fstream>
#include <string>
#include <iostream>

using namespace std;


class Writer{
public:
	Writer();
	virtual ~Writer() = 0;
	virtual void writeLine(const string s) = 0;
};

class ConsoleWriter : public Writer {
public:
	ConsoleWriter();
	~ConsoleWriter();
	void writeLine(const string s);
};

class FileWriter : public Writer {
public:
	FileWriter(const string filepath,bool append = false);
	~FileWriter();
	void writeLine(const string s);

private:
	ofstream* m_output;
	string path;
	bool exist() const;
};

#endif



