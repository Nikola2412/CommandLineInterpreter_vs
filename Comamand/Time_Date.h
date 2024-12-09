#ifndef Time_Date_h
#define Time_Date_h

#include "Command.h"

class  Time_Date: public Command{
public:
	virtual void execute(const string& args, bool last) = 0;
protected:
	tm getTime(const string& arg);
};


class Time : public Time_Date {
	virtual void execute(const string& args, bool last);
};

class Date : public Time_Date {
	virtual void execute(const string& args, bool last);
};

#endif



