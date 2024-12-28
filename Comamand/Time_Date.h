#ifndef Time_Date_h
#define Time_Date_h

#include "Command.h"

class  Time_Date: public Command{
public:
	virtual void execute(const string& args, bool last) = 0;
	void executeBatch(Reader* r = nullptr, Writer* w = nullptr) = 0;
protected:
	tm getTime(const string& arg);
	char buffer[256];
};


class Time : public Time_Date {
	void execute(const string& args, bool last);
	void executeBatch(Reader* r = nullptr, Writer* w = nullptr);
};

class Date : public Time_Date {
	void execute(const string& args, bool last);
	void executeBatch(Reader* r = nullptr, Writer* w = nullptr);
};

#endif



