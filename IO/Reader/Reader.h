#ifndef READER_H
#define READER_H

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class Reader {
protected: 
	Reader();
public:
	virtual ~Reader();
	virtual string getNextLine() = 0;
	virtual bool endOfRead() = 0;
};

class ConsoleReader : public Reader {
public:
	ConsoleReader();
	~ConsoleReader();

	virtual string getNextLine();
	virtual bool endOfRead();
};


class FileReader : public Reader {
public:

	FileReader(const string filepath);
	~FileReader();

	virtual string getNextLine();
	virtual bool endOfRead();

private:
	ifstream* m_input;
	bool exist();
};

#endif