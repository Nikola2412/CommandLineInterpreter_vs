#ifndef Time_Date_h
#define Time_Date_h

#include "Command.h"

class  Time_Date: public Command{
public:
	virtual void execute(const std::string& args, std::string& input) = 0;
protected:
	virtual tm getTime();
};


class Time : public Time_Date {
	virtual void execute(const std::string& args, std::string& input);
};

class Date : public Time_Date {
	virtual void execute(const std::string& args, std::string& input);
};

#endif



