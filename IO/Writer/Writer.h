#ifndef WRITER_H
#define WRITER_H

#include "../IO.h"

class Writer{
protected:
	Writer();
public:
	virtual ~Writer();
	virtual void writeLine(const string s) = 0;
};

class ConsoleWriter : public Writer {
public:
	ConsoleWriter();
	~ConsoleWriter();
	virtual void writeLine(const string s);
};

class FileWriter : public Writer {
public:
	FileWriter(const string filepath,bool append = false);
	~FileWriter();
	virtual void writeLine(const string s);
private:
	ofstream* m_output;
	string path;
	bool exist();
};

#endif



