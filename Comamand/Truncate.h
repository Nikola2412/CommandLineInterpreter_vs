#ifndef Truncate_h
#define Truncate_h

#include "Command.h"
class Truncate : public Command{
	virtual void execute(const string& args);
};
#endif
