#ifndef TIME_DATE_H
#define TIME_DATE_H

#include "Command.h"

#include <ctime>


class  TimeDate : public Command {
public:
	virtual void Execute(const string& params) = 0;
	virtual void Helper() = 0;

protected:
	tm getTime(const string& arg);

	char buffer[256] = { 0 };
};


class Time : public TimeDate {
public:
	void Execute(const string& params);
	void Helper();
};

class Date : public TimeDate {
public:
	void Execute(const string& params);
	void Helper();
};

#endif



