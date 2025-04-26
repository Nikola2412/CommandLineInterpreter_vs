#ifndef WRITER_H
#define WRITER_H

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

enum class WriterType {
	Console,
	File,
	Unknown
};

class Writer{
	
public:
	Writer();
	virtual ~Writer() = 0;
	virtual void writeLine(const string s) = 0;
	virtual WriterType GetType() const { return WriterType::Unknown; }
};

class ConsoleWriter : public Writer {
public:
	ConsoleWriter();
	~ConsoleWriter();
	void writeLine(const string s);
	WriterType GetType() const override { return WriterType::Console; }
};

class FileWriter : public Writer {
public:
	FileWriter(const string filepath, bool append = false);
	~FileWriter();
	void writeLine(const string s);
	WriterType GetType() const override { return WriterType::File; }
private:
	ofstream* output;
	string path;
	bool exist() const;
};

#endif



