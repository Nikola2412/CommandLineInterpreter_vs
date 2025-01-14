#ifndef TIME_DATE_H
#define TIME_DATE_H

#include "Command.h"

#include <ctime>


class  TimeDate : public Command {
public:
	virtual void Execute(const string& params, bool last) = 0;
protected:
	tm getTime(const string& arg);
	char buffer[256] = { 0 };
};


class Time : public TimeDate {
	void Execute(const string& params, bool last);
};

class Date : public TimeDate {
	void Execute(const string& params, bool last);
};

#endif



