#ifndef Touch_h
#define Touch_h

#include "Command.h"

class Touch : public Command{
public:
	void execute(const string& parms, bool last);
};

#endif