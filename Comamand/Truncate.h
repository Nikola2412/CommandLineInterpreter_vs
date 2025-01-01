#ifndef Truncate_h
#define Truncate_h

#include "Command.h"

class Truncate : public Command{
	void execute(const string& params, bool last);
};
#endif
