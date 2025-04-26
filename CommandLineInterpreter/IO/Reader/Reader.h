#ifndef READER_H
#define READER_H

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

enum class ReaderType {
	Console,
	File,
	Unknown
};

class Reader {
protected: 
	Reader();
public:
	virtual ~Reader();

	virtual string getNextLine() = 0;
	virtual bool endOfRead() = 0;
	virtual ReaderType GetType() const { return ReaderType::Unknown; }
};

class ConsoleReader : public Reader {
public:
	ConsoleReader();
	~ConsoleReader() = default;

	string getNextLine();
	bool endOfRead();
	ReaderType GetType() const override { return ReaderType::Console; }
};


class FileReader : public Reader {
public:

	FileReader(const string filepath);
	~FileReader() override;

	string getNextLine();
	bool endOfRead();
	ReaderType GetType() const override { return ReaderType::File; }

private:
	ifstream* input;
	bool exist();
};

#endif