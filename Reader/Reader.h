#ifndef READER_H
#define READER_H

#include <fstream>
#include <string>
using namespace std;

class Reader {
public:

	Reader();
	virtual ~Reader();

	virtual string getNextLine() = 0;

	virtual bool endOfRead() = 0;
};

class CommandReader : public Reader {
public:
	CommandReader();
	~CommandReader();

	virtual string getNextLine();
	virtual bool endOfRead();
private:

};


class FileReader : public Reader {
public:

	FileReader(string filepath);
	~FileReader();

	virtual string getNextLine();
	virtual bool endOfRead();

private:
	ifstream* m_input;
};

#endif