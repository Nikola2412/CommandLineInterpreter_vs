#ifndef TIME_DATE_H
#define TIME_DATE_H

#include "Command.h"

class  Time_Date : public Command {
public:
	virtual void Execute(const string& params, bool last) = 0;
	//virtual void executeBatch(const string& params, bool last, Reader* r = nullptr) = 0;
protected:
	tm getTime(const string& arg);
	char buffer[256] = { 0 };
};


class Time : public Time_Date {
	void Execute(const string& params, bool last);
	//void executeBatch(const string& params, bool last, Reader* r = nullptr);
};

class Date : public Time_Date {
	void Execute(const string& params, bool last);
	//void executeBatch(const string& params, bool last, Reader* r = nullptr);
};

#endif



