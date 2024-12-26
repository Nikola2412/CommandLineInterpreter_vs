#ifndef Touch_h
#define Touch_h

#include "Command.h"

class Touch : public Command{
public:
	virtual void execute(const string& args, bool last);
};

#endif